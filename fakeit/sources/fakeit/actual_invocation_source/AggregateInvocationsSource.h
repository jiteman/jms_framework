#pragma once

#include "ActualInvocationsSource.h"

#include <vector>


namespace fakeit {


struct AggregateInvocationsSource : public ActualInvocationsSource {

	AggregateInvocationsSource(std::vector<ActualInvocationsSource *> &sources);

	void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const override;

protected:
	bool shouldInclude(fakeit::Invocation *) const;

private:
	std::vector<ActualInvocationsSource *> _sources;

	void filter(std::unordered_set<Invocation *> &source, std::unordered_set<Invocation *> &target) const;
};


} // namespace fakeit
