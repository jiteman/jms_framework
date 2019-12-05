#pragma once

#include "fakeit_lib.h"


namespace fakeit {


struct JMSD_FAKEIT_SHARED_INTERFACE Quantity {
	Quantity(const int q);

	const int quantity;
};


JMSD_FAKEIT_SHARED_INTERFACE extern Quantity _once_;


} // namespace fakeit
