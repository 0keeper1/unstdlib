#ifndef UNSTDLIB_UNSTDINTTYPES_H
#define UNSTDLIB_UNSTDINTTYPES_H

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <bits/stdint-uintn.h>

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

// an alias for fixed-size/width types
typedef uint8_t u8t;
typedef int8_t s8t;
typedef uint_least8_t u8lt;
typedef int_least8_t s8lt;

typedef uint16_t u16t;
typedef int16_t s16t;
typedef uint_least16_t u16lt;
typedef int_least16_t s16lt;

typedef uint32_t u32t;
typedef int32_t s32t;
typedef uint_least32_t u32lt;
typedef int_least32_t s32lt;

typedef uint64_t u64t;
typedef int64_t s64t;
typedef uint_least64_t u64lt;
typedef int_least64_t s64lt;



#endif /* UNSTDLIB_UNSTDINTTYPES_H */