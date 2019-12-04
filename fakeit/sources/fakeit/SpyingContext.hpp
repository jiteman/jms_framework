/*
 * SpyingContext.hpp
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Oct 20, 2014
 */
#pragma once


#include "fakeit/Xaction.h"
#include "Action.hpp"
#include "mockutils/type_utils.hpp"

#include <functional>


namespace fakeit {

// For use in Spy(...) phrases
    template<typename R, typename ... arglist>
    struct SpyingContext : Xaction {
        virtual void appendAction(Action<R, arglist...> *action) = 0;

        virtual std::function<R(arglist&...)> getOriginalMethod() = 0;
    };
}
