/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once

#include "fakeit/StubbingProgress.hpp"
#include "fakeit/StubbingContext.hpp"

#include "Xaction.h"
#include "fakeit/fakeit_exceptions/UncaughtException.h"
#include "mockutils/smart_ptr.hpp"
#include "mockutils/Macros.hpp"

#include "fakeit_lib.h"


namespace fakeit {


class JMSD_FAKEIT_SHARED_INTERFACE WhenFunctor {

	struct JMSD_FAKEIT_SHARED_INTERFACE StubbingChange {

		friend class WhenFunctor;

		virtual ~StubbingChange() THROWS;
		StubbingChange(StubbingChange &other);

	private:
		StubbingChange(Xaction &xaction);

		Xaction &_xaction;
	};

public:

	template<typename R, typename ... arglist>
	struct MethodProgress : MethodStubbingProgress<R, arglist...> {

		friend class WhenFunctor;

		virtual ~MethodProgress() override = default;

		MethodProgress(MethodProgress &other)
			:
				_progress(other._progress),
				_context(other._context)
		{}

		MethodProgress(StubbingContext<R, arglist...> &xaction)
			:
				_progress(new StubbingChange(xaction)),
				_context(xaction)
		{}

	protected:

		virtual MethodStubbingProgress<R, arglist...> &DoImpl(Action<R, arglist...> *action) override {
			_context.appendAction(action);
			return *this;
		}

	private:
		smart_ptr<StubbingChange> _progress;
		StubbingContext<R, arglist...> &_context;
	};


	WhenFunctor();

	template<typename R, typename ... arglist>
	MethodProgress<R, arglist...> operator()(const StubbingContext<R, arglist...> &stubbingContext) {
		StubbingContext<R, arglist...> &rootWithoutConst = const_cast<StubbingContext<R, arglist...> &>(stubbingContext);
		MethodProgress<R, arglist...> progress(rootWithoutConst);
		return progress;
	}

};


}
