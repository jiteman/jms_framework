/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once


#include "mockutils/Destructible.h"
#include "fakeit/domain_objects/MethodInfo.h"

#include "mockutils/Macros.hpp"

#include <string>

#include "fakeit_lib.h"


namespace fakeit {

    struct JMSD_FAKEIT_SHARED_INTERFACE Invocation : Destructible {

        static unsigned int nextInvocationOrdinal();

        struct JMSD_FAKEIT_SHARED_INTERFACE Matcher {

            virtual ~Matcher() THROWS;

            virtual bool matches(Invocation &invocation) = 0;

            virtual std::string format() const = 0;
        };

        Invocation(unsigned int ordinal, MethodInfo &method);
        virtual ~Invocation() override = default;
        unsigned int getOrdinal() const;
        MethodInfo &getMethod() const ;
        void markAsVerified();
        bool isVerified() const;

        virtual std::string format() const = 0;

    private:
        const unsigned int _ordinal;
        MethodInfo &_method;
        bool _isVerified;
    };

}
