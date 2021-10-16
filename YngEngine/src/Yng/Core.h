#pragma once

#ifdef YNG_PLATFORM_WINDOWS

	#ifdef YNG_BUILD_DLL
		#define YNG_API __declspec(dllexport)
	#else
		#define YNG_API __declspec(dllimport)
	#endif
#else 
	#error Only Supports Windows!
#endif  
