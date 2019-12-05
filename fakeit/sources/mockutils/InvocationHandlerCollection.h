#pragma once


#include "Destructible.h"


#include "fakeit_lib.h"


namespace fakeit {


struct JMSD_FAKEIT_SHARED_INTERFACE InvocationHandlerCollection {
	static const unsigned int VT_COOKIE_INDEX = 0;

	virtual Destructible *getInvocatoinHandlerPtrById(unsigned int index) = 0;

	static InvocationHandlerCollection *getInvocationHandlerCollection(void *instance);
};


} // namespace fakeit
