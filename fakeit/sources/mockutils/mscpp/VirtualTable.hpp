#pragma once

#include "VirtualTableBase.h"

#include "RTTICompleteObjectLocator.hpp"


namespace fakeit {


template<class C, class... baseclasses>
struct VirtualTable : public VirtualTableBase {

	class Handle {

		friend struct VirtualTable<C, baseclasses...>;

		void **firstMethod;

		Handle(void **method) : firstMethod(method) { }

	public:

		VirtualTable<C, baseclasses...> &restore() {
			VirtualTable<C, baseclasses...> *vt = (VirtualTable<C, baseclasses...> *) this;
			return *vt;
		}
	};

	static VirtualTable<C, baseclasses...> &getVTable(C &instance) {
		fakeit::VirtualTable<C, baseclasses...> *vt = (fakeit::VirtualTable<C, baseclasses...> *) (&instance);
		return *vt;
	}

	void copyFrom(VirtualTable<C, baseclasses...> &from) {
		unsigned int size = VTUtils::getVTSize<C>();
		for (unsigned int i = 0; i < size; i++) {
			_firstMethod[i] = from.getMethod(i);
		}
	}

	VirtualTable() : VirtualTable(buildVTArray()) {
	}

	~VirtualTable() {

	}

	void dispose() {
		_firstMethod--; // skip objectLocator
		RTTICompleteObjectLocator<C, baseclasses...> *locator = (RTTICompleteObjectLocator<C, baseclasses...> *) _firstMethod[0];
		delete locator;
		_firstMethod -= numOfCookies; // skip cookies
		delete[] _firstMethod;
	}

	// the dtor VC++ must of the format: int dtor(int)
	unsigned int dtor(int) {
		C *c = (C *) this;
		C &cRef = *c;
		auto vt = VirtualTable<C, baseclasses...>::getVTable(cRef);
		void *dtorPtr = vt.getCookie(numOfCookies - 1); // read the last cookie
		void(*method)(C *) = reinterpret_cast<void (*)(C *)>(dtorPtr);
		method(c);
		return 0;
	}

	void setDtor(void *method) {
		// the dtor VC++ must of the format: int dtor(int).
		// the method passed by the user is: void dtor().
		// store the user method in a cookie and put the
		// correct format method in the virtual table.
		// the method stored in the vt will call the method in the cookie when invoked.
		void *dtorPtr = union_cast<void *>(&VirtualTable<C, baseclasses...>::dtor);
		unsigned int index = VTUtils::getDestructorOffset<C>();
		_firstMethod[index] = dtorPtr;
		setCookie(numOfCookies - 1, method); // use the last cookie
	}

	unsigned int getSize() {
		return VTUtils::getVTSize<C>();
	}

	void initAll(void *value) {
		auto size = getSize();
		for (unsigned int i = 0; i < size; i++) {
			setMethod(i, value);
		}
	}

	Handle createHandle() {
		Handle h(_firstMethod);
		return h;
	}

private:

	class SimpleType {
	};

	static_assert(sizeof(unsigned int (SimpleType::*)()) == sizeof(unsigned int (C::*)()),
		"Can't mock a type with multiple inheritance or with non-polymorphic base class");
	static const unsigned int numOfCookies = 3;

	static void **buildVTArray() {
		int vtSize = VTUtils::getVTSize<C>();
		auto array = new void *[vtSize + numOfCookies + 1]{};
		RTTICompleteObjectLocator<C, baseclasses...> *objectLocator = new RTTICompleteObjectLocator<C, baseclasses...>(
				typeid(C));
		array += numOfCookies; // skip cookies
		array[0] = objectLocator; // initialize RTTICompleteObjectLocator pointer
		array++; // skip object locator
		return array;
	}

	VirtualTable(void **firstMethod) : VirtualTableBase(firstMethod) {
	}
};


} // namespace fakeit
