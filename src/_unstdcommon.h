#ifndef UNSTDLIB__UNSTDCOMMON_H
#define UNSTDLIB__UNSTDCOMMON_H

#include "unstdinttypes.h"

#if defined(__WIN32) || defined(__WIN64)
#define __SHITDOWS
#error "This library is not intended to be used on Windows platforms."
#endif

#ifdef __STDC__
#ifdef __STDC_VERSION__
#if (__STDC_VERSION__ < 201112L)
#error "Compiler's version should be at least C11."
#endif
#endif
#endif

/**
 * @brief Checks whether a machine is little-endian or big-endian.
 * @details It first, stores a 2 continues bytes into memory, then fetches the first byte of it.
 * @returns A number (u8t) indicating the state of the operation.
 * @retval [0] little-endian
 * @retval [1] big-endian
 */
u8t unstdcommon_endianness(void) {
    u16t i = 0x00ff;
    return ((u8t *) &i)[0] == 0x00;
}

#endif /* UNSTDLIB__UNSTDCOMMON_H */