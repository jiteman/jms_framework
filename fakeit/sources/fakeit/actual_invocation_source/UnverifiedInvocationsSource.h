#pragma once

#include "ActualInvocationsSource.h"

#include "InvocationsSourceProxy.h"

#include <unordered_set>


namespace fakeit {


struct UnverifiedInvocationsSource : public ActualInvocationsSource {

	UnverifiedInvocationsSource(InvocationsSourceProxy decorated);

	void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const override;

private:
	InvocationsSourceProxy _decorated;
};


} // namespace fakeit
