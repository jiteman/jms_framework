#include "RefCount.h"


namespace fakeit {


void RefCount::AddRef() {
	count++;
}

int RefCount::Release() {
	return --count;
}


} // namespace fakeit
