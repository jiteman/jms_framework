#pragma once

#include "FakeitContext.h"
#include "SequenceVerificationProgress.hpp"
#include "fakeit/actual_invocation_source/AggregateInvocationsSource.h"
#include "fakeit/actual_invocation_source/UnverifiedInvocationsSource.h"
#include "UsingProgress.hpp"


namespace fakeit {


class VerifyUnverifiedFunctor {

	FakeitContext &_fakeit;

public:

	VerifyUnverifiedFunctor(FakeitContext &fakeit);

	template<typename ... list>
	SequenceVerificationProgress operator()(const Sequence &sequence, const list &... tail) {
		std::vector<Sequence *> allSequences{&InvocationUtils::remove_const(sequence),
											 &InvocationUtils::remove_const(tail)...};

		std::vector<ActualInvocationsSource *> involvedSources;
		InvocationUtils::collectInvolvedMocks(allSequences, involvedSources);

		InvocationsSourceProxy aggregateInvocationsSource{new AggregateInvocationsSource(involvedSources)};
		InvocationsSourceProxy unverifiedInvocationsSource{
				new UnverifiedInvocationsSource(aggregateInvocationsSource)};

		UsingProgress usingProgress(_fakeit, unverifiedInvocationsSource);
		return usingProgress.Verify(sequence, tail...);
	}

};


} // namespace fakeit
