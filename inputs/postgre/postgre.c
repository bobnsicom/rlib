/*
 *  Copyright (C) 2003 SICOM Systems, INC.
 *
 *  Authors: Bob Doan <bdoan@sicompos.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libpq-fe.h"
 
#include "ralloc.h"
#include "rlib_input.h"

#define INPUT_PRIVATE(input) (((struct _private *)input->private))

struct rlib_postgre_results {
	PGresult *result;
	char *name;
	int row;
	int tot_rows;
	int tot_fields;
	int isdone;
	int *fields;
};

struct _private {
	PGconn *conn;
};

void * rlib_postgre_connect(void * input_ptr, char *conninfo) {
	struct input_filter *input = input_ptr;
	PGconn *conn;

	conn = PQconnectdb(conninfo);

	if (PQstatus(conn) != CONNECTION_OK) {
		PQfinish(conn);
	}

	INPUT_PRIVATE(input)->conn = conn;	
	return conn;
}

static int rlib_postgre_input_close(void *input_ptr) {
	struct input_filter *input = input_ptr;
	PQfinish(INPUT_PRIVATE(input)->conn);
	INPUT_PRIVATE(input)->conn = NULL;
	return 0;
}

static PGresult * rlib_postgre_query(PGconn *conn, char *query) {
	PGresult *result = NULL;
	int rtn;

	result = PQexec(conn, query);
	if (PQresultStatus(result) != PGRES_TUPLES_OK) {
		PQclear(result);
		PQfinish(conn);
	}
	return result;
}

static int rlib_postgre_first(void *input_ptr, void *result_ptr) {
	struct rlib_postgre_results *result = result_ptr;
	result->row = 0;
	result->isdone = FALSE;
	return TRUE;
}

static int rlib_postgre_next(void *input_ptr, void *result_ptr) {
	struct rlib_postgre_results *result = result_ptr;
	if(result->row+1 < result->tot_rows) {
		result->row++;
		result->isdone = FALSE;
		return TRUE;
	}
	result->isdone = TRUE;
	return FALSE;
}

static int rlib_postgre_isdone(void *input_ptr, void *result_ptr) {
	struct rlib_postgre_results *result = result_ptr;
	return result->isdone;
}

static int rlib_postgre_previous(void *input_ptr, void *result_ptr) {
	struct rlib_postgre_results *result = result_ptr;
	if(result->row-1 > 0) {
		result->row--;
		result->isdone = FALSE;
		return TRUE;
	}
	result->isdone = TRUE;
	return FALSE;
}

static int rlib_postgre_last(void *input_ptr, void *result_ptr) {
	struct rlib_postgre_results *result = result_ptr;
	result->row = result->tot_rows-1;
	result->isdone = FALSE;
	return TRUE;
}

static char * rlib_postgre_get_field_value_as_string(void *input_ptr, void *result_ptr, void *field_ptr) {
	struct rlib_postgre_results *results = result_ptr;
	long field = (long)field_ptr;
	field -= 1;
	return PQgetvalue(results->result, results->row, field);
}

static void * rlib_postgre_resolve_field_pointer(void *input_ptr, void *result_ptr, char *name) {
	struct rlib_postgre_results *results = result_ptr;
	int i=0;
	for (i = 0; i < results->tot_fields; i++)
		if(!strcmp(PQfname(results->result, i), name)) {
			return (void *)results->fields[i];
		}
	return NULL;
}

void * postgre_new_result_from_query(void *input_ptr, char *query) {
	struct input_filter *input = input_ptr;
	struct rlib_postgre_results *results;
	PGresult *result;
	unsigned int count,i;
	result = rlib_postgre_query(INPUT_PRIVATE(input)->conn, query);
	if(result == NULL)
		return NULL;
	else {
		results = rmalloc(sizeof(struct rlib_postgre_results));
		results->result = result;
	}
	count = PQnfields(result);
	results->fields = rmalloc(sizeof(int) * count);
	for(i=0;i<count;i++) {
		results->fields[i] = i+1;
	}
	results->tot_fields = count;
	results->tot_rows = PQntuples(result);
	return results;
}

static void rlib_postgre_rlib_free_result(void *input_ptr, void *result_ptr) {
	struct rlib_postgre_results *results = result_ptr;
	PQclear(results->result);
	rfree(results->fields);
	rfree(results);
}

static int rlib_postgre_free_input_filter(void *input_ptr) {
	struct input_filter *input = input_ptr;
	rfree(input->private);
	rfree(input);
	return 0;
}

void * rlib_postgre_new_input_filter() {
	struct input_filter *input;
	
	input = rmalloc(sizeof(struct input_filter));
	input->private = rmalloc(sizeof(struct _private));
	bzero(input->private, sizeof(struct _private));
	input->input_close = rlib_postgre_input_close;
	input->first = rlib_postgre_first;
	input->next = rlib_postgre_next;
	input->previous = rlib_postgre_previous;
	input->last = rlib_postgre_last;
	input->isdone = rlib_postgre_isdone;
	input->new_result_from_query = postgre_new_result_from_query;
	input->get_field_value_as_string = rlib_postgre_get_field_value_as_string;

	input->resolve_field_pointer = rlib_postgre_resolve_field_pointer;

	input->free = rlib_postgre_free_input_filter;
	input->free_result = rlib_postgre_rlib_free_result;
	return input;
}