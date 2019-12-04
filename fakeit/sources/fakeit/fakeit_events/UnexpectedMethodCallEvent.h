#pragma once


#include "fakeit/Invocation.hpp"
#include "UnexpectedType.h"


namespace fakeit {


struct UnexpectedMethodCallEvent {
	UnexpectedMethodCallEvent(UnexpectedType unexpectedType, const Invocation &invocation);
	const Invocation &getInvocation() const;
	UnexpectedType getUnexpectedType() const;

	const UnexpectedType _unexpectedType;
	const Invocation &_invocation;
};


} // namespace fakeit
