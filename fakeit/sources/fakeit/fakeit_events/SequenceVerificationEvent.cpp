#include "SequenceVerificationEvent.h"


namespace fakeit {


SequenceVerificationEvent::SequenceVerificationEvent(
	VerificationType aVerificationType,
	std::vector<Sequence *> &anExpectedPattern,
	std::vector<Invocation *> &anActualSequence,
	int anExpectedCount,
	int anActualCount)
	:
		VerificationEvent(aVerificationType),
		_expectedPattern(anExpectedPattern),
		_actualSequence(anActualSequence),
		_expectedCount(anExpectedCount),
		_actualCount(anActualCount)
{}

const std::vector<Sequence *> &SequenceVerificationEvent::expectedPattern() const {
	return _expectedPattern;
}

const std::vector<Invocation *> &SequenceVerificationEvent::actualSequence() const {
	return _actualSequence;
}

int SequenceVerificationEvent::expectedCount() const {
	return _expectedCount;
}

int SequenceVerificationEvent::actualCount() const {
	return _actualCount;
}


} // namespace fakeit
