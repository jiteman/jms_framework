/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on August, 2014
 */
#pragma once


#include "fakeit/EventFormatter.hpp"
#include "fakeit/Sequence.hpp"
#include "fakeit/FakeitEvents.hpp"

#include <vector>


namespace fakeit {

    struct DefaultEventFormatter : public EventFormatter {

        virtual std::string format(const UnexpectedMethodCallEvent &e) override;

        /*
         test file:1: Verification error\n
         Expected pattern: mock.all_types( 'a', true, 1, 1, 1, 1, 1, 1, 1.0, 1.0 )
         Expected matches: exactly 2
         Actual matches  : 0
         Actual sequence : no actual invocations
         */
        virtual std::string format(const SequenceVerificationEvent &e) override;

        virtual std::string format(const NoMoreInvocationsVerificationEvent &e) override;

        static std::string formatExpectedPattern(const std::vector<fakeit::Sequence *> &expectedPattern);

    private:
        static std::string formatSequence(const Sequence &val);
        static void formatExpectedCount(std::ostream &out, fakeit::VerificationType verificationType, int expectedCount);
        static void formatInvocationList(std::ostream &out, const std::vector<fakeit::Invocation *> &actualSequence);
        static std::string format(const ConcatenatedSequence &val);
        static std::string format(const RepeatedSequence &val);
    };
}
