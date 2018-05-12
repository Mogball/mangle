#ifndef SLEX_UNORDERED_MAP_H
#define SLEX_UNORDERED_MAP_H

#include "types.h"
#include "hash.h"

#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEFINE_MAP_TYPE(type, key_t, val_t, hash_func)              \
typedef struct type##_node {                                        \
    key_t key;                                                      \
    val_t val;                                                      \
    struct type##_node *next;                                       \
} type##_node;                                                      \
                                                                    \
typedef struct type {                                               \
    type##_node **table;                                            \
    float32 max_load;                                               \
    uint32 size;                                                    \
    uint32 capacity;                                                \
} type;                                                             \
                                                                    \
typedef struct type##_create_args {                                 \
    uint32 size;                                                    \
    float32 max_load;                                               \
} type##_create_args;                                               \
                                                                    \
inline type *type##_create(uint32 capacity, float32 max_load) {     \
    type *ptr = malloc(sizeof(type));                               \
    uint32 table_size = capacity * sizeof(type##_node *);           \
    type##_node **table = malloc(table_size);                       \
    memset(table, 0, table_size);                                   \
    ptr->table = table;                                             \
    ptr->capacity = capacity;                                       \
    ptr->max_load = max_load;                                       \
    ptr->size = 0;                                                  \
    return ptr;                                                     \
}                                                                   \
                                                                    \
inline void type##_delete(type *ptr) {                              \
    assert(ptr != NULL);                                            \
    assert(ptr->table != NULL);                                     \
    type##_node *head = NULL;                                       \
    type##_node *next = NULL;                                       \
    for (uint32 i = 0; i < ptr->capacity; ++i) {                    \
        head = ptr->table[i];                                       \
        while (head) {                                              \
            next = head->next;                                      \
            free(head);                                             \
            head = next;                                            \
        }                                                           \
    }                                                               \
    free(ptr->table);                                               \
    free(ptr);                                                      \
}                                                                   \
                                                                    \
inline bool type##_insert(                                          \
    key_t *key,                                                     \
    val_t *val,                                                     \
    type##_node *it                                                 \
) {                                                                 \
    uint32 hash = hash_func(*key);

DEFINE_MAP_TYPE(smap, char *, char *, hash_string)
DEFINE_MAP_TYPE(imap, uint32, uint32, hash_uint32)
DEFINE_MAP_TYPE(ismap, uint32, char *, hash_uint32)

#endif //SLEX_UNORDERED_MAP_H
