/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once

//#include "fakeit/StubbingImpl.hpp"
//#include "fakeit/StubbingProgress.hpp"
//#include "fakeit/Sequence.hpp"
//#include "fakeit/UsingFunctor.hpp"

#include "fakeit/VerifyNoOtherInvocationsVerificationProgress.h"
#include "fakeit/FakeitContext.h"
#include "fakeit/InvocationUtils.h"


namespace fakeit {


class VerifyNoOtherInvocationsFunctor {

	FakeitContext &_fakeit;

public:

	VerifyNoOtherInvocationsFunctor(FakeitContext &fakeit);

	void operator()();

	template<typename ... list>
	VerifyNoOtherInvocationsVerificationProgress operator()(const ActualInvocationsSource &head,
															const list &... tail) {
		std::vector<ActualInvocationsSource *> invocationSources{&InvocationUtils::remove_const(head),
																 &InvocationUtils::remove_const(tail)...};
		VerifyNoOtherInvocationsVerificationProgress progress{_fakeit, invocationSources};
		return progress;
	}

};


}
