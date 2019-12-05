/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once


#include "fakeit/InvocationUtils.h"
#include "fakeit/FakeitContext.h"
#include "fakeit/UsingProgress.h"

#include "fakeit/actual_invocation_source/AggregateInvocationsSource.h"

#include <vector>

#include "fakeit_lib.h"


namespace fakeit {

    class JMSD_FAKEIT_SHARED_INTERFACE UsingFunctor {

        friend class VerifyFunctor;

        FakeitContext &_fakeit;

    public:

        UsingFunctor(FakeitContext &fakeit);
        template<typename ... list>
        UsingProgress operator()(const ActualInvocationsSource &head, const list &... tail) {
            std::vector<ActualInvocationsSource *> allMocks{&InvocationUtils::remove_const(head),
                                                            &InvocationUtils::remove_const(tail)...};
            InvocationsSourceProxy aggregateInvocationsSource{new AggregateInvocationsSource(allMocks)};
            UsingProgress progress(_fakeit, aggregateInvocationsSource);
            return progress;
        }

    };
}
