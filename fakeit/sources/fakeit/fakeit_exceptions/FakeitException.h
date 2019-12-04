#pragma once

#include <string>
#include <exception>
#include <ostream>


namespace fakeit {


struct FakeitException {
	std::exception err;

	virtual ~FakeitException() = default;

	virtual std::string what() const = 0;

	friend std::ostream &operator <<(std::ostream &os, const FakeitException &val);
};


} // namespace fakeit
