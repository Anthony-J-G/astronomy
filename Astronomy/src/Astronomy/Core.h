#pragma once

// Handle DLL Import/Export API Macros
#ifdef ASTRO_PLATFORM_WINDOWS
	#ifdef ASTRO_BUILD_DLL
		#define ASTRO_API __declspec(dllexport)
	#else
		#define ASTRO_API __declspec(dllimport)

	#endif // ASTRO_BUILD_DLL

#else
	#error Non-Windows OS not supported	

#endif // ASTRO_PLATFORM_WINDOWS

