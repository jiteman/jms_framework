/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once


#include <unordered_set>
#include <vector>


namespace fakeit {


class Sequence;

struct Invocation;
struct ActualInvocationsSource;


struct InvocationUtils {

	static void sortByInvocationOrder(std::unordered_set<Invocation *> &ivocations, std::vector<Invocation *> &result);
	static void collectActualInvocations(std::unordered_set<Invocation *> &actualInvocations, std::vector<ActualInvocationsSource *> &invocationSources);
	static void selectNonVerifiedInvocations(std::unordered_set<Invocation *> &actualInvocations, std::unordered_set<Invocation *> &into);
	static void collectInvocationSources(std::vector<ActualInvocationsSource *> &);

	template<typename ... list>
	static void collectInvocationSources(std::vector<ActualInvocationsSource *> &into,
										 const ActualInvocationsSource &mock,
										 const list &... tail) {
		into.push_back(const_cast<ActualInvocationsSource *>(&mock));
		collectInvocationSources(into, tail...);
	}

	static void collectSequences(std::vector<Sequence *> &);

	template<typename ... list>
	static void collectSequences(std::vector<Sequence *> &vec, const Sequence &sequence, const list &... tail) {
		vec.push_back(&const_cast<Sequence &>(sequence));
		collectSequences(vec, tail...);
	}

	static void collectInvolvedMocks(std::vector<Sequence *> &allSequences, std::vector<ActualInvocationsSource *> &involvedMocks);

	template<class T>
	static T &remove_const(const T &s) {
		return const_cast<T &>(s);
	}

};


}
