>
> Flurry Analytics API for the Marmalade SDK
>

> What is the Flurry API for Marmalade?
The Flurry API for Marmalade is a cross platform analytics API that is compatible with the Marmalade SDK (see http://www.madewithmarmalade.com)

> What version of the Flurry API is supported?
Version 4.1.0 of the Flurry API has been used to create this extension

> Which platforms are supported?
Android and iOS

> What features are supported?
Analytics only

> How to use the Flurry APi for Marmalade
1. Copy the Flurry folder to the modules folder of your Marmalade SDK installation
2. Add Flurry to the subprojects section of your MKB file
3. Add #include "Flurry.h" to the source file(s) that will use the extension
4. See Flurry.h for more information on how to use the suplied functionality

> Simple log event example:
if (FlurryAvailable())
{
	s3eFlurryStartSession(api_key);
	s3eFlurryLogEvent("my event 1")
	s3eFlurryEndSession();
}

> Log multiple parameter event example:
if (FlurryAvailable())
{
	s3eFlurryStartSession(api_key);
	s3eFlurryLogEventParams("my event 2", "key1|value1|key2|value2|key3|value3");
	s3eFlurryEndSession();
}

> Log an error example:
s3eFlurryLogError("error name", "error message");