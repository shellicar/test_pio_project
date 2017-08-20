#ifndef __LIB_FRAMEWORK__STATEID_H__
#define __LIB_FRAMEWORK__STATEID_H__

#include <cstdint>

enum class StateID : int16_t
{
    Invalid = -1,
    
    Init = 0,
    Join
};

#endif // __LIB_FRAMEWORK__STATEID_H__
