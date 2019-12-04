#include "VerifyNoOtherInvocationsVerificationProgress.h"

#include "InvocationUtils.h"
#include "ThrowFalseEventHandler.h"
#include "fakeit/fakeit_exceptions/UncaughtException.h"

#include <unordered_set>


namespace fakeit {


VerifyNoOtherInvocationsVerificationProgress::
VerifyNoOtherInvocationsExpectation::~VerifyNoOtherInvocationsExpectation() THROWS {
	if (UncaughtException()) {
		return;
	}

	VerifyExpectation(_fakeit);
}

void
VerifyNoOtherInvocationsVerificationProgress::
VerifyNoOtherInvocationsExpectation::setFileInfo(const char * file, int line, const char * callingMethod) {
	_file = file;
	_line = line;
	_callingMethod = callingMethod;
}

VerifyNoOtherInvocationsVerificationProgress::
VerifyNoOtherInvocationsExpectation::VerifyNoOtherInvocationsExpectation(
	VerificationEventHandler &fakeit,
	std::vector<ActualInvocationsSource *> mocks)
	:
		_fakeit(fakeit),
		_mocks(mocks),
		_line(0),
		_isVerified(false)
{}

void
VerifyNoOtherInvocationsVerificationProgress::
VerifyNoOtherInvocationsExpectation::VerifyExpectation(VerificationEventHandler &verificationErrorHandler) {
	if (_isVerified)
		return;
	_isVerified = true;

	std::unordered_set<Invocation *> actualInvocations;
	InvocationUtils::collectActualInvocations(actualInvocations, _mocks);

	std::unordered_set<Invocation *> nonVerifiedInvocations;
	InvocationUtils::selectNonVerifiedInvocations(actualInvocations, nonVerifiedInvocations);

	if (nonVerifiedInvocations.size() > 0) {
		std::vector<Invocation *> sortedNonVerifiedInvocations;
		InvocationUtils::sortByInvocationOrder(nonVerifiedInvocations, sortedNonVerifiedInvocations);

		std::vector<Invocation *> sortedActualInvocations;
		InvocationUtils::sortByInvocationOrder(actualInvocations, sortedActualInvocations);

		NoMoreInvocationsVerificationEvent evt(sortedActualInvocations, sortedNonVerifiedInvocations);
		evt.setFileInfo(_file, _line, _callingMethod);
		return verificationErrorHandler.handle(evt);
	}
}


VerifyNoOtherInvocationsVerificationProgress::VerifyNoOtherInvocationsVerificationProgress(
	VerifyNoOtherInvocationsExpectation *ptr)
	:
		_ptr(ptr)
{}

VerifyNoOtherInvocationsVerificationProgress::VerifyNoOtherInvocationsVerificationProgress(
	FakeitContext &fakeit,
	std::vector<ActualInvocationsSource *> &invocationSources)
	:
		VerifyNoOtherInvocationsVerificationProgress(
			new VerifyNoOtherInvocationsExpectation(fakeit, invocationSources) )
{}

bool VerifyNoOtherInvocationsVerificationProgress::toBool() {
	try {
		ThrowFalseEventHandler ev;
		_ptr->VerifyExpectation(ev);
		return true;
	} catch (bool e) {
		return e;
	}
}

VerifyNoOtherInvocationsVerificationProgress::~VerifyNoOtherInvocationsVerificationProgress() THROWS
{}

VerifyNoOtherInvocationsVerificationProgress VerifyNoOtherInvocationsVerificationProgress::setFileInfo(
	const char * file,
	int line,
	const char * callingMethod)
{
	_ptr->setFileInfo(file, line, callingMethod);
	return *this;
}

VerifyNoOtherInvocationsVerificationProgress::operator bool() const {
	return const_cast<VerifyNoOtherInvocationsVerificationProgress *>(this)->toBool();
}

bool VerifyNoOtherInvocationsVerificationProgress::operator !() const {
	return !const_cast<VerifyNoOtherInvocationsVerificationProgress *>(this)->toBool();
}


}
