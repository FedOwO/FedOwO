#ifndef type_h
    #define type_h
    #define NULL ((void*)0)
    #define low_16(address) (unsigned short)((address) & 0xFFFF)
    #define high_16(address) (unsigned short)(((address) >> 16) & 0xFFFF)

#endif
