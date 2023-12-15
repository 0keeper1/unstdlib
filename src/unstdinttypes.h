#ifndef UNSTDLIB_UNSTDINTTYPES_H
#define UNSTDLIB_UNSTDINTTYPES_H

#include <stddef.h>
#include <sys/types.h>

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short int s16;

typedef unsigned int u32;
typedef signed int s32;

// at least 32 bits
typedef unsigned long int u32l;
typedef signed long int s32l;

#if __WORDSIZE == 64 || defined(__x86_64__)
typedef unsigned long int u64;
typedef signed long int s64;

// at least 64 bits
typedef unsigned long long int u64l;
typedef signed long long int s64l;
#else
typedef u32l u64;
typedef s32l s64;
#endif

#endif /* UNSTDLIB_UNSTDINTTYPES_H */