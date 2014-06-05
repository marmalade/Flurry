/*
 * android-specific implementation of the Flurry extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */

#include "Flurry_internal.h"
#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_s3eFlurryStartSession;
static jmethodID g_s3eFlurryEndSession;
static jmethodID g_s3eFlurryLogEvent;
static jmethodID g_s3eFlurryLogEventTimed;
static jmethodID g_s3eFlurryLogEventParams;
static jmethodID g_s3eFlurryLogEventParamsTimed;
static jmethodID g_s3eFlurryEndTimedEvent;
static jmethodID g_s3eFlurryLogError;
static jmethodID g_s3eFlurrySetUserID;
static jmethodID g_s3eFlurrySetAge;
static jmethodID g_s3eFlurryCountPageView;
static jmethodID g_s3eFlurrySetSessionReportsOnCloseEnabled;
static jmethodID g_s3eFlurrySetSessionReportsOnPauseEnabled;

s3eResult FlurryInit_platform()
{
    //Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    //Get the extension class
    jclass cls = s3eEdkAndroidFindClass("Flurry");
    if (!cls)
        goto fail;

    //Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    //Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    //Get all the extension methods
    g_s3eFlurryStartSession = env->GetMethodID(cls, "s3eFlurryStartSession", "(Ljava/lang/String;)V");
    if (!g_s3eFlurryStartSession)
        goto fail;

    g_s3eFlurryEndSession = env->GetMethodID(cls, "s3eFlurryEndSession", "()V");
    if (!g_s3eFlurryEndSession)
        goto fail;

    g_s3eFlurryLogEvent = env->GetMethodID(cls, "s3eFlurryLogEvent", "(Ljava/lang/String;)V");
    if (!g_s3eFlurryLogEvent)
        goto fail;

    g_s3eFlurryLogEventTimed = env->GetMethodID(cls, "s3eFlurryLogEventTimed", "(Ljava/lang/String;)V");
    if (!g_s3eFlurryLogEventTimed)
        goto fail;

    g_s3eFlurryLogEventParams = env->GetMethodID(cls, "s3eFlurryLogEventParams", "(Ljava/lang/String;Ljava/lang/String;)V");
	//g_s3eFlurryLogEventParams = env->GetMethodID(cls, "s3eFlurryLogEventParams", "(Ljava/lang/String;Ljava/util/Map;)V");
    if (!g_s3eFlurryLogEventParams)
        goto fail;

    g_s3eFlurryLogEventParamsTimed = env->GetMethodID(cls, "s3eFlurryLogEventParamsTimed", "(Ljava/lang/String;Ljava/lang/String;)V");
	//g_s3eFlurryLogEventParamsTimed = env->GetMethodID(cls, "s3eFlurryLogEventParamsTimed", "(Ljava/lang/String;Ljava/util/Map;I)V");
    if (!g_s3eFlurryLogEventParamsTimed)
        goto fail;

    g_s3eFlurryEndTimedEvent = env->GetMethodID(cls, "s3eFlurryEndTimedEvent", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (!g_s3eFlurryEndTimedEvent)
        goto fail;

    g_s3eFlurryLogError = env->GetMethodID(cls, "s3eFlurryLogError", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (!g_s3eFlurryLogError)
        goto fail;

    g_s3eFlurrySetUserID = env->GetMethodID(cls, "s3eFlurrySetUserID", "(Ljava/lang/String;)V");
    if (!g_s3eFlurrySetUserID)
        goto fail;

    g_s3eFlurrySetAge = env->GetMethodID(cls, "s3eFlurrySetAge", "(I)V");
    if (!g_s3eFlurrySetAge)
        goto fail;

    g_s3eFlurryCountPageView = env->GetMethodID(cls, "s3eFlurryCountPageView", "()V");
    if (!g_s3eFlurryCountPageView)
        goto fail;

    g_s3eFlurrySetSessionReportsOnCloseEnabled = env->GetMethodID(cls, "s3eFlurrySetSessionReportsOnCloseEnabled", "(Z)V");
    if (!g_s3eFlurrySetSessionReportsOnCloseEnabled)
        goto fail;

    g_s3eFlurrySetSessionReportsOnPauseEnabled = env->GetMethodID(cls, "s3eFlurrySetSessionReportsOnPauseEnabled", "(Z)V");
    if (!g_s3eFlurrySetSessionReportsOnPauseEnabled)
        goto fail;

    IwTrace(FLURRY, ("FLURRY init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(s3eFlurry, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;
}

void FlurryTerminate_platform()
{
    // Add any platform-specific termination code here
}

void s3eFlurryStartSession_platform(const char* apiKey)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring apiKey_jstr = env->NewStringUTF(apiKey);
	
    env->CallVoidMethod(g_Obj, g_s3eFlurryStartSession, apiKey_jstr);
	
	env->DeleteLocalRef(apiKey_jstr);
}

void s3eFlurryEndSession_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlurryEndSession);
}

void s3eFlurryLogEvent_platform(const char* eventName)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring eventName_jstr = env->NewStringUTF(eventName);
    env->CallVoidMethod(g_Obj, g_s3eFlurryLogEvent, eventName_jstr);
	env->DeleteLocalRef(eventName_jstr);
}

void s3eFlurryLogEventTimed_platform(const char* eventName)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring eventName_jstr = env->NewStringUTF(eventName);
    env->CallVoidMethod(g_Obj, g_s3eFlurryLogEventTimed, eventName_jstr);
	env->DeleteLocalRef(eventName_jstr);
}

void s3eFlurryLogEventParams_platform(const char* eventName, const char* eventParams)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring eventName_jstr = env->NewStringUTF(eventName);
    jstring eventParams_jstr = env->NewStringUTF(eventParams);
	
	env->CallVoidMethod(g_Obj, g_s3eFlurryLogEventParams, eventName_jstr, eventParams_jstr);
		
	env->DeleteLocalRef(eventParams_jstr);
	env->DeleteLocalRef(eventName_jstr);
}

void s3eFlurryLogEventParamsTimed_platform(const char* eventName, const char* eventParams)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring eventName_jstr = env->NewStringUTF(eventName);
    jstring eventParams_jstr = env->NewStringUTF(eventParams);
    	
	env->CallVoidMethod(g_Obj, g_s3eFlurryLogEventParamsTimed, eventName_jstr, eventParams_jstr);
		
	env->DeleteLocalRef(eventParams_jstr);
	env->DeleteLocalRef(eventName_jstr);
}

void s3eFlurryEndTimedEvent_platform(const char* eventName, const char* eventParams)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring eventName_jstr = env->NewStringUTF(eventName);
    jstring eventParams_jstr = env->NewStringUTF(eventParams);
    
	env->CallVoidMethod(g_Obj, g_s3eFlurryEndTimedEvent, eventName_jstr, eventParams_jstr);
	
	env->DeleteLocalRef(eventParams_jstr);
	env->DeleteLocalRef(eventName_jstr);
}

void s3eFlurryLogError_platform(const char* errorName, const char* message)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring errorName_jstr = env->NewStringUTF(errorName);
    jstring message_jstr = env->NewStringUTF(message);
    
    env->CallVoidMethod(g_Obj, g_s3eFlurryLogError, errorName_jstr, message_jstr);
    
	env->DeleteLocalRef(errorName_jstr);
	env->DeleteLocalRef(message_jstr);
}

void s3eFlurrySetUserID_platform(const char* userId)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring userId_jstr = env->NewStringUTF(userId);
    
    env->CallVoidMethod(g_Obj, g_s3eFlurrySetUserID, userId_jstr);
    
	env->DeleteLocalRef(userId_jstr);
}

void s3eFlurrySetAge_platform(int32 age)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlurrySetAge, age);
}

void s3eFlurryCountPageView_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlurryCountPageView);
}

void s3eFlurrySetSessionReportsOnCloseEnabled_platform(s3eBool sendSessionReportsOnClose)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlurrySetSessionReportsOnCloseEnabled, sendSessionReportsOnClose);
}

void s3eFlurrySetSessionReportsOnPauseEnabled_platform(s3eBool sendSessionReportsOnPause)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlurrySetSessionReportsOnPauseEnabled, sendSessionReportsOnPause);
}
