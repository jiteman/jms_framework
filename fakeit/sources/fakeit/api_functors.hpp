#pragma once


#include "fakeit/SpyFunctor.hpp"
#include "fakeit/FakeFunctor.hpp"
//#include "fakeit/UnverifiedFunctor.hpp"

#include "fakeit/VerifyFunctor.h"
#include "fakeit/UnverifiedFunctor.h"
#include "fakeit/UsingFunctor.h"
#include "fakeit/VerifyNoOtherInvocationsFunctor.h"
#include "fakeit/WhenFunctor.h"


namespace fakeit {

    static UsingFunctor Using(Fakeit);
    static VerifyFunctor Verify(Fakeit);
    static VerifyNoOtherInvocationsFunctor VerifyNoOtherInvocations(Fakeit);
    static UnverifiedFunctor Unverified(Fakeit);
    static SpyFunctor Spy;
    static FakeFunctor Fake;
    static WhenFunctor When;

    template<class T>
    class SilenceUnusedVariableWarnings {

        void use(void *) {
        }

        SilenceUnusedVariableWarnings() {
            use(&Fake);
            use(&When);
            use(&Spy);
            use(&Using);
            use(&Verify);
            use(&VerifyNoOtherInvocations);
            use(&_any_);
        }
    };

}
