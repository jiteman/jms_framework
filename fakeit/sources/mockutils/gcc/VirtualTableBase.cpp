#include "VirtualTableBase.h"


namespace fakeit {

	// static
	VirtualTableBase &VirtualTableBase::getVTable(void *instance) {
		fakeit::VirtualTableBase *vt = (fakeit::VirtualTableBase *) (instance);
		return *vt;
	}

	VirtualTableBase::VirtualTableBase(void **firstMethod) : _firstMethod(firstMethod) { }

	void *VirtualTableBase::getCookie(int index) {
		return _firstMethod[-3 - index];
	}

	void VirtualTableBase::setCookie(int index, void *value) {
		_firstMethod[-3 - index] = value;
	}

	void *VirtualTableBase::getMethod(unsigned int index) const {
		return _firstMethod[index];
	}

	void VirtualTableBase::setMethod(unsigned int index, void *method) {
		_firstMethod[index] = method;
	}
 }
