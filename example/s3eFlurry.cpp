#include "Flurry.h"
#include "IwDebug.h"
#include "IwGx.h"
#include "s3eExt.h"
#include "s3eOSReadString.h"
#include "s3ePointer.h"

const char *YOUR_API_KEY = "YOUR_FLURRY_API_KEY_GOES_HERE";

void flurryInit()
{
    if (!FlurryAvailable())
    {
        s3eDebugOutputString(s3eExtGetErrorString());
        return;
    }

    s3eFlurryStartSession(YOUR_API_KEY);
    s3eDebugOutputString("Successfully started Flurry extension for API key:");
    s3eDebugOutputString(YOUR_API_KEY);

    s3eFlurrySetAge(42);
    s3eFlurrySetUserID("UNIQUE_USER_ID_LOL");
}

void flurryLogError()
{
    s3eFlurryLogError("TestError", "TestErrorMessage");
    s3eDebugOutputString("Flurry test error logged");
}

void flurryLogEvent()
{
    s3eFlurryLogEvent("TestEventNoParams");
    s3eDebugOutputString("Flurry test event logged (no parameters)");
}

void flurryLogEventWithParams()
{
    s3eFlurryLogEventParams("TestEventWithParams", "paramA|hello|paramB|5.4321|paramC|42");
    s3eDebugOutputString("Flurry test event logged (with parameters)");
}

void flurryLogAll()
{
    flurryLogError();
    flurryLogEvent();
    flurryLogEventWithParams();
}

void flurryEnd()
{
    s3eFlurryEndSession();
    s3eDebugOutputString("Flurry Shutdown");
}

void touchEvent(s3ePointerTouchEvent *event)
{
    if(event->m_Pressed)
    {
        flurryLogAll();
    }
}

// Example showing how to use the Flurry extension
int main()
{
    s3eDebugOutputString("Booting Flurry example");

    s3ePointerRegister(S3E_POINTER_BUTTON_EVENT, (s3eCallback)touchEvent, NULL);

    IwGxInit();

    IwGxSetColClear(0, 0, 0, 0xff);

    flurryInit();
    flurryLogAll();

    while(!s3eDeviceCheckQuitRequest())
    {
        IwGxClear();

        IwGxPrintString(100, 100, "s3eFlurryTest");

        IwGxPrintString(100, 300, "Touch to fire event");

        IwGxFlush();
        IwGxSwapBuffers();
        s3eDeviceYield(0);
    }

    flurryEnd();

    IwGxTerminate();

    return 0;
}