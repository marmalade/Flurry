Flurry Analytics for Marmalade
==============================

This Marmalade extension was built to provide support for Flurry analytics in your Marmalade-based mobile app.

#### Supported Platforms
1. Android
2. iOS

#### Flurry SDK Versions
1. Android 3.2.2
2. iPhone 4.2.3

#### Supported Features
1. Analytics only

## Using the Marmalade Flurry API

1. Clone this whole folder into your project (or add it as a submodule)
2. Add "Flurry" to the subprojects section of your MKB file
3. Add `#include "Flurry.h"` to the source files where it will be used
4. Refer to the file `Flurry.h` for more information on the supplied functionality

##### Initializing Flurry
```cpp
if (FlurryAvailable())
{
	s3eFlurryStartSession(YOUR_FLURRY_API_KEY_HERE);
}
```

##### Logging a simple event
```cpp
if (FlurryAvailable())
{
	s3eFlurryLogEvent("EVENT_NAME");
}
```

##### Logging an event with parameters
```cpp
if (FlurryAvailable())
{
	s3eFlurryLogEventParams("EVENT_NAME", "KEY1|VALUE1|KEY2|VALUE2|KEY3|VALUE3");
}
```

##### Logging an error
```cpp
if (FlurryAvailable())
{
    s3eFlurryLogError("ERROR_NAME", "ERROR_MESSAGE");
}
```

##### Terminating Flurry
```cpp
if (FlurryAvailable())
{
    s3eFlurryEndSession();
}
```

## Notes
* Flurry's API supports a maximum of 10 parameters per event as of this writing.
* In order to correctly get full statistics on Android, call `s3eFlurryEndSession()` on `S3E_DEVICE_PAUSE` and `s3eFlurryStartSession(YOUR_FLURRY_API_KEY_HERE)` again on `S3E_DEVICE_UNPAUSE`
