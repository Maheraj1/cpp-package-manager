#pragma once

// Core.h file for dynamic libary support

#include <string>
using namespace std::string_literals;

#include "Platform.hpp"

#ifndef CLIB_API
    #ifdef CLIB_SHARED
        #ifdef CLIB_PLATFORM_WINDOWS
            #ifdef BUILD_DLL
                #define CLIB_API __declspec(dllexport)
            #else
                #define CLIB_API __declspec(dllimport)
            #endif
        #else
            #define CLIB_API
        #endif
    #else
        #define CLIB_API
    #endif
#endif