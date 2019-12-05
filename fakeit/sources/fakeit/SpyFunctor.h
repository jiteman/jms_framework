/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once


#include "fakeit/SpyingContext.hpp"

#include "fakeit_lib.h"


namespace fakeit {


class JMSD_FAKEIT_SHARED_INTERFACE SpyFunctor {
private:

	template<typename R, typename ... arglist>
	void spy(const SpyingContext<R, arglist...> &root) {
		SpyingContext<R, arglist...> &rootWithoutConst = const_cast<SpyingContext<R, arglist...> &>(root);
		auto methodFromOriginalVT = rootWithoutConst.getOriginalMethod();
		rootWithoutConst.appendAction(new ReturnDelegateValue<R, arglist...>(methodFromOriginalVT));
		rootWithoutConst.commit();
	}

	void operator()();

public:

	template<typename H, typename ... M>
	void operator()(const H &head, const M &... tail) {
		spy(head);
		this->operator()(tail...);
	}

};


}
