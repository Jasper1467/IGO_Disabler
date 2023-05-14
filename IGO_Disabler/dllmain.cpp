#include <Windows.h>

#include "Platform.h"

#include "Hooks/Hooks.h"

typedef void(__fastcall* EnableIGODebugMenuFn)(bool);

#ifndef NDEBUG
#define ENABLE_IGO_DEBUG_MENU
#endif

BOOL WINAPI StartupThread()
{
#ifdef ENABLE_IGO_DEBUG_MENU
	const auto EnableIGODebugMenu = (EnableIGODebugMenuFn)GetProcAddress(GetModuleHandle(IGO_MODULE),
		"EnableIGODebugMenu");

	EnableIGODebugMenu(true);
#endif

	Hooks::Initialize();

	return TRUE;
}

void ThreadCreation()
{
	CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)StartupThread, nullptr, 0, nullptr);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		ThreadCreation();

	return TRUE;
}