#pragma once

#include "fakeit/Invocation.hpp"
#include "VerificationEvent.h"

#include <vector>


namespace fakeit {


struct NoMoreInvocationsVerificationEvent : public VerificationEvent {

	~NoMoreInvocationsVerificationEvent() = default;
	NoMoreInvocationsVerificationEvent( std::vector<Invocation *> &allTheIvocations, std::vector<Invocation *> &anUnverifedIvocations);
	const std::vector<Invocation *> &allIvocations() const;
	const std::vector<Invocation *> &unverifedIvocations() const ;

private:
	const std::vector<Invocation *> _allIvocations;
	const std::vector<Invocation *> _unverifedIvocations;
};


} // namespace fakeit
