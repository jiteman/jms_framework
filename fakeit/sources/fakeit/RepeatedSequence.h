#pragma once

#include "Sequence.h"

#include <vector>

#include "fakeit_lib.h"


namespace fakeit {


class JMSD_FAKEIT_SHARED_INTERFACE RepeatedSequence : public virtual Sequence {
private:
	const Sequence &_s;
	const int times;

protected:
	RepeatedSequence(const Sequence &s, const int t);

public:

	~RepeatedSequence();

	unsigned int size() const override ;

	friend JMSD_FAKEIT_SHARED_INTERFACE RepeatedSequence operator *(const Sequence &s, int times);

	friend JMSD_FAKEIT_SHARED_INTERFACE RepeatedSequence operator *(int times, const Sequence &s);

	void getInvolvedMocks(std::vector<ActualInvocationsSource *> &into) const override;

	void getExpectedSequence(std::vector<Invocation::Matcher *> &into) const override;

	int getTimes() const;

	const Sequence &getSequence() const;
};


JMSD_FAKEIT_SHARED_INTERFACE RepeatedSequence operator *(const Sequence &s, int times);

JMSD_FAKEIT_SHARED_INTERFACE RepeatedSequence operator *(int times, const Sequence &s);


} // namespace fakeit
