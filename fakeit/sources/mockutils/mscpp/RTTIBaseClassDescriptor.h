#pragma once

#include "PMD.h"
#include "mscpp_types.h"

#include <typeinfo>


namespace fakeit {


struct RTTIBaseClassDescriptor {
	RTTIBaseClassDescriptor();

	const std::type_info *pTypeDescriptor; //type descriptor of the class
	dword_ numContainedBases; //number of nested classes following in the Base Class Array
	PMD where;        //pointer-to-member displacement info
	dword_ attributes;        //flags, usually 0
};


} // namespace fakeit
