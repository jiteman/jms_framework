#include "WhenFunctor.h"


namespace fakeit {


WhenFunctor::StubbingChange::~StubbingChange() THROWS {
	if (UncaughtException()) {
		return;
	}

	_xaction.commit();
}

WhenFunctor::StubbingChange::StubbingChange(StubbingChange &other)
	:
		_xaction(other._xaction)
{}


WhenFunctor::StubbingChange::StubbingChange(Xaction &xaction)
	:
		_xaction(xaction)
{}

WhenFunctor::WhenFunctor()
{}


}
