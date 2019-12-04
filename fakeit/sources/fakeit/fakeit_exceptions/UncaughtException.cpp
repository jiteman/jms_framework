#include "UncaughtException.h"

#include <exception>


namespace fakeit {


bool UncaughtException () {

#if __cplusplus >= 201703L
	return std::uncaught_exceptions() >= 1;
#else
	return std::uncaught_exception();
#endif

}


} // namespace fakeit

