#pragma once

#include "ActualInvocationsSource.h"

#include "InvocationsSourceProxy.h"


namespace fakeit {


struct UnverifiedInvocationsSource : public ActualInvocationsSource {

	UnverifiedInvocationsSource(InvocationsSourceProxy decorated);

	void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const override;

private:
	InvocationsSourceProxy _decorated;
};


} // namespace fakeit
