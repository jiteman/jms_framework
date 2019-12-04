#include "InvocationHandlerCollection.h"

#include "VirtualTable.hpp"


namespace fakeit {


// static
InvocationHandlerCollection *InvocationHandlerCollection::getInvocationHandlerCollection(void *instance) {
	VirtualTableBase &vt = VirtualTableBase::getVTable(instance);
	InvocationHandlerCollection *invocationHandlerCollection = (InvocationHandlerCollection *) vt.getCookie(
			InvocationHandlerCollection::VT_COOKIE_INDEX);
	return invocationHandlerCollection;
}


} // namespace fakeit
