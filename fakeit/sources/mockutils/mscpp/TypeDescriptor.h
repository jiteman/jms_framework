#pragma once

#include "mscpp_types.h"


namespace fakeit {


struct TypeDescriptor {
	TypeDescriptor();

	char *ptrToVTable;
	dword_ spare;
	char name[8];
};


} // namespace fakeit
