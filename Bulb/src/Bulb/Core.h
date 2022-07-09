#pragma once

#ifdef BLB_PLATFORM_WINDOWS
	#ifdef BLB_BUILD_DLL
		#define BULB_API __declspec(dllexport)	
	#else
		#define BULB_API __declspec(dllimport)
	#endif
#else
	#error Bulb only supports Windows!
#endif