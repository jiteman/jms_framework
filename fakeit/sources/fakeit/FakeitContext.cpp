#include "FakeitContext.h"

#ifdef FAKEIT_ASSERT_ON_UNEXPECTED_METHOD_INVOCATION
#include <cassert>
#endif

namespace fakeit {


void FakeitContext::handle(const UnexpectedMethodCallEvent &e) {
	fireEvent(e);
	auto &eh = getTestingFrameworkAdapter();
	#ifdef FAKEIT_ASSERT_ON_UNEXPECTED_METHOD_INVOCATION
	assert(!"Unexpected method invocation");
	#endif
	eh.handle(e);
}

void FakeitContext::handle(const SequenceVerificationEvent &e) {
	fireEvent(e);
	auto &eh = getTestingFrameworkAdapter();
	return eh.handle(e);
}

void FakeitContext::handle(const NoMoreInvocationsVerificationEvent &e) {
	fireEvent(e);
	auto &eh = getTestingFrameworkAdapter();
	return eh.handle(e);
}

std::string FakeitContext::format(const UnexpectedMethodCallEvent &e) {
	auto &eventFormatter = getEventFormatter();
	return eventFormatter.format(e);
}

std::string FakeitContext::format(const SequenceVerificationEvent &e) {
	auto &eventFormatter = getEventFormatter();
	return eventFormatter.format(e);
}

std::string FakeitContext::format(const NoMoreInvocationsVerificationEvent &e) {
	auto &eventFormatter = getEventFormatter();
	return eventFormatter.format(e);
}

void FakeitContext::addEventHandler(EventHandler &eventListener) {
	_eventListeners.push_back(&eventListener);
}

void FakeitContext::clearEventHandlers() {
	_eventListeners.clear();
}

void FakeitContext::fireEvent(const NoMoreInvocationsVerificationEvent &evt) {
	for (auto listener : _eventListeners) {
		listener->handle(evt);
	}
}

void FakeitContext::fireEvent(const UnexpectedMethodCallEvent &evt) {
	for (auto listener : _eventListeners) {
		listener->handle(evt);
	}
}

void FakeitContext::fireEvent(const SequenceVerificationEvent &evt) {
	for (auto listener : _eventListeners) {
		listener->handle(evt);
	}
}


}
