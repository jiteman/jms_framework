#include "ActualInvocationsSource.h"


namespace fakeit {


	ActualInvocationsContainer::~ActualInvocationsContainer() NO_THROWS
	{}

	ActualInvocationsSource::~ActualInvocationsSource() NO_THROWS
	{}

	InvocationsSourceProxy::InvocationsSourceProxy(ActualInvocationsSource *inner) :
			_inner(inner) {
	}

	void InvocationsSourceProxy::getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const {
		_inner->getActualInvocations(into);
	}

	UnverifiedInvocationsSource::UnverifiedInvocationsSource(InvocationsSourceProxy decorated)
		: _decorated(decorated)
	{}

	void UnverifiedInvocationsSource::getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const {
		std::unordered_set<fakeit::Invocation *> all;
		_decorated.getActualInvocations(all);
		for (fakeit::Invocation *i : all) {
			if (!i->isVerified()) {
				into.insert(i);
			}
		}
	}

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


}
