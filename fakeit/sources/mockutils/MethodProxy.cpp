#include "MethodProxy.h"

#include "mockutils/union_cast.hpp"


namespace fakeit {


	MethodProxy::MethodProxy(unsigned int id, unsigned int offset, void *vMethod) :
			_id(id),
			_offset(offset),
			_vMethod(vMethod) {
	}

	unsigned int MethodProxy::getOffset() const {
		return _offset;
	}

	unsigned int MethodProxy::getId() const {
		return _id;
	}

	void *MethodProxy::getProxy() const {
		return union_cast<void *>(_vMethod);
	}


}
