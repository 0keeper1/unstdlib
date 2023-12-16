#ifndef UNSTDLIB__UNSTDCOMMON_H
#define UNSTDLIB__UNSTDCOMMON_H

#include "unstdinttypes.h"

#if defined(__WIN32) || defined(__WIN64)
#define __SHITDOWS
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