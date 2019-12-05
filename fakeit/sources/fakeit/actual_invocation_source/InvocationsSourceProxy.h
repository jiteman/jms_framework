#pragma once


#include "ActualInvocationsSource.h"

#include <memory>
#include <unordered_set>

#include "fakeit_lib.h"


namespace fakeit {


struct JMSD_FAKEIT_SHARED_INTERFACE InvocationsSourceProxy : public ActualInvocationsSource {

	InvocationsSourceProxy(ActualInvocationsSource *inner);

	void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const override;

private:
	std::shared_ptr<ActualInvocationsSource> _inner;
};


} // namespace fakeit
