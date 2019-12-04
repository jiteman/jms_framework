#include "InvocationHandlers.h"


namespace fakeit {


unsigned int InvocationHandlers::getOffset(unsigned int id) const
{
	unsigned int offset = 0;
	for (; offset < _offsets.size(); offset++) {
		if (_offsets[offset] == id) {
			break;
		}
	}
	return offset;
}

InvocationHandlers::InvocationHandlers(
		std::vector<std::shared_ptr<Destructible>> &methodMocks,
		std::vector<unsigned int> &offsets) :
		_methodMocks(methodMocks), _offsets(offsets)
{
	for (std::vector<unsigned int>::iterator it = _offsets.begin(); it != _offsets.end(); ++it)
	{
		*it = std::numeric_limits<int>::max();
	}
}

Destructible *InvocationHandlers::getInvocatoinHandlerPtrById(unsigned int id) {
	unsigned int offset = getOffset(id);
	std::shared_ptr<Destructible> ptr = _methodMocks[offset];
	return ptr.get();
}


} // namespace fakeit
