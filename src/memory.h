#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

void *memory_arena(size_t size);

struct malloc_area {
    uint8_t marker;
    struct malloc_area* prev;
    bool lock; 
    uint32_t length;
    struct malloc_area* next;
};

struct memory_header {
    int magical_bytes;
    bool lock;
    uint32_t num_blocks;
    uint16_t num_pages;
};

typedef struct malloc_area area;
typedef struct memory_header header;

#endif // MEMORY_H
