#include "hash.h"

#define BIT_16  2
#define BIT_32  4
#define BIT_64  8

uint32 hash_string(const char *str) {
    uint32 hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

uint32 hash_uint32(uint32 v) {
    v = ((v >> 16) ^ v) * 0x45d9f3b;
    v = ((v >> 16) ^ v) * 0x45d9f3b;
    v = (v >> 16) ^ v;
    return v;
}

uint32 hash_int32(int32 v) {
    return hash_uint32((uint32) v);
}

uint32 hash_uint64(uint64 v) {
    return (uint32) (v * 14695981039346656037);
}

uint32 hash_int64(int64 v) {
    return hash_uint64((uint64) v);
}

uint32 hash_ptr(void *ptr) {
    const uint32 ptr_size = sizeof(void *);
    uint32 hash;
    switch (ptr_size) {
        case BIT_64:
            hash = hash_uint64((uint64) ptr);
            break;
        case BIT_32:
        case BIT_16:
        default:
            hash = hash_uint32((uint32) ptr);
            break;
    }
    return hash;
}
