#pragma once


#include "VerificationType.h"


namespace fakeit {


struct VerificationEvent {

	VerificationEvent(VerificationType aVerificationType);
	virtual ~VerificationEvent() = default;
	VerificationType verificationType() const;
	void setFileInfo(const char *aFile, int aLine, const char *aCallingMethod);
	const char *file() const;
	int line() const;
	const char *callingMethod() const;

private:
	VerificationType _verificationType;
	const char *_file;
	int _line;
	const char *_callingMethod;
};


} // namespace fakeit
