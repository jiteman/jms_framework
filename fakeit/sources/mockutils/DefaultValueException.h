#pragma once


#include <string>


namespace fakeit {


struct DefaultValueInstatiationException {
	virtual ~DefaultValueInstatiationException() = default;

	virtual std::string what() const = 0;
};


} // namespace fakeit
