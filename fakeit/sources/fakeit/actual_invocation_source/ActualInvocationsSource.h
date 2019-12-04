#pragma once


#include "mockutils/Macros.hpp"

#include <unordered_set>


namespace fakeit {


struct Invocation;


struct ActualInvocationsSource {
	virtual void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const = 0;

	virtual ~ActualInvocationsSource() NO_THROWS;
};


} // namespace fakeit
