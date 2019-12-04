/*
 * VerifyNoOtherInvocationsVerificationProgress.hpp
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Jul 21, 2014
 */
#pragma once

#include "fakeit/FakeitContext.h"
#include "mockutils/smart_ptr.hpp"
#include "mockutils/Macros.hpp"

#include <vector>


namespace fakeit {


struct ActualInvocationsSource;


class VerifyNoOtherInvocationsVerificationProgress {

	friend class VerifyNoOtherInvocationsFunctor;

	struct VerifyNoOtherInvocationsExpectation {

		friend class VerifyNoOtherInvocationsVerificationProgress;

		~VerifyNoOtherInvocationsExpectation() THROWS;
		void setFileInfo(const char * file, int line, const char * callingMethod);

	private:

		VerificationEventHandler &_fakeit;
		std::vector<ActualInvocationsSource *> _mocks;

		const char * _file;
		int _line;
		const char * _callingMethod;
		bool _isVerified;

		VerifyNoOtherInvocationsExpectation(VerificationEventHandler &fakeit, std::vector<ActualInvocationsSource *> mocks);

		VerifyNoOtherInvocationsExpectation(VerifyNoOtherInvocationsExpectation &other) = default;

		void VerifyExpectation(VerificationEventHandler &verificationErrorHandler);

	};

	smart_ptr<VerifyNoOtherInvocationsExpectation> _ptr;

	VerifyNoOtherInvocationsVerificationProgress(VerifyNoOtherInvocationsExpectation *ptr);
	VerifyNoOtherInvocationsVerificationProgress(FakeitContext &fakeit, std::vector<ActualInvocationsSource *> &invocationSources);
	bool toBool();

public:
	~VerifyNoOtherInvocationsVerificationProgress() THROWS;
	VerifyNoOtherInvocationsVerificationProgress setFileInfo(const char * file, int line, const char * callingMethod);
	operator bool() const;
	bool operator!() const;

};


}
