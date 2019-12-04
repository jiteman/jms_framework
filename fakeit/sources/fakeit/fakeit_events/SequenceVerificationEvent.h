#pragma once

#include "VerificationEvent.h"

#include <vector>


namespace fakeit {


class Sequence;
class Invocation;


struct SequenceVerificationEvent : public VerificationEvent {

	~SequenceVerificationEvent() = default;

	SequenceVerificationEvent(
		VerificationType aVerificationType,
		std::vector<Sequence *> &anExpectedPattern,
		std::vector<Invocation *> &anActualSequence,
		int anExpectedCount,
		int anActualCount);

	const std::vector<Sequence *> &expectedPattern() const;
	const std::vector<Invocation *> &actualSequence() const;
	int expectedCount() const;
	int actualCount() const;

private:
	const std::vector<Sequence *> _expectedPattern;
	const std::vector<Invocation *> _actualSequence;
	const int _expectedCount;
	const int _actualCount;
};


} // namespace fakeit
