#pragma once


#include "mockutils/Macros.hpp"

#include <unordered_set>

#include "fakeit_lib.h"


namespace fakeit {


struct Invocation;


struct JMSD_FAKEIT_SHARED_INTERFACE ActualInvocationsSource {
	virtual void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const = 0;

	virtual ~ActualInvocationsSource() NO_THROWS;
};


} // namespace fakeit
