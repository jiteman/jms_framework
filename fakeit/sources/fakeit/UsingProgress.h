//
// Created by eran on 01/04/2015.
//
#pragma once

#include "fakeit/FakeitContext.h"
#include "fakeit/SequenceVerificationProgress.h"

#include <vector>

#include "fakeit_lib.h"


namespace fakeit {

    class JMSD_FAKEIT_SHARED_INTERFACE UsingProgress {
        fakeit::FakeitContext &_fakeit;
        InvocationsSourceProxy _sources;

        void collectSequences(std::vector<fakeit::Sequence *> &);

        template<typename ... list>
        void collectSequences(std::vector<fakeit::Sequence *> &vec, const fakeit::Sequence &sequence,
                              const list &... tail) {
            vec.push_back(&const_cast<fakeit::Sequence &>(sequence));
            collectSequences(vec, tail...);
        }

    public:

        UsingProgress(fakeit::FakeitContext &fakeit, InvocationsSourceProxy source);

        template<typename ... list>
        SequenceVerificationProgress Verify(const fakeit::Sequence &sequence, const list &... tail) {
            std::vector<fakeit::Sequence *> allSequences;
            collectSequences(allSequences, sequence, tail...);
            SequenceVerificationProgress progress(_fakeit, _sources, allSequences);
            return progress;
        }

    };
}
