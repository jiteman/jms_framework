#pragma once

//#include "mockutils/smart_ptr.hpp"
////#include "fakeit/FakeitExceptions.hpp"
//#include "fakeit/InvocationUtils.h"
////#include "fakeit/MatchAnalysis.hpp"

//#include "FakeitContext.h"
//#include "fakeit/actual_invocation_source/InvocationsSourceProxy.h"
//#include "MatchAnalysis.h"
//#include "fakeit/fakeit_exceptions/UncaughtException.h"

#include "EventHandler.h"
#include "fakeit/actual_invocation_source/InvocationsSourceProxy.h"
#include "MatchAnalysis.h"
#include "mockutils/Macros.hpp"

#include <vector>

namespace fakeit {


class Sequence;


struct SequenceVerificationExpectation {

	friend class SequenceVerificationProgress;

	~SequenceVerificationExpectation() THROWS;

	void setExpectedPattern(std::vector<Sequence *> expectedPattern);

	void setExpectedCount(const int count);

	void setFileInfo(const char * file, int line, const char * callingMethod);

private:

	VerificationEventHandler &_fakeit;
	InvocationsSourceProxy _involvedInvocationSources;
	std::vector<Sequence *> _expectedPattern;
	int _expectedCount;

	const char * _file;
	int _line;
	const char * _testMethod;
	bool _isVerified;

	SequenceVerificationExpectation(
			VerificationEventHandler &fakeit,
			InvocationsSourceProxy mocks,
			std::vector<Sequence *> &expectedPattern);


	void VerifyExpectation(VerificationEventHandler &verificationErrorHandler);

	std::vector<Sequence *> &collectSequences(std::vector<Sequence *> &vec);

	template<typename ... list>
	std::vector<Sequence *> &collectSequences(std::vector<Sequence *> &vec, const Sequence &sequence,
											  const list &... tail) {
		vec.push_back(&const_cast<Sequence &>(sequence));
		return collectSequences(vec, tail...);
	}


	static void markAsVerified(std::vector<Invocation *> &matchedInvocations);

	bool isAtLeastVerification();

	bool isExactVerification();

	bool atLeastLimitNotReached(int actualCount);

	bool exactLimitNotMatched(int actualCount);

	void handleExactVerificationEvent(
		VerificationEventHandler &verificationErrorHandler,
		std::vector<Invocation *> actualSequence,
		int count);

	void handleAtLeastVerificationEvent(
		VerificationEventHandler &verificationErrorHandler,
		std::vector<Invocation *> actualSequence,
		int count);

};

}
