#pragma once

#include "ActualInvocationsSource.h"

#include "InvocationsSourceProxy.h"

#include <unordered_set>

#include "fakeit_lib.h"


namespace fakeit {


struct JMSD_FAKEIT_SHARED_INTERFACE UnverifiedInvocationsSource : public ActualInvocationsSource {

	UnverifiedInvocationsSource(InvocationsSourceProxy decorated);

	void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const override;

private:
	InvocationsSourceProxy _decorated;
};


} // namespace fakeit
