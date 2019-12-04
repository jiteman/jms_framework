#pragma once

#include "MethodMockingContext.hpp"

#include <string>
#include <functional>


namespace fakeit {


class DtorMockingContext : public MethodMockingContext<void> {
public:

	DtorMockingContext(MethodMockingContext<void>::Context *stubbingContext);
	DtorMockingContext(DtorMockingContext &other);
	DtorMockingContext(DtorMockingContext &&other);
	void operator=(std::function<void()> method);
	DtorMockingContext &setMethodDetails(std::string mockName, std::string methodName);
};


} // namespace fakeit
