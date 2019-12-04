#include "FakeitException.h"


namespace fakeit {


std::ostream &operator <<(std::ostream &os, const FakeitException &val) {
	os << val.what();
	return os;
}


} // namespace fakeit

