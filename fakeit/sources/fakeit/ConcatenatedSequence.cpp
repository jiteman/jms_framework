#include "ConcatenatedSequence.h"


namespace fakeit {


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


ConcatenatedSequence operator +(const Sequence &s1, const Sequence &s2) {
	return ConcatenatedSequence(s1, s2);
}


} // namespace fakeit

