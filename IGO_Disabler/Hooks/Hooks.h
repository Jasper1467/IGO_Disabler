#pragma once

#include <Windows.h>

namespace Hooks
{
	void Initialize();

	void hkInjectIGODll_0(HANDLE hProcess, void* a2);
}