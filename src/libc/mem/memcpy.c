#include "mem.h"

void *memcpy(const void* src, void* dst, unsigned int n)
{
    char *dest_ptr = (char*)dst;
    const char *src_ptr = (const char*)src;
    if ((dest_ptr != NULL) && (src_ptr != NULL)) {
        while (n) {
            *(dest_ptr++) = *(src_ptr++);
            --n;
        }
    }
    return dst;
}
