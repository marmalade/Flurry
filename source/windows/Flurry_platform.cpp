/*
 * windows-specific implementation of the Flurry extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "Flurry_internal.h"

s3eResult FlurryInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS; // We need this to ensure the extension is loaded (and breakpoints are hit) when debugging on Windows so we don't always have to deploy to devices for basic testing.
}

void FlurryTerminate_platform()
{
    // Add any platform-specific termination code here
}

void s3eFlurryStartSession_platform(const char* apiKey)
{
}

void s3eFlurryEndSession_platform()
{
}

void s3eFlurryLogEvent_platform(const char* eventName)
{
}

void s3eFlurryLogEventTimed_platform(const char* eventName)
{
}

void s3eFlurryLogEventParams_platform(const char* eventName, const char* eventParams)
{
}

void s3eFlurryLogEventParamsTimed_platform(const char* eventName, const char* eventParams)
{
}

void s3eFlurryEndTimedEvent_platform(const char* eventName, const char* eventParams)
{
}

void s3eFlurryLogError_platform(const char* errorName, const char* message)
{
}

void s3eFlurrySetUserID_platform(const char* userId)
{
}

void s3eFlurrySetAge_platform(int32 age)
{
}

void s3eFlurryCountPageView_platform()
{
}

void s3eFlurrySetSessionReportsOnCloseEnabled_platform(s3eBool sendSessionReportsOnClose)
{
}

void s3eFlurrySetSessionReportsOnPauseEnabled_platform(s3eBool sendSessionReportsOnPause)
{
}
