#include "atsplugin.h"

int g_brakeNotches = 0;
int g_powerNotches = 0;
int g_reverser = 0;

BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
) {
}

// Called when this plug-in is loaded
void WINAPI Load(void) {

}

// Called when this plug-in is unloaded
void WINAPI Dispose(void) {}

// Returns the version numbers of ATS plug-in
int WINAPI GetPluginVersion(void) { return ATS_VERSION; }

// Called when the train is loaded
void WINAPI SetVehicleSpec(ATS_VEHICLESPEC) {}

// Called when the game is started
void WINAPI Initialize(int) {}

// Called every frame
ATS_HANDLES WINAPI Elapse(ATS_VEHICLESTATE, int*, int*) {
	ATS_HANDLES handles = { g_brakeNotches, g_powerNotches, g_reverser, ATS_CONSTANTSPEED_CONTINUE };
	return handles;
}

// Called when the power is changed
void WINAPI SetPower(int notch) {
	g_powerNotches = notch;
}

// Called when the brake is changed
void WINAPI SetBrake(int brake) {
	g_brakeNotches = brake;
}

// Called when the reverser is changed
void WINAPI SetReverser(int reverser) {
	g_reverser = reverser;
}

// Called when any ATS key is pressed
void WINAPI KeyDown(int) {}

// Called when any ATS key is released
void WINAPI KeyUp(int) {}

// Called when the horn is used
void WINAPI HornBlow(int) {}

// Called when the door is opened
void WINAPI DoorOpen(void) {}

// Called when the door is closed
void WINAPI DoorClose(void) {}

// Called when current signal is changed
void WINAPI SetSignal(int) {}

// Called when the beacon data is received
void WINAPI SetBeaconData(ATS_BEACONDATA) {}