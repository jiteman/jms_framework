#include "AggregateInvocationsSource.h"


namespace fakeit {


AggregateInvocationsSource::AggregateInvocationsSource(std::vector<ActualInvocationsSource *> &sources)
	: _sources(sources)
{}

void AggregateInvocationsSource::getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const {
	std::unordered_set<fakeit::Invocation *> tmp;
	for (ActualInvocationsSource *source : _sources) {
		source->getActualInvocations(tmp);
	}
	filter(tmp, into);
}

bool AggregateInvocationsSource::shouldInclude(fakeit::Invocation *) const {
	return true;
}

void AggregateInvocationsSource::filter(std::unordered_set<Invocation *> &source, std::unordered_set<Invocation *> &target) const {
	for (Invocation *i:source) {
		if (shouldInclude(i)) {
			target.insert(i);
		}
	}
}


} // namespace fakeit

