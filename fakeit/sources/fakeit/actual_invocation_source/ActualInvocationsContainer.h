#pragma once


#include "mockutils/Macros.hpp"

#include "fakeit_lib.h"


namespace fakeit {


struct JMSD_FAKEIT_SHARED_INTERFACE ActualInvocationsContainer {
	virtual void clear() = 0;

	virtual ~ActualInvocationsContainer() NO_THROWS;
};


} // namespace fakeit
