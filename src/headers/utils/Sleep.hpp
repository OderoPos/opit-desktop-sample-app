#pragma once

#ifdef _WIN32
	#include <Windows.h>
#elif(__linux__)
	#include <unistd.h>
#else
	#include <unistd.h>
#endif

void sleep(long delay);