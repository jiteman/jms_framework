#include "InvocationUtils.h"

#include "fakeit/actual_invocation_source/ActualInvocationsSource.h"
#include "Invocation.h"
#include "Sequence.hpp"


#include <set>


namespace fakeit {


// static
void InvocationUtils::sortByInvocationOrder(std::unordered_set<Invocation *> &ivocations, std::vector<Invocation *> &result) {
	auto comparator = [](Invocation *a, Invocation *b) -> bool {
		return a->getOrdinal() < b->getOrdinal();
	};

	std::set<Invocation *, bool (*)(Invocation *a, Invocation *b)> sortedIvocations(comparator);

	for (auto i : ivocations) {
		sortedIvocations.insert(i);
	}

	for (auto i : sortedIvocations) {
		result.push_back(i);
	}
}

// static
void InvocationUtils::collectActualInvocations(std::unordered_set<Invocation *> &actualInvocations, std::vector<ActualInvocationsSource *> &invocationSources) {
	for (auto source : invocationSources) {
		source->getActualInvocations(actualInvocations);
	}
}

// static
void InvocationUtils::selectNonVerifiedInvocations(std::unordered_set<Invocation *> &actualInvocations, std::unordered_set<Invocation *> &into) {
	for (auto invocation : actualInvocations) {
		if (!invocation->isVerified()) {
			into.insert(invocation);
		}
	}
}

// static
void InvocationUtils::collectInvocationSources(std::vector<ActualInvocationsSource *> &)
{}

// static
void InvocationUtils::collectSequences(std::vector<Sequence *> &)
{}

// static
void InvocationUtils::collectInvolvedMocks(std::vector<Sequence *> &allSequences, std::vector<ActualInvocationsSource *> &involvedMocks) {
	for (auto sequence : allSequences) {
		sequence->getInvolvedMocks(involvedMocks);
	}
}


}
