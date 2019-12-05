#pragma once


#include <string>

#include "fakeit_lib.h"


namespace fakeit {


struct JMSD_FAKEIT_SHARED_INTERFACE MethodInfo {

	static unsigned int nextMethodOrdinal();
	MethodInfo(unsigned int anId, std::string aName);
	unsigned int id() const;
	std::string name() const;
	void setName(const std::string &value);

private:
	unsigned int _id;
	std::string _name;
};


} // namespace fakeit
