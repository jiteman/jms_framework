#include "UsingProgress.h"


namespace fakeit {


void UsingProgress::collectSequences(std::vector<fakeit::Sequence *> &)
{}

UsingProgress::UsingProgress(fakeit::FakeitContext &fakeit, InvocationsSourceProxy source)
	:
		_fakeit(fakeit),
		_sources(source)
{}


}
