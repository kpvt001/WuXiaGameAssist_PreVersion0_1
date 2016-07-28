#ifndef BASECONFIG_H
#define BASECONFIG_H

namespace wuxia {
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
            private: \
            TypeName(const TypeName&); \
            void operator=(const TypeName&)

#define P_Class(TypeName) \
            PrivateClass_##TypeName
}

#endif // BASECONFIG_H

