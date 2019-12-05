#pragma once


namespace fakeit {


struct PMD {

	/************************************************************************/
	/* member displacement.
	/* For a simple inheritance structure the member displacement is always 0.
	/* since since the first member is placed at 0.
	/* In the case of multiple inheritance, this value may have a positive value.
	/************************************************************************/
	int mdisp;

	int pdisp;  // vtable displacement
	int vdisp;  //displacement inside vtable

	PMD();

};


} // namespace fakeit
