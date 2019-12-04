#pragma once


#include "InvocationHandlerCollection.h"
#include "Destructible.h"

#include <vector>
#include <memory>


namespace fakeit {


class InvocationHandlers : public InvocationHandlerCollection {
	std::vector<std::shared_ptr<Destructible>> &_methodMocks;
	std::vector<unsigned int> &_offsets;

	unsigned int getOffset(unsigned int id) const;

public:
	InvocationHandlers(
			std::vector<std::shared_ptr<Destructible>> &methodMocks,
			std::vector<unsigned int> &offsets);

	Destructible *getInvocatoinHandlerPtrById(unsigned int id) override;

};


} // namespace fakeit
