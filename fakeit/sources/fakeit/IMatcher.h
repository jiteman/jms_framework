#pragma once


#include "mockutils/Destructible.h"

#include <string>


namespace fakeit {


struct IMatcher : Destructible {
	~IMatcher() = default;
	virtual std::string format() const = 0;
};


} // namespace fakeit
