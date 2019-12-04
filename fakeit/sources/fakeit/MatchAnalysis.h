//
// Created by eran on 09/04/2015.
//

#pragma once

#include "Invocation.h"

#include <vector>
#include <unordered_set>


namespace fakeit {



struct InvocationsSourceProxy;

class Sequence;


struct MatchAnalysis {
	std::vector<Invocation *> actualSequence;
	std::vector<Invocation *> matchedInvocations;
	int count;

	void run(InvocationsSourceProxy &involvedInvocationSources, std::vector<Sequence *> &expectedPattern);

private:
	static void getActualInvocationSequence(InvocationsSourceProxy &involvedMocks, std::vector<Invocation *> &actualSequence);

	static int countMatches(std::vector<Sequence *> &pattern, std::vector<Invocation *> &actualSequence, std::vector<Invocation *> &matchedInvocations) ;

	static void collectActualInvocations(InvocationsSourceProxy &involvedMocks, std::unordered_set<Invocation *> &actualInvocations);

	static bool findNextMatch(
		std::vector<Sequence *> &pattern,
		std::vector<Invocation *> &actualSequence,
		int startSearchIndex,
		int &end,
		std::vector<Invocation *> &matchedInvocations);


	static void collectMatchedInvocations(
		std::vector<Invocation *> &actualSequence,
		std::vector<Invocation *> &matchedInvocations,
		int start,
		int length);


	static bool isMatch(std::vector<Invocation *> &actualSequence, std::vector<Invocation::Matcher *> &expectedSequence, int start);
	static int findNextMatch(Sequence *&pattern, std::vector<Invocation *> &actualSequence, int startSearchIndex);

};


}
