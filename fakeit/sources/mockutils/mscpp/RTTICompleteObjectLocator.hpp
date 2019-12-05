#pragma once

#include "mscpp_types.h"


namespace fakeit {


template<typename C, typename... baseclasses>
struct RTTICompleteObjectLocator {
#ifdef _WIN64
	RTTICompleteObjectLocator(const std::type_info &unused) :
		signature(0), offset(0), cdOffset(0),
		typeDescriptorOffset(0), classDescriptorOffset(0)
	{
				(void)unused;
	}

	dword_ signature; //always zero ?
	dword_ offset;    //offset of this vtable in the complete class
	dword_ cdOffset;  //constructor displacement offset
	dword_ typeDescriptorOffset;
	dword_ classDescriptorOffset;
#else
	RTTICompleteObjectLocator(const std::type_info &info) :
		signature(0), offset(0), cdOffset(0),
		pTypeDescriptor(&info),
		pClassDescriptor(new RTTIClassHierarchyDescriptor<C, baseclasses...>()) {
	}

	~RTTICompleteObjectLocator() {
		delete pClassDescriptor;
	}

	dword_ signature; //always zero ?
	dword_ offset;    //offset of this vtable in the complete class
	dword_ cdOffset;  //constructor displacement offset
	const std::type_info *pTypeDescriptor; //TypeDescriptor of the complete class
	struct RTTIClassHierarchyDescriptor<C, baseclasses...> *pClassDescriptor; //describes inheritance hierarchy
#endif
};


} // namespace fakeit
