#pragma once

#include "MethodMockingContext.hpp"

#include <string>
#include <functional>

#include "fakeit_lib.h"


namespace fakeit {


class JMSD_FAKEIT_SHARED_INTERFACE DtorMockingContext : public MethodMockingContext<void> {
public:

	DtorMockingContext(MethodMockingContext<void>::Context *stubbingContext);
	DtorMockingContext(DtorMockingContext &other);
	DtorMockingContext(DtorMockingContext &&other);
	void operator=(std::function<void()> method);
	DtorMockingContext &setMethodDetails(std::string mockName, std::string methodName);
};


} // namespace fakeit
