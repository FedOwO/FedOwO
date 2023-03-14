#ifndef MEM_H
    #define MEM_H
    #include "../type.h"

void memory_set(char *dest, char val, unsigned int len);
void *memcpy(const void* src, void* dst, unsigned int n);

#endif //FEDOWO_MEM_H
