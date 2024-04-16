#include "jadl.h"
#include "http/httplib.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif
	void Log(const char* format_str, ...)
	{
		static const char* const prefix = "%d ";
		static const size_t prefix_length = 3;
		va_list ap;

		printf("%lld ", (long long int)time(0));
		va_start(ap, format_str);
		vprintf(format_str, ap);
		va_end(ap);
	}

	void JADL_Init()
	{
		Log("Init");
		httplib::Client client("http://localhost:4506");
		httplib::Result response = client.Get("/api/test/HelloWorld");
		if (response)
		{
			Log("Status: %i", response->status);
			Log("Body: %s", response->body.c_str());
		}
		else
		{
			Log("Response is null");
		}
	}

	void JADL_OnClientConnected(const char* clientName)
	{
		Log(clientName);
	}

	void JADL_OnMapLoaded(const char* mapName, MapLoadContext context)
	{
		Log("Map Loaded: %s", mapName);
	}

	void JADL_OnMapConcluded(const char* mapName)
	{
		Log("Map Concluded: %s", mapName);
	}

#ifdef __cplusplus
}

#endif