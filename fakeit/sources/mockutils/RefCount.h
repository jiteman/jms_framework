#pragma once

#include "fakeit_lib.h"


namespace fakeit {


class JMSD_FAKEIT_SHARED_INTERFACE RefCount {
private:
	int count;

public:
	void AddRef();

	int Release();
};


} // namespace fakeit
