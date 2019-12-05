#include "TypeDescriptor.h"


namespace fakeit {


TypeDescriptor::TypeDescriptor()
	:
		ptrToVTable(0),
		spare(0)
{
	// ptrToVTable should contain the pointer to the virtual table of the type type_info!!!
	int **tiVFTPtr = (int **) (&typeid(void));
	int *i = (int *) tiVFTPtr[0];
	char *type_info_vft_ptr = (char *) i;
	ptrToVTable = type_info_vft_ptr;
}


} // namespace fakeit

