/*
 * Finally.hpp
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Aug 30, 2014
 */
#pragma once

#include <functional>

#include "fakeit_lib.h"


namespace fakeit {


class JMSD_FAKEIT_SHARED_INTERFACE Finally {
private:
	std::function<void()> _finallyClause;

	Finally(const Finally &);

	Finally &operator=(const Finally &);

public:
	explicit Finally(std::function<void()> f);

	~Finally();
};


}
