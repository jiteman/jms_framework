/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */

#pragma once

#include <vector>
#include "fakeit/EventHandler.h"
#include "fakeit/EventFormatter.h"


namespace fakeit {

    struct FakeitContext : public EventHandler, protected EventFormatter {

        virtual ~FakeitContext() = default;
        void handle(const UnexpectedMethodCallEvent &e) override;
        void handle(const SequenceVerificationEvent &e) override;
        void handle(const NoMoreInvocationsVerificationEvent &e) override;
        std::string format(const UnexpectedMethodCallEvent &e) override;
        std::string format(const SequenceVerificationEvent &e) override;
        std::string format(const NoMoreInvocationsVerificationEvent &e) override;
        void addEventHandler(EventHandler &eventListener);
        void clearEventHandlers();

    protected:
        virtual EventHandler &getTestingFrameworkAdapter() = 0;
        virtual EventFormatter &getEventFormatter() = 0;

    private:
        std::vector<EventHandler *> _eventListeners;

        void fireEvent(const NoMoreInvocationsVerificationEvent &evt);
        void fireEvent(const UnexpectedMethodCallEvent &evt);
        void fireEvent(const SequenceVerificationEvent &evt);

    };

}
