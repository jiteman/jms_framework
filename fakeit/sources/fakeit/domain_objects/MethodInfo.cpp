#include "MethodInfo.h"

#include <atomic>


namespace fakeit {


// static
unsigned int MethodInfo::nextMethodOrdinal() {
	static std::atomic_uint ordinal{0};
	return ++ordinal;
}

MethodInfo::MethodInfo(unsigned int anId, std::string aName)
	:
		_id(anId),
		_name(aName)
{}

unsigned int MethodInfo::id() const {
	return _id;
}

std::string MethodInfo::name() const {
	return _name;
}

void MethodInfo::setName(const std::string &value) {
	_name = value;
}


} // namespace fakeit
