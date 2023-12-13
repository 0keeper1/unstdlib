#ifndef UNSTDLIB__UNSTDCOMMON_H
#define UNSTDLIB__UNSTDCOMMON_H

#include "unstdinttypes.h"

#if defined(__WIN32) || defined(__WIN64)
#define __SHITDOWS
#endif

/**
 * @brief Checks whether a machine is little-endian or big-endian.
 * @details `usethefuckinggoogle.com`
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] little-endian
 * @retval [1] big-endian
 */
u8 unstdcommon_endianness(void) {
    u8 i = 1;
    return !((u8 *) &i)[0];
}

#endif /* UNSTDLIB__UNSTDCOMMON_H */