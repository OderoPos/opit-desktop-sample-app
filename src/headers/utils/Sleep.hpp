#pragma once

#ifdef _WIN32
	#include <Windows.h>
#elif(__linux__)
	#include <unistd.h>
#else
	#include <unistd.h>
#endif

#include "../dll.h"

DllExport void sleep(long delay);