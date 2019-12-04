#pragma once

#include "FakeitContext.h"
#include "VerifyUnverifiedFunctor.h"


namespace fakeit {


class UnverifiedFunctor {
public:
	UnverifiedFunctor(FakeitContext &fakeit);

	VerifyUnverifiedFunctor Verify;

	template<typename ... list>
	UnverifiedInvocationsSource operator()(const ActualInvocationsSource &head, const list &... tail) {
		std::vector<ActualInvocationsSource *> allMocks{&InvocationUtils::remove_const(head),
														&InvocationUtils::remove_const(tail)...};
		InvocationsSourceProxy aggregateInvocationsSource{new AggregateInvocationsSource(allMocks)};
		UnverifiedInvocationsSource unverifiedInvocationsSource{aggregateInvocationsSource};
		return unverifiedInvocationsSource;
	}

//	template<typename ... list>
//	void operator()(const Sequence &sequence, const list &... tail) {
//		std::vector<Sequence *> allSequences;
//		collectSequences(allSequences, sequence, tail...);

//		std::vector<ActualInvocationsSource *> involvedSources;
//		collectInvolvedMocks(allSequences, involvedSources);

//		InvocationsSourceProxy aggregateInvocationsSource{new AggregateInvocationsSource(involvedSources)};
//		InvocationsSourceProxy unverifiedInvocationsSource{new UnverifiedInvocationsSource(aggregateInvocationsSource)};
//	}
};


} // namespace fakeit
