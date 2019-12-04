//
// Created by eran on 01/04/2015.
//

#include <unordered_set>
#include "fakeit/Invocation.hpp"

#include <memory>
#include <vector>


namespace fakeit {

	struct ActualInvocationsContainer {
		virtual void clear() = 0;

		virtual ~ActualInvocationsContainer() NO_THROWS;
	};

    struct ActualInvocationsSource {
        virtual void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const = 0;

        virtual ~ActualInvocationsSource() NO_THROWS;
    };

    struct InvocationsSourceProxy : public ActualInvocationsSource {

        InvocationsSourceProxy(ActualInvocationsSource *inner);

        void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const override;

    private:
        std::shared_ptr<ActualInvocationsSource> _inner;
    };

    struct UnverifiedInvocationsSource : public ActualInvocationsSource {

        UnverifiedInvocationsSource(InvocationsSourceProxy decorated);

        void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const override;

    private:
        InvocationsSourceProxy _decorated;
    };

    struct AggregateInvocationsSource : public ActualInvocationsSource {

        AggregateInvocationsSource(std::vector<ActualInvocationsSource *> &sources);

        void getActualInvocations(std::unordered_set<fakeit::Invocation *> &into) const override;

    protected:
        bool shouldInclude(fakeit::Invocation *) const;

    private:
        std::vector<ActualInvocationsSource *> _sources;

        void filter(std::unordered_set<Invocation *> &source, std::unordered_set<Invocation *> &target) const;
    };
}
