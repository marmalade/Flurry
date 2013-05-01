/*
 * Internal header for the Flurry extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef FLURRY_INTERNAL_H
#define FLURRY_INTERNAL_H

#include "s3eTypes.h"
#include "Flurry.h"
#include "Flurry_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult FlurryInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult FlurryInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void FlurryTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void FlurryTerminate_platform();
void s3eFlurryStartSession_platform(const char* apiKey);
void s3eFlurryEndSession_platform();

void s3eFlurryLogEvent_platform(const char* eventName);

void s3eFlurryLogEventTimed_platform(const char* eventName);

void s3eFlurryLogEventParams_platform(const char* eventName, const char* eventParams);

void s3eFlurryLogEventParamsTimed_platform(const char* eventName, const char* eventParams);

void s3eFlurryEndTimedEvent_platform(const char* eventName, const char* eventParams);

void s3eFlurryLogError_platform(const char* errorName, const char* message);

void s3eFlurrySetUserID_platform(const char* userId);

void s3eFlurrySetAge_platform(int32 age);

void s3eFlurryCountPageView_platform();

void s3eFlurrySetSessionReportsOnCloseEnabled_platform(s3eBool sendSessionReportsOnClose);

void s3eFlurrySetSessionReportsOnPauseEnabled_platform(s3eBool sendSessionReportsOnPause);


#endif /* !FLURRY_INTERNAL_H */