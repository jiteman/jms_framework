#pragma once

#include "FakeitException.h"

#include <string>


namespace fakeit {


// Unlike verification exceptions (that are thrown from the test level), this exception
// should not inherit from std::exception so that production code will not catch it.
struct UnexpectedMethodCallException : public FakeitException {

	UnexpectedMethodCallException(std::string format);
	virtual std::string what() const override;

private:
	std::string _format;
};


} // namespace fakeit
