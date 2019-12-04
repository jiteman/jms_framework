/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once

#include <set>
#include <vector>
#include <stdexcept>

#include "mockutils/Macros.hpp"
#include "fakeit/ActualInvocation.hpp"
//#include "fakeit/ActualInvocationsSource.h"


namespace fakeit {


struct ActualInvocationsSource;

class Sequence {
private:

protected:

	Sequence();

	virtual ~Sequence() THROWS;
public:

	/**
	 * Fetch the matchers that make-up this sequence.
	 */
	virtual void getExpectedSequence(std::vector<Invocation::Matcher *> &into) const = 0;

	/**
	 * Collect all mock objects that are involved in this sequence.
	 */
	virtual void getInvolvedMocks(std::vector<ActualInvocationsSource *> &into) const = 0;

	virtual unsigned int size() const = 0;

	friend class VerifyFunctor;
};

class ConcatenatedSequence : public virtual Sequence {
private:
	const Sequence &s1;
	const Sequence &s2;

protected:
	ConcatenatedSequence(const Sequence &seq1, const Sequence &seq2);

public:

	virtual ~ConcatenatedSequence();

	unsigned int size() const override;

	const Sequence &getLeft() const;

	const Sequence &getRight() const;

	void getExpectedSequence(std::vector<Invocation::Matcher *> &into) const override;

	virtual void getInvolvedMocks(std::vector<ActualInvocationsSource *> &into) const override;

	friend ConcatenatedSequence operator+(const Sequence &s1, const Sequence &s2);
};

class RepeatedSequence : public virtual Sequence {
private:
	const Sequence &_s;
	const int times;

protected:
	RepeatedSequence(const Sequence &s, const int t);

public:

	~RepeatedSequence();

	unsigned int size() const override ;

	friend RepeatedSequence operator*(const Sequence &s, int times);

	friend RepeatedSequence operator*(int times, const Sequence &s);

	void getInvolvedMocks(std::vector<ActualInvocationsSource *> &into) const override;

	void getExpectedSequence(std::vector<Invocation::Matcher *> &into) const override;

	int getTimes() const;

	const Sequence &getSequence() const;
};


ConcatenatedSequence operator +(const Sequence &s1, const Sequence &s2);

RepeatedSequence operator *(const Sequence &s, int times);

RepeatedSequence operator *(int times, const Sequence &s);


}
