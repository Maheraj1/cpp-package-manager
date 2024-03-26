#pragma once

#if defined(_WIN64)
	#define CLIB_PLATFORM_WINDOWS
	#define CLIB_PLATFORM_TYPE_WIN64
	#define CLIB_PLATFORM_TYPE_WIN32
#elif defined(_WIN32)
	#define CLIB_PLATFORM_WINDOWS
	#define CLIB_PLATFORM_TYPE_WIN32
#elif defined(__APPLE__) && defined(__MACH__)
	#define CLIB_PLATFORM_OSX
	#define CLIB_PLATFORM_TYPE_UNIX
#elif defined(__linux__)
	#define CLIB_PLATFORM_LINUX
	#define CLIB_PLATFORM_TYPE_UNIX
#endif