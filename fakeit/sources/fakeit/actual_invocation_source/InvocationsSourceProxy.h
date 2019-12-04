#pragma once


#include "ActualInvocationsSource.h"

#include <memory>
#include <unordered_set>


namespace fakeit {


struct InvocationsSourceProxy : public ActualInvocationsSource {

	InvocationsSourceProxy(ActualInvocationsSource *inner);

	void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const override;

private:
	std::shared_ptr<ActualInvocationsSource> _inner;
};


} // namespace fakeit
