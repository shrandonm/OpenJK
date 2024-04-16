#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

	typedef enum
	{
		JADL_Context_InitialLoad,
		JADL_Context_Restart,
	} MapLoadContext;

	void JADL_Init();
	void JADL_OnMapConcluded(const char* mapName);
	void JADL_OnClientConnected(const char* clientName);
	void JADL_OnMapLoaded(const char* mapName, MapLoadContext context);

#ifdef __cplusplus
}
#endif
