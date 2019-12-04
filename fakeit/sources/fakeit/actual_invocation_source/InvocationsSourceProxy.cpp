#include "InvocationsSourceProxy.h"


namespace fakeit {


InvocationsSourceProxy::InvocationsSourceProxy(ActualInvocationsSource *inner) :
		_inner(inner) {
}

void InvocationsSourceProxy::getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const {
	_inner->getActualInvocations(into);
}



} // namespace fakeit

