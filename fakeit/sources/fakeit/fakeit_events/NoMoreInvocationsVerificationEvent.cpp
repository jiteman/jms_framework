#include "NoMoreInvocationsVerificationEvent.h"


namespace fakeit {


NoMoreInvocationsVerificationEvent::NoMoreInvocationsVerificationEvent( std::vector<Invocation *> &allTheIvocations, std::vector<Invocation *> &anUnverifedIvocations)
	:
		VerificationEvent(VerificationType::NoMoreInvocations),
		_allIvocations(allTheIvocations),
		_unverifedIvocations(anUnverifedIvocations)
{}

const std::vector<Invocation *> &NoMoreInvocationsVerificationEvent::allIvocations() const {
	return _allIvocations;
}

const std::vector<Invocation *> &NoMoreInvocationsVerificationEvent::unverifedIvocations() const {
	return _unverifedIvocations;
}


} // namespace fakeit
