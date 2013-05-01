/*
java implementation of the Flurry extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.flurry.android.FlurryAgent;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

class Flurry
{
	private static final String TAG = "Flurry";

	private Map<String, String> ParamsToMap(String params)
	{
		Map<String, String> map = new HashMap<String, String>();
		StringTokenizer tokens = new StringTokenizer(params, "|");
		
		//android.util.Log.d(TAG, "Creating map from params");
		int count = tokens.countTokens() / 2;
		for (int t = 0; t < count; t++)
		{
			String key = tokens.nextToken();
			String value = tokens.nextToken();
			map.put(key, value);
			//android.util.Log.d(TAG, "Added: " + key + " - " + value);
		}
		
		return map;
	}
	
    public void s3eFlurryStartSession(String apiKey)
    {
		android.util.Log.d(TAG, "s3eFlurryStartSession");
		android.util.Log.d(TAG, apiKey);
		
		FlurryAgent.onStartSession(LoaderActivity.m_Activity, apiKey);
		//FlurryAgent.setLogEnabled(true);
		//FlurryAgent.setLogEvents(true);
		//FlurryAgent.setLogLevel(android.util.Log.VERBOSE);
    }
	
    public void s3eFlurryEndSession()
	{
		android.util.Log.d(TAG, "s3eFlurryEndSession");
		FlurryAgent.onEndSession(LoaderActivity.m_Activity);
	}
	
	public void s3eFlurrySetUserID(String userId)
    {
        android.util.Log.d(TAG, "SUId "+userId);
		
		FlurryAgent.setUserId(userId);
    }
	
    public void s3eFlurrySetAge(int age)
    {
		FlurryAgent.setAge(age);
    }
	
    public void s3eFlurryCountPageView()
    {
        FlurryAgent.onPageView();
    }
	
    public void s3eFlurryLogEvent(String eventName)
    {
		android.util.Log.d(TAG, "LE "+eventName);
		
		FlurryAgent.logEvent(eventName);		
    }
	
    public void s3eFlurryLogEventTimed(String eventName)
    {
        android.util.Log.d(TAG, "LET "+eventName);
		
		FlurryAgent.logEvent(eventName,true); //guessing that the boolean is bTimed???? method has no documentation
    }
	
    public void s3eFlurryLogError(String errorName, String message)
    {
        android.util.Log.w(TAG, "LEr "+errorName+" "+message);
		
		FlurryAgent.onError(errorName, message, "N/A");
    }	
	
    public void s3eFlurryLogEventParams(String eventName, String eventParams)//, Map<String, String> params)
    {
        android.util.Log.d(TAG, "LEP " + eventName + " - " + eventParams);

		FlurryAgent.logEvent(eventName, ParamsToMap(eventParams));
		//FlurryAgent.logEvent(eventName);
    }
	
    public void s3eFlurryLogEventParamsTimed(String eventName, String eventParams)//, Map<String, String> params)
    {
        android.util.Log.d(TAG, "LEPT " + eventName + " - " + eventParams);
		
		//FlurryAgent.logEvent(eventName,params,true); //guessing that the boolean is bTimed???? method has no documentation
		FlurryAgent.logEvent(eventName, ParamsToMap(eventParams), true);
    }
	
    public void s3eFlurryEndTimedEvent(String eventName, String eventParams)//, Map<String, String> params)
    {
        android.util.Log.d(TAG, "ETE " + eventName + " - " + eventParams);
		
		FlurryAgent.endTimedEvent(eventName); //only implementation I could find in Android jar
    }
		
    public void s3eFlurrySetSessionReportsOnCloseEnabled(boolean sendSessionReportsOnClose)
    {
        //not implemented
    }
	
    public void s3eFlurrySetSessionReportsOnPauseEnabled(boolean sendSessionReportsOnPause)
    {
		//not implemented
    }
}
