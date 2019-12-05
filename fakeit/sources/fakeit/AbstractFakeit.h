#pragma once

#include "fakeit/FakeitContext.h"

#include "fakeit_lib.h"


namespace fakeit {


class JMSD_FAKEIT_SHARED_INTERFACE AbstractFakeit : public FakeitContext {
public:
	virtual ~AbstractFakeit() = default;

protected:

	virtual fakeit::EventHandler &accessTestingFrameworkAdapter() = 0;

	virtual EventFormatter &accessEventFormatter() = 0;
};


} // namespace fakeit
