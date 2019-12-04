#include "UnexpectedMethodCallException.h"


namespace fakeit {


// Unlike verification exceptions (that are thrown from the test level), this exception
// should not inherit from std::exception so that production code will not catch it.
UnexpectedMethodCallException::UnexpectedMethodCallException(std::string format)
	:
		_format(format)
{}

std::string UnexpectedMethodCallException::what() const {
	return _format;
}


} // namespace fakeit
