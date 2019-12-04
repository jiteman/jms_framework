#include "ThrowFalseEventHandler.h"


namespace fakeit {


void ThrowFalseEventHandler::handle(const SequenceVerificationEvent &) {
	throw false;
}

void ThrowFalseEventHandler::handle(const NoMoreInvocationsVerificationEvent &) {
	throw false;
}


}
