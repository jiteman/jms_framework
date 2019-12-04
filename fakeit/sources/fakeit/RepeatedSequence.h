#pragma once

#include "Sequence.h"


namespace fakeit {


class RepeatedSequence : public virtual Sequence {
private:
	const Sequence &_s;
	const int times;

protected:
	RepeatedSequence(const Sequence &s, const int t);

public:

	~RepeatedSequence();

	unsigned int size() const override ;

	friend RepeatedSequence operator *(const Sequence &s, int times);

	friend RepeatedSequence operator *(int times, const Sequence &s);

	void getInvolvedMocks(std::vector<ActualInvocationsSource *> &into) const override;

	void getExpectedSequence(std::vector<Invocation::Matcher *> &into) const override;

	int getTimes() const;

	const Sequence &getSequence() const;
};


RepeatedSequence operator *(const Sequence &s, int times);

RepeatedSequence operator *(int times, const Sequence &s);


} // namespace fakeit
