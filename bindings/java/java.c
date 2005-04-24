/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.21
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */


#if defined(__GNUC__)
    typedef long long __int64; /*For gcc on Windows */
#endif
#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" } };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  (*jenv)->ExceptionClear(jenv);
  excep = (*jenv)->FindClass(jenv, except_ptr->java_exception);
  if (excep)
    (*jenv)->ThrowNew(jenv, excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


#include <rlib.h>
 

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_librlibJNI_rlib_1init(JNIEnv *jenv, jclass jcls) {
    jlong jresult = 0 ;
    rlib *result;
    
    (void)jenv;
    (void)jcls;
    result = (rlib *)rlib_init();
    
    *(rlib **)&jresult = result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1add_1datasource_1mysql(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3, jstring jarg4, jstring jarg5, jstring jarg6) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    char *arg3 ;
    char *arg4 ;
    char *arg5 ;
    char *arg6 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    {
        arg3 = 0;
        if (jarg3) {
            arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
            if (!arg3) return 0;
        }
    }
    {
        arg4 = 0;
        if (jarg4) {
            arg4 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg4, 0);
            if (!arg4) return 0;
        }
    }
    {
        arg5 = 0;
        if (jarg5) {
            arg5 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg5, 0);
            if (!arg5) return 0;
        }
    }
    {
        arg6 = 0;
        if (jarg6) {
            arg6 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg6, 0);
            if (!arg6) return 0;
        }
    }
    result = (int)rlib_add_datasource_mysql(arg1,arg2,arg3,arg4,arg5,arg6);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    {
        if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, arg3); 
    }
    {
        if (arg4) (*jenv)->ReleaseStringUTFChars(jenv, jarg4, arg4); 
    }
    {
        if (arg5) (*jenv)->ReleaseStringUTFChars(jenv, jarg5, arg5); 
    }
    {
        if (arg6) (*jenv)->ReleaseStringUTFChars(jenv, jarg6, arg6); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1add_1datasource_1postgre(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    char *arg3 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    {
        arg3 = 0;
        if (jarg3) {
            arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
            if (!arg3) return 0;
        }
    }
    result = (int)rlib_add_datasource_postgre(arg1,arg2,arg3);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    {
        if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, arg3); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1add_1datasource_1odbc(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3, jstring jarg4, jstring jarg5) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    char *arg3 ;
    char *arg4 ;
    char *arg5 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    {
        arg3 = 0;
        if (jarg3) {
            arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
            if (!arg3) return 0;
        }
    }
    {
        arg4 = 0;
        if (jarg4) {
            arg4 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg4, 0);
            if (!arg4) return 0;
        }
    }
    {
        arg5 = 0;
        if (jarg5) {
            arg5 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg5, 0);
            if (!arg5) return 0;
        }
    }
    result = (int)rlib_add_datasource_odbc(arg1,arg2,arg3,arg4,arg5);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    {
        if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, arg3); 
    }
    {
        if (arg4) (*jenv)->ReleaseStringUTFChars(jenv, jarg4, arg4); 
    }
    {
        if (arg5) (*jenv)->ReleaseStringUTFChars(jenv, jarg5, arg5); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1add_1query_1as(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3, jstring jarg4) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    char *arg3 ;
    char *arg4 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    {
        arg3 = 0;
        if (jarg3) {
            arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
            if (!arg3) return 0;
        }
    }
    {
        arg4 = 0;
        if (jarg4) {
            arg4 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg4, 0);
            if (!arg4) return 0;
        }
    }
    result = (int)rlib_add_query_as(arg1,arg2,arg3,arg4);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    {
        if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, arg3); 
    }
    {
        if (arg4) (*jenv)->ReleaseStringUTFChars(jenv, jarg4, arg4); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1add_1report(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    result = (int)rlib_add_report(arg1,arg2);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1add_1report_1from_1buffer(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    result = (int)rlib_add_report_from_buffer(arg1,arg2);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1execute(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    result = (int)rlib_execute(arg1);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jstring JNICALL Java_librlibJNI_rlib_1get_1content_1type_1as_1text(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jstring jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    result = (char *)rlib_get_content_type_as_text(arg1);
    
    {
        if(result) jresult = (*jenv)->NewStringUTF(jenv, result); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1spool(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    result = (int)rlib_spool(arg1);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1set_1output_1format(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    int arg2 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    arg2 = (int)jarg2; 
    result = (int)rlib_set_output_format(arg1,arg2);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1add_1resultset_1follower_1n_1to_11(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3, jstring jarg4, jstring jarg5) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    char *arg3 ;
    char *arg4 ;
    char *arg5 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    {
        arg3 = 0;
        if (jarg3) {
            arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
            if (!arg3) return 0;
        }
    }
    {
        arg4 = 0;
        if (jarg4) {
            arg4 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg4, 0);
            if (!arg4) return 0;
        }
    }
    {
        arg5 = 0;
        if (jarg5) {
            arg5 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg5, 0);
            if (!arg5) return 0;
        }
    }
    result = (int)rlib_add_resultset_follower_n_to_1(arg1,arg2,arg3,arg4,arg5);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    {
        if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, arg3); 
    }
    {
        if (arg4) (*jenv)->ReleaseStringUTFChars(jenv, jarg4, arg4); 
    }
    {
        if (arg5) (*jenv)->ReleaseStringUTFChars(jenv, jarg5, arg5); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1add_1resultset_1follower(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    char *arg3 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    {
        arg3 = 0;
        if (jarg3) {
            arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
            if (!arg3) return 0;
        }
    }
    result = (int)rlib_add_resultset_follower(arg1,arg2,arg3);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    {
        if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, arg3); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1set_1output_1format_1from_1text(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    result = (int)rlib_set_output_format_from_text(arg1,arg2);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT jstring JNICALL Java_librlibJNI_rlib_1get_1output(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jstring jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    result = (char *)rlib_get_output(arg1);
    
    {
        if(result) jresult = (*jenv)->NewStringUTF(jenv, result); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1get_1output_1length(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    result = (int)rlib_get_output_length(arg1);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1signal_1connect(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2, jlong jarg3, jlong jarg4) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    int arg2 ;
    int (*arg3)(rlib *,void *) = (int (*)(rlib *,void *)) 0 ;
    void *arg4 = (void *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    arg2 = (int)jarg2; 
    arg3 = *(int (**)(rlib *,void *))&jarg3; 
    arg4 = *(void **)&jarg4; 
    result = (int)rlib_signal_connect(arg1,arg2,arg3,arg4);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1signal_1connect_1string(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jlong jarg3, jlong jarg4) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    int (*arg3)(rlib *,void *) = (int (*)(rlib *,void *)) 0 ;
    void *arg4 = (void *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    arg3 = *(int (**)(rlib *,void *))&jarg3; 
    arg4 = *(void **)&jarg4; 
    result = (int)rlib_signal_connect_string(arg1,arg2,arg3,arg4);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1query_1refresh(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    result = (int)rlib_query_refresh(arg1);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1add_1parameter(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    char *arg3 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    {
        arg3 = 0;
        if (jarg3) {
            arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
            if (!arg3) return 0;
        }
    }
    result = (int)rlib_add_parameter(arg1,(char const *)arg2,(char const *)arg3);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    {
        if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, arg3); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1set_1locale(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    result = (int)rlib_set_locale(arg1,arg2);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT void JNICALL Java_librlibJNI_rlib_1set_1output_1parameter(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    char *arg3 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return ;
        }
    }
    {
        arg3 = 0;
        if (jarg3) {
            arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
            if (!arg3) return ;
        }
    }
    rlib_set_output_parameter(arg1,arg2,arg3);
    
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    {
        if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, arg3); 
    }
}


JNIEXPORT void JNICALL Java_librlibJNI_rlib_1set_1output_1encoding(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return ;
        }
    }
    rlib_set_output_encoding(arg1,(char const *)arg2);
    
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1set_1datasource_1encoding(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    char *arg3 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    {
        arg3 = 0;
        if (jarg3) {
            arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
            if (!arg3) return 0;
        }
    }
    result = (int)rlib_set_datasource_encoding(arg1,arg2,arg3);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    {
        if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, arg3); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1free(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    result = (int)rlib_free(arg1);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jstring JNICALL Java_librlibJNI_rlib_1version(JNIEnv *jenv, jclass jcls) {
    jstring jresult = 0 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    result = (char *)rlib_version();
    
    {
        if(result) jresult = (*jenv)->NewStringUTF(jenv, result); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1graph_1add_1bg_1region(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jstring jarg3, jstring jarg4, jfloat jarg5, jfloat jarg6) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    char *arg3 ;
    char *arg4 ;
    float arg5 ;
    float arg6 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    {
        arg3 = 0;
        if (jarg3) {
            arg3 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg3, 0);
            if (!arg3) return 0;
        }
    }
    {
        arg4 = 0;
        if (jarg4) {
            arg4 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg4, 0);
            if (!arg4) return 0;
        }
    }
    arg5 = (float)jarg5; 
    arg6 = (float)jarg6; 
    result = (int)rlib_graph_add_bg_region(arg1,arg2,arg3,arg4,arg5,arg6);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    {
        if (arg3) (*jenv)->ReleaseStringUTFChars(jenv, jarg3, arg3); 
    }
    {
        if (arg4) (*jenv)->ReleaseStringUTFChars(jenv, jarg4, arg4); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_librlibJNI_rlib_1graph_1clear_1bg_1region(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    jint jresult = 0 ;
    rlib *arg1 = (rlib *) 0 ;
    char *arg2 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(rlib **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    result = (int)rlib_graph_clear_bg_region(arg1,arg2);
    
    jresult = (jint)result; 
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    return jresult;
}


#ifdef __cplusplus
}
#endif

