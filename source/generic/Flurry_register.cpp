/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "Flurry_autodefs.h"
#include "s3eEdk.h"
#include "Flurry.h"
//Declarations of Init and Term functions
extern s3eResult FlurryInit();
extern void FlurryTerminate();


void FlurryRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[13];
    funcPtrs[0] = (void*)s3eFlurryStartSession;
    funcPtrs[1] = (void*)s3eFlurryEndSession;
    funcPtrs[2] = (void*)s3eFlurryLogEvent;
    funcPtrs[3] = (void*)s3eFlurryLogEventTimed;
    funcPtrs[4] = (void*)s3eFlurryLogEventParams;
    funcPtrs[5] = (void*)s3eFlurryLogEventParamsTimed;
    funcPtrs[6] = (void*)s3eFlurryEndTimedEvent;
    funcPtrs[7] = (void*)s3eFlurryLogError;
    funcPtrs[8] = (void*)s3eFlurrySetUserID;
    funcPtrs[9] = (void*)s3eFlurrySetAge;
    funcPtrs[10] = (void*)s3eFlurryCountPageView;
    funcPtrs[11] = (void*)s3eFlurrySetSessionReportsOnCloseEnabled;
    funcPtrs[12] = (void*)s3eFlurrySetSessionReportsOnPauseEnabled;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[13] = { 0 };

    /*
     * Register the extension
     */
s3eEdkRegister("Flurry", funcPtrs, sizeof(funcPtrs), flags, FlurryInit, FlurryTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int FlurryStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&FlurryRegisterExt;
    return 0;
}

int g_FlurryVal = FlurryStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    FlurryRegisterExt();
}
#endif

#endif
