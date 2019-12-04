#pragma once


#include "mockutils/Macros.hpp"


namespace fakeit {


struct FakeitContext;

template<typename C>
struct MockObject {
	virtual ~MockObject() THROWS
	{}

	virtual C &get() = 0;

	virtual FakeitContext &getFakeIt() = 0;
};


} // namespace fakeit
