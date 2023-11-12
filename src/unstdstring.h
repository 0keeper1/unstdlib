#include "unstdinttypes.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

//! [compare]
/**
 *
 * @param fBufferArg Should be a character.
 * @param sBufferArg Should be a character.
 * @returns True if both buffers are identical otherwise False.
 */
bool unstdstring_charcmp(
        const u8 fBufferArg,
        const u8 sBufferArg
);

/**
 *
 * @param fBufferArg A pointer to a null-terminated buffer.
 * @param sBufferArg A pointer to a null-terminated buffer.
 * @returns True if both buffers are identical otherwise False.
 */
bool unstdstring_strcmp(
        const char *const fBufferArg,
        const char *const sBufferArg
);

/**
 *
 * @param fBufferArg A pointer to a null-terminated buffer.
 * @param sBufferArg A pointer to a null-terminated buffer.
 * @returns True if both buffers are identical otherwise False.
 */
bool unstdstring_strcmpignorecase(
        const char *const fBufferArg,
        const char *const sBufferArg
);


//! [startswith]
/**
 *
 * @param bufferArg A pointer to a null-terminated buffer.
 * @param checkOnArg The character which the function performs the operation on.
 * @returns A boolean indicating the state of the operation.
 */
bool unstdstring_startswithchar(
        const char *const bufferArg,
        const char checkOnArg
);

/**
 *
 * @param bufferArg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @param checkOnArg The character which the function performs the operation on.
 * @returns A pointer to the first character of the modified buffer.
 */
bool unstdstring_startswithcharignorecase(
        const char *const bufferArg,
        const char checkOnArg
);


//! [endswith]
/**
 *
 * @param bufferArg A pointer to a null-terminated buffer.
 * @param checkOnArg The character which the function performs the operation on.
 * @returns A boolean indicating the state of the operation.
 */
bool unstdstring_endswithchar(
        const char *const bufferArg,
        const char checkOnArg
);

/**
 *
 * @param bufferArg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @param checkOnArg The character which the function performs the operation on.
 * @returns A pointer to the first character of the modified buffer.
 */
bool unstdstring_endswithcharignorecase(
        const char *const bufferArg,
        const char checkOnArg
);


//! [tolower]
/**
 *
 * @param bufferArg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
void unstdstring_tolowerstr(
        char *const bufferArg
);

/**
 *
 * @param bufferArg Should be a pointer to a valid, null-terminated heap-allocated / c-array / constant buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
char *unstdstring_tolowerstrcopy(
        const char *const bufferArg
);

/**
 *
 * @param bufferArg Should be a reference to a null-terminated c-array of characters.
 * @returns A pointer to the first character of the modified buffer.
 */
void unstdstring_tolowerstrarray(
        char (*const bufferArg)[]
);


//! [toupper]
/**
 *
 * @param bufferArg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
void unstdstring_toupperstr(
        char *const bufferArg
);

/**
 *
 * @param bufferArg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
char *unstdstring_toupperstrcopy(
        const char *const bufferArg
);

/**
 *
 * @param bufferArg Should be a reference to a null-terminated c-array of characters.
 * @returns A pointer to the first character of the modified buffer.
 */
void unstdstring_toupperstrarray(
        char (*const bufferArg)[]
);


//! [is]
//! [isascii]
/**
 *
 * @param bufferArg Should be an ascii character.
 * @returns Whether a character is an ASCII control character or not.
 */
bool unstdstring_isasciicontrolchar(
        const u8 bufferArg
);

/**
 *
 * @param bufferArg Should be an ascii character.
 * @returns Whether a character is an ASCII printable character or not.
 */
bool unstdstring_isasciiprintablechar(
        const u8 bufferArg
);

/**
 *
 * @param bufferArg Should be an ascii character.
 * @returns Whether a character is an ASCII extended character or not.
 */
bool unstdstring_isasciiextendedchar(
        const u8 bufferArg
);

/**
 *
 * @param bufferArg Should be a character.
 * @returns Whether a character is within the ranges A-Z, a-z or not.
 */
bool unstdstring_isalphabeticchar(
        const u8 bufferArg
);

/**
 *
 * @param bufferArg Should be a character.
 * @returns Whether a character is within the ranges A-Z, a-z, 0-9 or not.
 */
bool unstdstring_isalphanumericchar(
        const u8 bufferArg
);

/**
 *
 * @param bufferArg Should be a character.
 * @returns Whether a character is within the range 0-9 or not.
 */
bool unstdstring_isdigitchar(
        const u8 bufferArg
);

/**
 *
 * @param bufferArg Should be a character.
 * @returns Whether a character is within the ranges A-f, a-f, 0-9 or not.
 */
bool unstdstring_ishexchar(
        const u8 bufferArg
);

/**
 *
 * @param bufferArg Should be a character.
 * @returns Whether a character is within the ranges A-f, a-f, 0-9 or not.
 */
bool unstdstring_iswhitespace(
        const u8 bufferArg
);

//! [buffer]
//! [manipulation]
//! [resize]
/**
 * @internal This function should not be called directly (dont fuck around with it if you have no idea what the fuck are doing).
 * @brief Extends the buffer by reallocating it according to the `sizeArg` param.
 * @details Extends the memory `sizeArg` bytes, then zeros-out the newly reallocated (extended) memory.
 *          Be aware that it depends on `strlen()`; consider passing a buffer with (minimum_buffer_length >= 1) length.
 * @param bufferArg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param sizeArg Number of bytes to extend the buffer by.<br><br>
 *                <strong>Maximum sizeArg size</strong>: UNLIMITED (till your memory/system goes kaboom).<br>
 *                <strong>Minimum sizeArg size</strong>: 0 (meaningless, waste of time/resource, shit-call operation. Why would you even wanna do that?).
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. Failed to reallocate.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `bufferArg` is NULL. See `bufferArg`.
 * @retval [3] Insufficient parameter. `sizeArg` does not meet the minimum required length. See `sizeArg`.
 * @retval [4] Failure. 'memset()' failed.
 */
u8 _unstdstring_bufferextend(
        void *bufferArg,
        const u64 sizeArg
);

/**
 * @internal This function should not be called directly (dont fuck around with it if you have no idea what the fuck are doing).
 * @brief Shrinks down the buffer by reallocating it according to the `sizeArg` param.
 * @details Shrinks the memory `sizeArg` bytes, then zeros-out the newly reallocated (shrinked) memory.<br>
 *          Be aware that it depends on `strlen()`; consider passing a buffer with (minimum_buffer_length >= 1) length.
 * @param bufferArg Should be a pointer to a valid, null-terminated heap-allocated buffer.<br><br>
 *                  <strong>Minimum bufferArg length</strong>: 1 (should be enough to be able to get shrinked down).
 * @param sizeArg Number of bytes to shrink the buffer by.<br><br>
 *                <strong>Maximum sizeArg size</strong>: should be less than the size of `bufferArg`.<br>
 *                <strong>Minimum sizeArg size</strong>: 0 (meaningless, waste of time/resource, shit-call operation. Why would you even wanna do that?).
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. Failed to reallocate.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `bufferArg` is NULL. See `bufferArg`.
 * @retval [3] Insufficient parameter. `sizeArg` does not meet the minimum required length. See `sizeArg`.
 * @retval [4] Insufficient parameter. `bufferArg` does not meet the minimum required length. Buffer is too short to be shrinked. See `bufferArg`.
 * @retval [5] Insufficient parameter. `sizeArg` does not meet the maximum required length. See `sizeArg`.
 * @retval [6] Failure. 'memset()' failed.
 */
u8 _unstdstring_buffershrink(
        void *bufferArg,
        const u64 sizeArg
);


/**
 * @brief Declares and initializes a valid, null-terminated heap-allocated string buffer.
 * @param bufferArg Should be a pointer to a valid, null-terminated heap-allocated / c-array / constant buffer.<br>
 *                  It gets assigned to the string (return) after declaration.<br>
 *                  Pass `NULL` to ignore.
 * @param outErrorArg Will contain a number (u8) indicating the state of the operation. See `outparam` and `outvalue`s.<br>
 *                    It's considered best practice to always check for errors (only if you do give a shit).<br>
 *                    Pass `NULL` to ignore.
 * @returns A pointer to the newly allocated string buffer or NULL, in case of failure.
 * @OutParam outErrorArg
 * @OutParamValue [0] Failure. `malloc()` failed.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Failure `memset()` failed.
 * @OutParamValue [3] Failure `strcpy()` failed.
 */
char *unstdstring_bufferstringinit(
        const char *const bufferArg,
        u8 *const outErrorArg
);


/**
 * @brief Zeros all the bytes in `bufferArg`.
 * @details This function only reallocates to 1; it does not free the `bufferArg`,
 *          meaning that it only reallocates the buffer to the lowest size possible (that can only holds 1 byte '\0').
 * @attention Freeing the buffer is users responsibility.
 * @param bufferArg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. `memset()` failed.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `bufferArg` is NULL. See `bufferArg`.
 * @retval [3] Failure. `_unstdstring_buffershrink()` failed.
 */
u8 unstdstring_bufferclear(
        void *const bufferArg
);

//! [add / remove]
//! [pop / push]
/**
 * @brief Appends a character (ANSI, 8bit) at the end of the string buffer.
 * @param toBufferArg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param fromBufferArg Should be an 8bit, ANSI character.
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. `_unstdstring_bufferextend()` failed.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `toBufferArg` is NULL. See `toBufferArg`.
 */
u8 unstdstring_pushchar8(
        void *const toBufferArg,
        const u8 fromBufferArg
);

/**
 * @brief Pops back the last character (ANSI, 8bit) from buffer.
 * @param bufferArg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param outErrorArg Will contain a number (u8) indicating the state of the operation.<br>
 *                    Pass `NULL` to ignore.
 * @returns The popped character from end-of-the-buffer or 0 in case of failure which is not very reliable.<br>
 *          It's best practice to always check for errors (only if you do give a shit).<br>
 *          See `outErrorArg`.
 * @OutParam outErrorArg
 * @OutParamValue [0] Failure. `_unstdstring_buffershrink()` failed.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Insufficient parameter. `bufferArg` is NULL. See `bufferArg`.
 */
u8 unstdstring_popchar8(
        void *const bufferArg,
        u8 *const outErrorArg
);

/**
 * @brief Appends a string at the end of the string buffer (`toBufferArg`).
 * @param toBufferArg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param fromBufferArg Should be a pointer to a valid, null-terminated heap-allocated / c-array / constant buffer.
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. `_unstdstring_bufferextend()` failed.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `toBufferArg` is NULL. See `toBufferArg`.
 * @retval [3] Insufficient parameter. `fromBufferArg` is NULL. See `fromBufferArg`.
 */
u8 unstdstring_appendstr(
        void *const toBufferArg,
        const char *const fromBufferArg
);
