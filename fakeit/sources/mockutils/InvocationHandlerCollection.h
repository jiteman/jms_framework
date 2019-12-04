#pragma once


#include "Destructible.h"


namespace fakeit {


struct InvocationHandlerCollection {
	static const unsigned int VT_COOKIE_INDEX = 0;

	virtual Destructible *getInvocatoinHandlerPtrById(unsigned int index) = 0;

	static InvocationHandlerCollection *getInvocationHandlerCollection(void *instance);
};


} // namespace fakeit
