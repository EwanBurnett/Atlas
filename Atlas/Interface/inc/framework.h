#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files
#include <windows.h>
#else

#endif

#include <Atlas.h>

#define DLLEXPORT

#ifdef DLLEXPORT
#define ATLAS_API extern "C" __declspec(dllexport)
#else
#define ATLAS_API extern __declspec(dllimport)
#endif

