#pragma once

#include <string>
#include <exception>
#include <ostream>

#include "fakeit_lib.h"


namespace fakeit {


struct JMSD_FAKEIT_SHARED_INTERFACE FakeitException {
	std::exception err;

	virtual ~FakeitException() = default;

	virtual std::string what() const = 0;

	friend JMSD_FAKEIT_SHARED_INTERFACE std::ostream &operator <<(std::ostream &os, const FakeitException &val);
};

JMSD_FAKEIT_SHARED_INTERFACE std::ostream &operator <<(std::ostream &os, const FakeitException &val);


} // namespace fakeit
