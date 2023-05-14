#include "Hooks.h"

#include "../SignatureScan.h"
#include "../Platform.h"

#include "../MinHook/include/MinHook.h"

void Hooks::Initialize()
{
	const auto pInjectIGODll_0_Target = PatternScan(GetModuleHandle(IGO_MODULE), "84 C0 75 37 E8") + 0xEC;
	MH_CreateHook(pInjectIGODll_0_Target, hkInjectIGODll_0, nullptr);
}

void Hooks::hkInjectIGODll_0(HANDLE hProcess, void* a2)
{
	// Do nothing
}