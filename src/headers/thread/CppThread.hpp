#pragma once

#ifdef _WIN32
#include <comdef.h>
#elif(__linux__)
#include <thread>
#else
#include <thread>
#endif

#include <iostream>
#include "../dll.h"

class DllExport CppThread {
public:

#ifdef _WIN32
    CppThread(DWORD(WINAPI* function)(LPVOID lpThreadParameter), void* argument) {
#elif(__linux__)
    CppThread(void(*function)(int), void* argument) {
#else
    CppThread(void(*function)(int), void* argument) {
#endif

    #ifdef _WIN32
        DWORD dwThreadId;

        HANDLE hThreadArray = CreateThread(
            NULL,                   // default security attributes
            0,                      // use default stack size
            function,               // thread function name
            argument,          // argument to thread function 
            0,                      // use default creation flags 
            &dwThreadId);           // returns the thread identifier

        // Check the return value for success.
        // If CreateThread fails, terminate execution. 
        // This will automatically clean up threads and memory. 
        if (hThreadArray == NULL) {
            std::cout << "startReadThread error creating thread" << std::endl;
            ExitProcess(3);
        }

    #elif(__linux__)
        std::thread first(function, argument);
    #else
        std::thread first(function, argument);
    #endif

    }
};