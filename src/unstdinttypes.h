#ifndef UNSTDLIB_UNSTDINTTYPES_H
#define UNSTDLIB_UNSTDINTTYPES_H

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short int s16;

typedef unsigned int u32;
typedef signed int s32;

#if __WORDSIZE == 64 || defined __x86_64__
typedef unsigned long int u64;
typedef signed long int s64;

typedef unsigned long long int u128;
typedef signed long long int s128;
#else
typedef u32 u64;
typedef s32 s64;
#endif

#endif /* UNSTDLIB_UNSTDINTTYPES_H */