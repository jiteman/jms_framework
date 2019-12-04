#include "Finally.h"


namespace fakeit {

	Finally::Finally(std::function<void()> f) :
			_finallyClause(f)
	{}

	Finally::~Finally() {
		_finallyClause();
	}

}
