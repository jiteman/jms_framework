#include "VerificationEvent.h"


namespace fakeit {


VerificationEvent::VerificationEvent(VerificationType aVerificationType) :
		_verificationType(aVerificationType), _line(0) {
}

VerificationType VerificationEvent::verificationType() const {
	return _verificationType;
}

void VerificationEvent::setFileInfo(const char * aFile, int aLine, const char * aCallingMethod) {
	_file = aFile;
	_callingMethod = aCallingMethod;
	_line = aLine;
}

const char *VerificationEvent::file() const {
	return _file;
}

int VerificationEvent::line() const {
	return _line;
}

const char *VerificationEvent::callingMethod() const {
	return _callingMethod;
}


} // namespace fakeit
