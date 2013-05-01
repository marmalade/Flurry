/*
Generic implementation of the Flurry extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "Flurry_internal.h"
s3eResult FlurryInit()
{
    //Add any generic initialisation code here
    return FlurryInit_platform();
}

void FlurryTerminate()
{
    //Add any generic termination code here
    FlurryTerminate_platform();
}

void s3eFlurryStartSession(const char* apiKey)
{
	s3eFlurryStartSession_platform(apiKey);
}

void s3eFlurryEndSession()
{
	s3eFlurryEndSession_platform();
}

void s3eFlurryLogEvent(const char* eventName)
{
	s3eFlurryLogEvent_platform(eventName);
}

void s3eFlurryLogEventTimed(const char* eventName)
{
	s3eFlurryLogEventTimed_platform(eventName);
}

void s3eFlurryLogEventParams(const char* eventName, const char* eventParams)
{
	s3eFlurryLogEventParams_platform(eventName, eventParams);
}

void s3eFlurryLogEventParamsTimed(const char* eventName, const char* eventParams)
{
	s3eFlurryLogEventParamsTimed_platform(eventName, eventParams);
}

void s3eFlurryEndTimedEvent(const char* eventName, const char* eventParams)
{
	s3eFlurryEndTimedEvent_platform(eventName, eventParams);
}

void s3eFlurryLogError(const char* errorName, const char* message)
{
	s3eFlurryLogError_platform(errorName, message);
}

void s3eFlurrySetUserID(const char* userId)
{
	s3eFlurrySetUserID_platform(userId);
}

void s3eFlurrySetAge(int32 age)
{
	s3eFlurrySetAge_platform(age);
}

void s3eFlurryCountPageView()
{
	s3eFlurryCountPageView_platform();
}

void s3eFlurrySetSessionReportsOnCloseEnabled(s3eBool sendSessionReportsOnClose)
{
	s3eFlurrySetSessionReportsOnCloseEnabled_platform(sendSessionReportsOnClose);
}

void s3eFlurrySetSessionReportsOnPauseEnabled(s3eBool sendSessionReportsOnPause)
{
	s3eFlurrySetSessionReportsOnPauseEnabled_platform(sendSessionReportsOnPause);
}
