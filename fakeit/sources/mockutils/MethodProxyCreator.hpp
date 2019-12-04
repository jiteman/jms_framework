#pragma once
//#include <utility>

#include "mockutils/type_utils.hpp"
#include "mockutils/VirtualTable.hpp"
#include "mockutils/MethodProxy.h"
#include "mockutils/MethodInvocationHandler.hpp"
#include "mockutils/InvocationHandlers.h"
#include "mockutils/InvocationHandlerCollection.h"
#include "mockutils/Destructible.h"

namespace fakeit {

    template<typename R, typename ... arglist>
    class MethodProxyCreator {

        //using MethodProxyPtrType = R(MethodProxyCreator::*)(arglist...);

    public:

        template<unsigned int id>
        MethodProxy createMethodProxy(unsigned int offset) {
            return MethodProxy(id, offset, union_cast<void *>(&MethodProxyCreator::methodProxyX < id > ));
        }

    protected:

        R methodProxy(unsigned int id, const typename fakeit::production_arg<arglist>::type... args) {
            InvocationHandlerCollection *invocationHandlerCollection = InvocationHandlerCollection::getInvocationHandlerCollection(
                    this);
            MethodInvocationHandler<R, arglist...> *invocationHandler =
                    (MethodInvocationHandler<R, arglist...> *) invocationHandlerCollection->getInvocatoinHandlerPtrById(
                            id);
            return invocationHandler->handleMethodInvocation(std::forward<const typename fakeit::production_arg<arglist>::type>(args)...);
        }

        template<int id>
        R methodProxyX(arglist ... args) {
            return methodProxy(id, std::forward<const typename fakeit::production_arg<arglist>::type>(args)...);
        }
    };
}
