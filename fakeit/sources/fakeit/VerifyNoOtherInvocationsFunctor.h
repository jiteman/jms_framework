/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once


#include "fakeit/VerifyNoOtherInvocationsVerificationProgress.h"
#include "fakeit/FakeitContext.h"
#include "fakeit/InvocationUtils.h"

#include <vector>

#include "fakeit_lib.h"


namespace fakeit {


class JMSD_FAKEIT_SHARED_INTERFACE VerifyNoOtherInvocationsFunctor {

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
