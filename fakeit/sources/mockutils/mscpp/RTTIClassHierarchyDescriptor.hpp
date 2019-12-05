#pragma once

#include "RTTIBaseClassDescriptor.h"


namespace fakeit {


template<typename C, typename... baseclasses>
struct RTTIClassHierarchyDescriptor {
	RTTIClassHierarchyDescriptor() :
			signature(0),
			attributes(0),
			numBaseClasses(0),
			pBaseClassArray(nullptr) {
		pBaseClassArray = new RTTIBaseClassDescriptor *[1 + sizeof...(baseclasses)];
		addBaseClass < C, baseclasses...>();
	}

	~RTTIClassHierarchyDescriptor() {
		for (int i = 0; i < 1 + sizeof...(baseclasses); i++) {
			RTTIBaseClassDescriptor *desc = pBaseClassArray[i];
			delete desc;
		}
		delete[] pBaseClassArray;
	}

	dword_ signature;      //always zero?
	dword_ attributes;     //bit 0 set = multiple inheritance, bit 1 set = virtual inheritance
	dword_ numBaseClasses; //number of classes in pBaseClassArray
	RTTIBaseClassDescriptor **pBaseClassArray;

	template<typename BaseType>
	void addBaseClass() {
		static_assert(std::is_base_of<BaseType, C>::value, "C must be a derived class of BaseType");
		RTTIBaseClassDescriptor *desc = new RTTIBaseClassDescriptor();
		desc->pTypeDescriptor = &typeid(BaseType);
		pBaseClassArray[numBaseClasses] = desc;
		for (unsigned int i = 0; i < numBaseClasses; i++) {
			pBaseClassArray[i]->numContainedBases++;
		}
		numBaseClasses++;
	}

	template<typename head, typename B1, typename... tail>
	void addBaseClass() {
		static_assert(std::is_base_of<B1, head>::value, "invalid inheritance list");
		addBaseClass<head>();
		addBaseClass<B1, tail...>();
	}

};


} // namespace fakeit
