#include "Sequences.h"


namespace fakeit {


struct ActualInvocationsSource;

Sequence::Sequence()
{}

Sequence::~Sequence() THROWS
{}


ConcatenatedSequence::ConcatenatedSequence(const Sequence &seq1, const Sequence &seq2)
	:
		s1(seq1),
		s2(seq2)
{}

ConcatenatedSequence::~ConcatenatedSequence()
{}

unsigned int ConcatenatedSequence::size() const {
	return s1.size() + s2.size();
}

const Sequence &ConcatenatedSequence::getLeft() const {
	return s1;
}

const Sequence &ConcatenatedSequence::getRight() const {
	return s2;
}

void ConcatenatedSequence::getExpectedSequence(std::vector<Invocation::Matcher *> &into) const {
	s1.getExpectedSequence(into);
	s2.getExpectedSequence(into);
}

void ConcatenatedSequence::getInvolvedMocks(std::vector<ActualInvocationsSource *> &into) const {
	s1.getInvolvedMocks(into);
	s2.getInvolvedMocks(into);
}

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

//ConcatenatedSequence operator +(const Sequence &s1, const Sequence &s2) {
//	return ConcatenatedSequence(s1, s2);
//}

//RepeatedSequence operator *(const Sequence &s, int times) {
//	if (times <= 0) {
//		throw std::invalid_argument("times");
//	}

//	return RepeatedSequence(s, times);
//}

//RepeatedSequence operator*(int times, const Sequence &s) {
//	if (times <= 0) {
//		throw std::invalid_argument("times");
//	}

//	return RepeatedSequence(s, times);
//}


}
