#pragma once

#include "Sequence.h"

#include <vector>


namespace fakeit {


class ConcatenatedSequence : public virtual Sequence {
private:
	const Sequence &s1;
	const Sequence &s2;

protected:
	ConcatenatedSequence(const Sequence &seq1, const Sequence &seq2);

public:

	virtual ~ConcatenatedSequence();

	unsigned int size() const override;

	const Sequence &getLeft() const;

	const Sequence &getRight() const;

	void getExpectedSequence(std::vector<Invocation::Matcher *> &into) const override;

	virtual void getInvolvedMocks(std::vector<ActualInvocationsSource *> &into) const override;

	friend ConcatenatedSequence operator +(const Sequence &s1, const Sequence &s2);
};


ConcatenatedSequence operator +(const Sequence &s1, const Sequence &s2);


} // namespace fakeit
