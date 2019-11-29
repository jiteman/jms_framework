#pragma once


#include "jmsf/encodebuba/platforming/compiler_detection.h"


#if !defined( JMSF_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )
	#error This file "jmsf/ms_windows/temporary_windows_include.h" is included, but there is no MS Windows detected.

#endif


#include "jmsf/encodebuba/common_suppress_compilation_warnings.h"


#pragma warning( push )
#pragma warning( disable : 4668 ) // is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'


#include <windows.h>


#pragma warning( pop )


#if defined( max )
	#undef max
#endif

#if defined( min )
	#undef min
#endif

#if defined( small )
	#undef small
#endif
