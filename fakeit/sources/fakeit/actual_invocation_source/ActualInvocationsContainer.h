#pragma once


#include "mockutils/Macros.hpp"


namespace fakeit {


struct ActualInvocationsContainer {
	virtual void clear() = 0;

	virtual ~ActualInvocationsContainer() NO_THROWS;
};


} // namespace fakeit
