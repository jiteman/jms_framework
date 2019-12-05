#pragma once

#include "FakeitException.h"

#include <string>

#include "fakeit_lib.h"


namespace fakeit {


// Unlike verification exceptions (that are thrown from the test level), this exception
// should not inherit from std::exception so that production code will not catch it.
struct JMSD_FAKEIT_SHARED_INTERFACE UnexpectedMethodCallException : public FakeitException {

	UnexpectedMethodCallException(std::string format);
	virtual std::string what() const override;

private:
	std::string _format;
};


} // namespace fakeit
