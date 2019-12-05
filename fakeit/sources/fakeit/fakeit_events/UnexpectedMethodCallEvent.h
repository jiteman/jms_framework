#pragma once


#include "UnexpectedType.h"

#include "fakeit_lib.h"


namespace fakeit {


struct Invocation;


struct JMSD_FAKEIT_SHARED_INTERFACE UnexpectedMethodCallEvent {
	UnexpectedMethodCallEvent(UnexpectedType unexpectedType, const Invocation &invocation);
	const Invocation &getInvocation() const;
	UnexpectedType getUnexpectedType() const;

	const UnexpectedType _unexpectedType;
	const Invocation &_invocation;
};


} // namespace fakeit
