#pragma once


#include "fakeit_lib.h"


namespace fakeit {


struct JMSD_FAKEIT_SHARED_INTERFACE VirtualTableBase {

	static VirtualTableBase &getVTable(void *instance);

	VirtualTableBase(void **firstMethod);

	void *getCookie(int index);
	void setCookie(int index, void *value);
	void *getMethod(unsigned int index) const;
	void setMethod(unsigned int index, void *method);

protected:
	void **_firstMethod;
};


} // namespace fakeit
