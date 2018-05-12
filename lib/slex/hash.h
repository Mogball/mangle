#ifndef SLEX_HASH_H
#define SLEX_HASH_H

#include "types.h"

extern uint32 hash_string(const char *str);

extern uint32 hash_uint32(uint32 v);
extern uint32 hash_int32(int32 v);

extern uint32 hash_uint64(uint64 v);
extern uint32 hash_int64(int64 v);

extern uint32 hash_ptr(void *ptr);

#endif //SLEX_HASH_H
