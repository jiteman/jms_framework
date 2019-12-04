#pragma once

#include "fakeit/FakeitContext.h"


namespace fakeit {


class AbstractFakeit : public FakeitContext {
public:
	virtual ~AbstractFakeit() = default;

protected:

	virtual fakeit::EventHandler &accessTestingFrameworkAdapter() = 0;

	virtual EventFormatter &accessEventFormatter() = 0;
};


} // namespace fakeit
