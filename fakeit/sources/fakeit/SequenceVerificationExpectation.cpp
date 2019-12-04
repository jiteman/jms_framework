#include "SequenceVerificationExpectation.h"

#include "fakeit/fakeit_exceptions/UncaughtException.h"


namespace fakeit {


SequenceVerificationExpectation::~SequenceVerificationExpectation() THROWS {
	if (UncaughtException()) {
		return;
	}

	VerifyExpectation(_fakeit);
}

void SequenceVerificationExpectation::setExpectedPattern(std::vector<Sequence *> expectedPattern) {
	_expectedPattern = expectedPattern;
}

void SequenceVerificationExpectation::setExpectedCount(const int count) {
	_expectedCount = count;
}

void SequenceVerificationExpectation::setFileInfo(const char * file, int line, const char * callingMethod) {
	_file = file;
	_line = line;
	_testMethod = callingMethod;
}

SequenceVerificationExpectation::SequenceVerificationExpectation(
	VerificationEventHandler &fakeit,
	InvocationsSourceProxy mocks,
	std::vector<Sequence *> &expectedPattern)
	:
		_fakeit(fakeit),
		_involvedInvocationSources(mocks),
		_expectedPattern(expectedPattern),
		_expectedCount(-1), // AT_LEAST_ONCE
		_line(0),
		_isVerified(false)
{}


void SequenceVerificationExpectation::VerifyExpectation(VerificationEventHandler &verificationErrorHandler) {
	if (_isVerified) return;

	_isVerified = true;

	MatchAnalysis ma;
	ma.run(_involvedInvocationSources, _expectedPattern);

	if (isAtLeastVerification() && atLeastLimitNotReached(ma.count)) {
		return handleAtLeastVerificationEvent(verificationErrorHandler, ma.actualSequence, ma.count);
	}

	if (isExactVerification() && exactLimitNotMatched(ma.count)) {
		return handleExactVerificationEvent(verificationErrorHandler, ma.actualSequence, ma.count);
	}

	markAsVerified(ma.matchedInvocations);
}

std::vector<Sequence *> &SequenceVerificationExpectation::collectSequences(std::vector<Sequence *> &vec) {
	return vec;
}

// static
void SequenceVerificationExpectation::markAsVerified(std::vector<Invocation *> &matchedInvocations) {
	for (auto i : matchedInvocations) {
		i->markAsVerified();
	}
}

bool SequenceVerificationExpectation::isAtLeastVerification() {
	// negative number represents an "AtLeast" search;
	return _expectedCount < 0;
}

bool SequenceVerificationExpectation::isExactVerification() {
	return !isAtLeastVerification();
}

bool SequenceVerificationExpectation::atLeastLimitNotReached(int actualCount) {
	return actualCount < -_expectedCount;
}

bool SequenceVerificationExpectation::exactLimitNotMatched(int actualCount) {
	return actualCount != _expectedCount;
}

void SequenceVerificationExpectation::handleExactVerificationEvent(
	VerificationEventHandler &verificationErrorHandler,
	std::vector<Invocation *> actualSequence,
	int count)
{
	SequenceVerificationEvent evt(VerificationType::Exact, _expectedPattern, actualSequence, _expectedCount, count);
	evt.setFileInfo(_file, _line, _testMethod);
	return verificationErrorHandler.handle(evt);
}

void SequenceVerificationExpectation::handleAtLeastVerificationEvent(
	VerificationEventHandler &verificationErrorHandler,
	std::vector<Invocation *> actualSequence,
	int count)
{
	SequenceVerificationEvent evt(VerificationType::AtLeast, _expectedPattern, actualSequence, -_expectedCount, count);
	evt.setFileInfo(_file, _line, _testMethod);
	return verificationErrorHandler.handle(evt);
}


}
