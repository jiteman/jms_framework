#include "SequenceVerificationProgress.h"

#include "FakeitContext.h"


namespace fakeit {


SequenceVerificationProgress::SequenceVerificationProgress(SequenceVerificationExpectation *ptr) : _expectationPtr(ptr) {
}

SequenceVerificationProgress::SequenceVerificationProgress(
	FakeitContext &fakeit,
	InvocationsSourceProxy sources,
	std::vector<Sequence *> &allSequences)
	:
		SequenceVerificationProgress(new SequenceVerificationExpectation(fakeit, sources, allSequences))
{}

void SequenceVerificationProgress::verifyInvocations(const int times) {
	_expectationPtr->setExpectedCount(times);
}

bool SequenceVerificationProgress::Terminator::toBool() {
	try {
		ThrowFalseEventHandler eh;
		_expectationPtr->VerifyExpectation(eh);
		return true;
	}
	catch (bool e) {
		return e;
	}
}

SequenceVerificationProgress::Terminator::Terminator(smart_ptr<SequenceVerificationExpectation> expectationPtr)
	:
		_expectationPtr(expectationPtr)
{}

SequenceVerificationProgress::Terminator::operator bool() {
	return toBool();
}

bool SequenceVerificationProgress::Terminator::operator!() const {
	return !const_cast<Terminator *>(this)->toBool();
}

SequenceVerificationProgress::~SequenceVerificationProgress() THROWS
{}

SequenceVerificationProgress::operator bool() const {
	return Terminator(_expectationPtr);
}

bool SequenceVerificationProgress::operator !() const {
	return !Terminator(_expectationPtr);
}

SequenceVerificationProgress::Terminator SequenceVerificationProgress::Never() {
	Exactly(0);
	return Terminator(_expectationPtr);
}

SequenceVerificationProgress::Terminator SequenceVerificationProgress::Once() {
	Exactly(1);
	return Terminator(_expectationPtr);
}

SequenceVerificationProgress::Terminator SequenceVerificationProgress::Twice() {
	Exactly(2);
	return Terminator(_expectationPtr);
}

SequenceVerificationProgress::Terminator SequenceVerificationProgress::AtLeastOnce() {
	verifyInvocations(-1);
	return Terminator(_expectationPtr);
}

SequenceVerificationProgress::Terminator SequenceVerificationProgress::Exactly(const int times) {
	if (times < 0) {
		throw std::invalid_argument(std::string("bad argument times:").append(fakeit::to_string(times)));
	}
	verifyInvocations(times);
	return Terminator(_expectationPtr);
}

SequenceVerificationProgress::Terminator SequenceVerificationProgress::Exactly(const Quantity &q) {
	Exactly(q.quantity);
	return Terminator(_expectationPtr);
}

SequenceVerificationProgress::Terminator SequenceVerificationProgress::AtLeast(const int times) {
	if (times < 0) {
		throw std::invalid_argument(std::string("bad argument times:").append(fakeit::to_string(times)));
	}
	verifyInvocations(-times);
	return Terminator(_expectationPtr);
}

SequenceVerificationProgress::Terminator SequenceVerificationProgress::SequenceVerificationProgress::AtLeast(const Quantity &q) {
	AtLeast(q.quantity);
	return Terminator(_expectationPtr);
}

SequenceVerificationProgress SequenceVerificationProgress::setFileInfo(const char * file, int line, const char * callingMethod) {
	_expectationPtr->setFileInfo(file, line, callingMethod);
	return *this;
}


}
