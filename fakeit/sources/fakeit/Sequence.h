#pragma once

#include "Invocation.h"
#include "mockutils/Macros.hpp"

#include <vector>


namespace fakeit {


struct ActualInvocationsSource;


class Sequence {
private:

protected:

	Sequence();

	virtual ~Sequence() THROWS;
public:

	/**
	 * Fetch the matchers that make-up this sequence.
	 */
	virtual void getExpectedSequence(std::vector<Invocation::Matcher *> &into) const = 0;

	/**
	 * Collect all mock objects that are involved in this sequence.
	 */
	virtual void getInvolvedMocks(std::vector<ActualInvocationsSource *> &into) const = 0;

	virtual unsigned int size() const = 0;

	friend class VerifyFunctor;
};


} // namespace fakeit