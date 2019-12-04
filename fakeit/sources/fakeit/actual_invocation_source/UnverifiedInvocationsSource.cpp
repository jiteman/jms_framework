#include "UnverifiedInvocationsSource.h"

#include "fakeit/Invocation.h"


namespace fakeit {


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


} // namespace fakeit

