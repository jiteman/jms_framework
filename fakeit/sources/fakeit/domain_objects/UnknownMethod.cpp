#include "UnknownMethod.h"


namespace fakeit {


// static
MethodInfo &UnknownMethod::instance() {
   static MethodInfo instance(MethodInfo::nextMethodOrdinal(), "unknown");
   return instance;
}


} // namespace fakeit

