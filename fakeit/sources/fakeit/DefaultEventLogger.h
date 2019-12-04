/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once


#include "fakeit/EventHandler.h"
#include "fakeit/DefaultEventFormatter.h"

#include <ostream>


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
