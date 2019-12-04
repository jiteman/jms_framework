#include "DefaultFakeit.h"


namespace fakeit {


DefaultFakeit::DefaultFakeit()
	:
		_formatter(),
		_customFormatter(nullptr),
		_testingFrameworkAdapter(nullptr)
{}

void DefaultFakeit::setCustomEventFormatter(fakeit::EventFormatter &customEventFormatter) {
	_customFormatter = &customEventFormatter;
}

void DefaultFakeit::resetCustomEventFormatter() {
	_customFormatter = nullptr;
}

void DefaultFakeit::setTestingFrameworkAdapter(fakeit::EventHandler &testingFrameforkAdapter) {
	_testingFrameworkAdapter = &testingFrameforkAdapter;
}

void DefaultFakeit::resetTestingFrameworkAdapter() {
	_testingFrameworkAdapter = nullptr;
}

fakeit::EventHandler &DefaultFakeit::getTestingFrameworkAdapter() {
	if (_testingFrameworkAdapter) {
		return *_testingFrameworkAdapter;
	}

	return accessTestingFrameworkAdapter();
}

EventFormatter &DefaultFakeit::getEventFormatter() {
	if (_customFormatter) {
		return *_customFormatter;
	}

	return accessEventFormatter();
}

EventFormatter &DefaultFakeit::accessEventFormatter() {
	return _formatter;
}


}
