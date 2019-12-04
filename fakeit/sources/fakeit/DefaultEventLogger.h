/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once


#include "fakeit/EventHandler.hpp"
#include "fakeit/DefaultEventFormatter.h"
//#include "fakeit/FakeitExceptions.hpp"

namespace fakeit {

    struct DefaultEventLogger : public fakeit::EventHandler {

        DefaultEventLogger(EventFormatter &formatter);
        virtual void handle(const UnexpectedMethodCallEvent &e) override;
        virtual void handle(const SequenceVerificationEvent &e) override;
        virtual void handle(const NoMoreInvocationsVerificationEvent &e) override;

    private:
        EventFormatter &_formatter;
        std::ostream &_out;
    };

}
