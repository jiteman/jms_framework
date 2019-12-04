#include "Invocation.h"

#include <atomic>


namespace fakeit {

// static
unsigned int Invocation::nextInvocationOrdinal() {
	static std::atomic_uint invocationOrdinal{0};
	return ++invocationOrdinal;
}

Invocation::Matcher::~Matcher() THROWS
{}


Invocation::Invocation(unsigned int ordinal, MethodInfo &method)
	:
		_ordinal(ordinal),
		_method(method),
		_isVerified(false)
{}

unsigned int Invocation::getOrdinal() const {
	return _ordinal;
}

MethodInfo &Invocation::getMethod() const {
	return _method;
}

void Invocation::markAsVerified() {
	_isVerified = true;
}

bool Invocation::isVerified() const {
	return _isVerified;
}


}
