#pragma once

#if _WIN32 || _WIN64
#if _WIN64
#define IGO_MODULE (L"IGO64.dll")
#else
#define ENV32BIT
#define IGO_MODULE (L"IGO32.dll")
#endif
#endif