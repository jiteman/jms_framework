#include "UnexpectedMethodCallEvent.h"


namespace fakeit {


UnexpectedMethodCallEvent::UnexpectedMethodCallEvent(UnexpectedType unexpectedType, const Invocation &invocation)
	:
		_unexpectedType(unexpectedType),
		_invocation(invocation)
{}

const Invocation &UnexpectedMethodCallEvent::getInvocation() const {
	return _invocation;
}

UnexpectedType UnexpectedMethodCallEvent::getUnexpectedType() const {
	return _unexpectedType;
}


} // namespace fakeit
