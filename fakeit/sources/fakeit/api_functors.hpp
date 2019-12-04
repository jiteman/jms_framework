#pragma once

#include "fakeit/UsingFunctor.hpp"
//#include "fakeit/VerifyFunctor.hpp"
#include "fakeit/VerifyNoOtherInvocationsFunctor.h"
#include "fakeit/SpyFunctor.hpp"
#include "fakeit/FakeFunctor.hpp"
#include "fakeit/WhenFunctor.h"
//#include "fakeit/UnverifiedFunctor.hpp"

#include "fakeit/VerifyFunctor.h"
#include "fakeit/UnverifiedFunctor.h"


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
