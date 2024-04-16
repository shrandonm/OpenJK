#include "jadl.h"
#include "http/httplib.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif
	void Log(const char* format_str, ...)
	{
		va_list ap;
		printf("[JADL] ");
		va_start(ap, format_str);
		vprintf(format_str, ap);
		va_end(ap);
		printf("\n");
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