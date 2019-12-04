#pragma once

#include <memory>
#include "mockutils/smart_ptr.hpp"
#include "mockutils/to_string.hpp"

#include "fakeit/SequenceVerificationExpectation.h"
#include "ThrowFalseEventHandler.h"
#include "Quantity.h"


namespace fakeit {

    struct FakeitContext;

    class SequenceVerificationProgress {

        friend class UsingFunctor;

        friend class VerifyFunctor;

        friend class UsingProgress;

        smart_ptr<SequenceVerificationExpectation> _expectationPtr;

        SequenceVerificationProgress(SequenceVerificationExpectation *ptr);

        SequenceVerificationProgress(
                FakeitContext &fakeit,
                InvocationsSourceProxy sources,
                std::vector<Sequence *> &allSequences);

        virtual void verifyInvocations(const int times);

        class Terminator {
            smart_ptr<SequenceVerificationExpectation> _expectationPtr;

            bool toBool();

        public:
            Terminator(smart_ptr<SequenceVerificationExpectation> expectationPtr);
            operator bool();
            bool operator!() const;
        };

    public:
        ~SequenceVerificationProgress() THROWS;
        operator bool() const;
        bool operator!() const;
        Terminator Never();
        Terminator Once();
        Terminator Twice();
        Terminator AtLeastOnce();
        Terminator Exactly(const int times);
        Terminator Exactly(const Quantity &q);
        Terminator AtLeast(const int times);
        Terminator AtLeast(const Quantity &q);
        SequenceVerificationProgress setFileInfo(const char * file, int line, const char * callingMethod);
    };
}
