#include "DefaultEventLogger.h"

#include <iostream>

namespace fakeit {


DefaultEventLogger::DefaultEventLogger(EventFormatter &formatter)
	:
		_formatter(formatter),
		_out(std::cout)
{}

void DefaultEventLogger::handle(const UnexpectedMethodCallEvent &e) {
	_out << _formatter.format(e) << std::endl;
}

void DefaultEventLogger::handle(const SequenceVerificationEvent &e) {
	_out << _formatter.format(e) << std::endl;
}

void DefaultEventLogger::handle(const NoMoreInvocationsVerificationEvent &e) {
	_out << _formatter.format(e) << std::endl;
}


}
