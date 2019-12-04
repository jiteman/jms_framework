#include "Invocation.h"

//#include <typeinfo>
//#include <tuple>
//#include <string>
//#include <iosfwd>
//#include <sstream>


//#include "fakeit/domain_objects/MethodInfo.h"

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
