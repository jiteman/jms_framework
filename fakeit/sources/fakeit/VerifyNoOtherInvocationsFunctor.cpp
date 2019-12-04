#include "VerifyNoOtherInvocationsFunctor.h"


namespace fakeit {


VerifyNoOtherInvocationsFunctor::VerifyNoOtherInvocationsFunctor(FakeitContext &fakeit)
	:
		_fakeit(fakeit)
{}

void VerifyNoOtherInvocationsFunctor::operator()()
{}


}
