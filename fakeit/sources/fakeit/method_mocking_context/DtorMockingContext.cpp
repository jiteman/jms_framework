#include "DtorMockingContext.h"


namespace fakeit {


DtorMockingContext::DtorMockingContext(MethodMockingContext<void>::Context *stubbingContext)
	:
		MethodMockingContext<void>(stubbingContext)
{}

DtorMockingContext::DtorMockingContext(DtorMockingContext &other)
	:
		MethodMockingContext<void>(other)
{}

DtorMockingContext::DtorMockingContext(DtorMockingContext &&other)
	:
	  MethodMockingContext<void>( std::move(other))
{}

void DtorMockingContext::operator=(std::function<void()> method) {
	MethodMockingContext<void>::setMethodBodyByAssignment(method);
}

DtorMockingContext &DtorMockingContext::setMethodDetails(std::string mockName, std::string methodName) {
	MethodMockingContext<void>::setMethodDetails(mockName, methodName);
	return *this;
}


} // namespace fakeit

