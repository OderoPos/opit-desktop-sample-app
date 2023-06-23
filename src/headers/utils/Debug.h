#pragma once

#include <cstdarg>
#include <iostream>
#include "../dll.h"

static const bool DEBUG = true;

static void printd(const char* text) {
    if (DEBUG) {
        std::cout << text << std::endl;
    }
}

/*
template<class... Args>
void printd(Args... args) {
    if (DEBUG) {
        (std::cout << ... << args);
    }
}
*/

/*
static void printd(const char* fmt ...) {
    if (DEBUG) {
        va_list args;
        va_start(args, fmt);

        while (*fmt != '\0') {
            if (*fmt == 'd') {
                int i = va_arg(args, int);
                std::cout << i << '\n';
            }
            else if (*fmt == 'c') {
                // note automatic conversion to integral type
                int c = va_arg(args, int);
                std::cout << static_cast<char>(c) << '\n';
            }
            else if (*fmt == 'f') {
                double d = va_arg(args, double);
                std::cout << d << '\n';
            }
            else if (*fmt == 's') {
                char* s = va_arg(args, char*);
                std::cout << s << '\n';
            }
            ++fmt;
        }

        va_end(args);
    }
}
*/