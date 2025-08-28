// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。

// ノッチを維持(素通し)するためのグローバル変数
int g_power = 0;
int g_brake = 0;
int g_reverser = 0;

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

// Called when this plug-in is loaded
void WINAPI atsLoad() {}

// Called when this plug-in is unloaded
void WINAPI atsDispose() {}

// Returns the version numbers of ATS plug-in
int WINAPI atsGetPluginVersion() {
	return ATS_VERSION;
}

// Called when the train is loaded
void WINAPI atsSetVehicleSpec(ATS_VEHICLESPEC) {}

// Called when the game is started
void WINAPI atsInitialize(int) {}

// Called every frame
ATS_HANDLES WINAPI atsElapse(ATS_VEHICLESTATE vs, int* p_panel, int* p_sound) {
	ATS_HANDLES handles = { g_brake, g_power, g_reverser, ATS_CONSTANTSPEED_CONTINUE };
	return handles;
}

// Called when the power is changed
void WINAPI atsSetPower(int notch) {
	g_power = notch;
}

// Called when the brake is changed
void WINAPI atsSetBrake(int notch) {
	g_brake = notch;
}

// Called when the reverser is changed
void WINAPI atsSetReverser(int pos) {
	g_reverser = pos;
}

// Called when any ATS key is pressed
void WINAPI atsKeyDown(int ats_key_code) {}

// Called when any ATS key is released
void WINAPI atsKeyUp(int ats_key_code) {}

// Called when the horn is used
void WINAPI atsHornBlow(int ats_horn) {}

// Called when the door is opened
void WINAPI atsDoorOpen() {}

// Called when the door is closed
void WINAPI atsDoorClose() {}

// Called when current signal is changed
void WINAPI atsSetSignal(int signal) {}

// Called when the beacon data is received
void WINAPI atsSetBeaconData(ATS_BEACONDATA beacon_data) {}

