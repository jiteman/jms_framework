#include "RepeatedSequence.h"

#include <stdexcept>


namespace fakeit {


RepeatedSequence::RepeatedSequence(const Sequence &s, const int t)
	:
		_s(s),
		times(t)
{}

RepeatedSequence::~RepeatedSequence()
{}

unsigned int RepeatedSequence::size() const {
	return _s.size() * times;
}

void RepeatedSequence::getInvolvedMocks(std::vector<ActualInvocationsSource *> &into) const {
	_s.getInvolvedMocks(into);
}

void RepeatedSequence::getExpectedSequence(std::vector<Invocation::Matcher *> &into) const {
	for (int i = 0; i < times; i++)
		_s.getExpectedSequence(into);
}

int RepeatedSequence::getTimes() const {
	return times;
}

const Sequence &RepeatedSequence::getSequence() const {
	return _s;
}


RepeatedSequence operator *(const Sequence &s, int times) {
	if (times <= 0) {
		throw std::invalid_argument("times");
	}

	return RepeatedSequence(s, times);
}

RepeatedSequence operator*(int times, const Sequence &s) {
	if (times <= 0) {
		throw std::invalid_argument("times");
	}

	return RepeatedSequence(s, times);
}


} // namespace fakeit
