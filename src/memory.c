#include "memory.h"
#include <string.h>

static unsigned char *arena_buffer;
static size_t arena_buffer_length;
static size_t arena_offset;

void *memory_arena(size_t size) {
    //
    if (arena_offset + size <= arena_buffer_length) {
        void* pointer = &arena_buffer[arena_offset];
        arena_offset += size;
        memset(pointer, 0, size);
        return pointer;
    }
    // if there is no more space then return an error
    return NULL;
}
