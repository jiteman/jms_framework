//
// Created by eran on 11/04/2015.
//
#pragma once

#include "fakeit/EventHandler.h"

namespace fakeit {


class ThrowFalseEventHandler : public VerificationEventHandler {

	void handle(const SequenceVerificationEvent &) override;
	void handle(const NoMoreInvocationsVerificationEvent &) override;
};


}
