#ifndef UNSTDLIB_UNSTDSTRING_H
#define UNSTDLIB_UNSTDSTRING_H

#include "unstdinttypes.h"
#include "unstdbool.h"


//! [strlen]
/**
 * @brief Counts the number of UTF-8 characters (bytes (u8)) inside `buffer_arg`.
 * @note Returns 0 if `buffer_arg` is NULL.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @returns Number of UTF-8 characters (bytes (u8)) in `buffer_arg`.
 */
extern u64l unstdstring_strlen8(
        const char *const buffer_arg
);

/**
 * @brief Counts the number of UTF-16 characters (double-bytes (u16)) inside `buffer_arg`.
 * @note Returns 0 if `buffer_arg` is NULL.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated.
 * @returns Number of UTF-16 characters (double-bytes (u16)) in `buffer_arg`.
 */
extern u64l unstdstring_strlen16(
        const u16 *const buffer_arg
);


//! [compare]
/**
 *
 * @param f_buffer_arg Should be a character.
 * @param s_buffer_arg Should be a character.
 * @returns True if both buffers are identical otherwise False.
 */
extern bool unstdstring_charcmp(
        const u8 f_buffer_arg,
        const u8 s_buffer_arg
);

/**
 *
 * @param f_buffer_arg A pointer to a null-terminated buffer.
 * @param s_buffer_arg A pointer to a null-terminated buffer.
 * @returns True if both buffers are identical otherwise False.
 */
extern bool unstdstring_strcmp(
        const char *const f_buffer_arg,
        const char *const s_buffer_arg
);

/**
 *
 * @param f_buffer_arg A pointer to a null-terminated buffer.
 * @param s_buffer_arg A pointer to a null-terminated buffer.
 * @returns True if both buffers are identical otherwise False.
 */
extern bool unstdstring_strcmpignorecase(
        const char *const f_buffer_arg,
        const char *const s_buffer_arg
);


//! [startswith]
/**
 *
 * @param buffer_arg A pointer to a null-terminated buffer.
 * @param checkon_arg The character which the function performs the operation on.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_startswithchar8(
        const char *const buffer_arg,
        const char checkon_arg
);

/**
 *
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @param checkon_arg The character which the function performs the operation on.
 * @returns A pointer to the first character of the modified buffer.
 */
extern bool unstdstring_startswithcharignorecase8(
        const char *const buffer_arg,
        const char checkon_arg
);


//! [endswith]
/**
 *
 * @param buffer_arg A pointer to a null-terminated buffer.
 * @param checkon_arg The character which the function performs the operation on.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_endswithchar(
        const char *const buffer_arg,
        const char checkon_arg
);

/**
 *
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @param checkon_arg The character which the function performs the operation on.
 * @returns A pointer to the first character of the modified buffer.
 */
extern bool unstdstring_endswithcharignorecase(
        const char *const buffer_arg,
        const char checkon_arg
);


//! [tolower]
/**
 *
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
extern void unstdstring_tolowerstr(
        char *const buffer_arg
);

/**
 *
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array / constant buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
char *unstdstring_tolowerstrcopy(
        const char *const buffer_arg
);

/**
 *
 * @param buffer_arg Should be a reference to a null-terminated c-array of characters.
 * @returns A pointer to the first character of the modified buffer.
 */
extern void unstdstring_tolowerstrarray(
        char (*const buffer_arg)[]
);


//! [toupper]
/**
 *
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
extern void unstdstring_toupperstr(
        char *const buffer_arg
);

/**
 *
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
extern char *unstdstring_toupperstrcopy(
        const char *const buffer_arg
);

/**
 *
 * @param buffer_arg Should be a reference to a null-terminated c-array of characters.
 * @returns A pointer to the first character of the modified buffer.
 */
extern void unstdstring_toupperstrarray(
        char (*const buffer_arg)[]
);


//! [is]
//! [isascii]
/**
 * @brief Whether a character is an ASCII control character or not.
 * @param buffer_arg Should be an ASCII (u8) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isasciicontrolchar(
        const u8 buffer_arg
);

/**
 * @brief Whether a character is an ASCII printable character or not.
 * @param buffer_arg Should be an ASCII (u8) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isasciiprintablechar(
        const u8 buffer_arg
);

/**
 * @brief Whether a character is an ASCII extended character or not.
 * @param buffer_arg Should be an ASCII (u8) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isasciiextendedchar(
        const u8 buffer_arg
);

/**
 * @brief Whether a character is an ASCII visible character or not.
 * @param buffer_arg Should be an ASCII (u8) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isasciivisiblechar(
        const u8 buffer_arg
);

/**
 * @brief Whether a character is an ASCII or not.
 * @note I know i know, it's pretty dump.
 * @param buffer_arg Should be an ASCII (u8) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isasciichar(
        const u8 buffer_arg
);

/**
 * @brief Whether a character is within the ranges A-Z, a-z or not.
 * @param buffer_arg Should be an ASCII (u8) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isalphabeticchar(
        const u8 buffer_arg
);

/**
 * @brief Whether a character is within the ranges A-Z, a-z, 0-9 or not.
 * @param buffer_arg Should be an ASCII (u8) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isalphanumericchar(
        const u8 buffer_arg
);

/**
 * @brief Whether a character is within the range 0-9 or not.
 * @param buffer_arg Should be an ASCII (u8) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isdigitchar(
        const u8 buffer_arg
);

/**
 * @brief Whether a character is within the ranges A-f, a-f, 0-9 or not.
 * @param buffer_arg Should be an ASCII (u8) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_ishexchar(
        const u8 buffer_arg
);

/**
 * @brief Whether a character is a whitespace or not.
 * @param buffer_arg Should be a character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_iswhitespace(
        const u8 buffer_arg
);


//! [buffer]
//! [manipulation]
//! [resize]
/**
 * @internal This function should not be called directly (dont fuck around with it if you have no idea what the fuck are doing).
 * @brief Extends the buffer by reallocating it according to the `bytes_arg` param.
 * @details Extends the memory `bytes_arg` bytes, then zeros-out the newly reallocated (extended) memory.
 *          Be aware that it depends on <code>strlen()</code>; consider passing a buffer with (minimum_buffer_length >= 1) length.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param bytes_arg Number of bytes to extend the buffer by.<br><br>
 *                <strong>Maximum bytes_arg size</strong>: UNLIMITED (till your memory/system goes kaboom).<br>
 *                <strong>Minimum bytes_arg size</strong>: 0 (meaningless, waste of time/resource, shit-call operation. Why would you even wanna do that?).
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. Failed to reallocate.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @retval [3] Insufficient parameter. `bytes_arg` does not meet the minimum required length. See `bytes_arg`.
 * @retval [4] Failure. <code>memset()</code> failed.
 */
extern u8 _unstdstring_bufferextend(
        void *buffer_arg,
        const u64 bytes_arg
);

/**
 * @internal This function should not be called directly (dont fuck around with it if you have no idea what the fuck are doing).
 * @brief Shrinks down the buffer by reallocating it according to the `bytes_arg` param.
 * @details Shrinks the memory `bytes_arg` bytes, then zeros-out the newly reallocated (shrinked) memory.<br>
 *          Be aware that it depends on <code>strlen()</code>; consider passing a buffer with (minimum_buffer_length >= 1) length.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.<br><br>
 *                  <strong>Minimum buffer_arg length</strong>: 1 (should be enough to be able to get shrinked down).
 * @param bytes_arg Number of bytes to shrink the buffer by.<br><br>
 *                <strong>Maximum bytes_arg size</strong>: should be less than the size of `buffer_arg`.<br>
 *                <strong>Minimum bytes_arg size</strong>: 0 (meaningless, waste of time/resource, shit-call operation. Why would you even wanna do that?).
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. Failed to reallocate.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @retval [3] Insufficient parameter. `bytes_arg` does not meet the minimum required length. See `bytes_arg`.
 * @retval [4] Insufficient parameter. `buffer_arg` does not meet the minimum required length. Buffer is too short to be shrinked. See `buffer_arg`.
 * @retval [5] Insufficient parameter. `bytes_arg` does not meet the maximum required length. See `bytes_arg`.
 * @retval [6] Failure. <code>memset()</code> failed.
 */
extern u8 _unstdstring_buffershrink(
        void *buffer_arg,
        const u64 bytes_arg
);

/**
 * @brief Declares and initializes a valid, null-terminated heap-allocated UTF-8 string buffer.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array / constant buffer.<br>
 *                  It gets assigned to the string (return) after declaration.<br>
 *                  Pass `NULL` to ignore.
 * @param out_error_arg Will contain a number (u8) indicating the state of the operation. See `outparam` and `outvalue`s.<br>
 *                    It's considered best practice to always check for errors (only if you do give a shit).<br>
 *                    Pass `NULL` to ignore.
 * @returns A pointer to the newly allocated string buffer or NULL, in case of failure.
 * @OutParam <strong>out_error_arg</strong>
 * @OutParamValue [0] Failure. <code>malloc()<code> failed.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Failure <code>memset()</code> failed.
 * @OutParamValue [3] Failure <code>strcpy()</code> failed.
 */
extern char *unstdstring_bufferstringinit8(
        const char *const buffer_arg,
        u8 *const out_error_arg
);

/**
 * @brief Zeros all the bytes in `buffer_arg`.
 * @details This function only reallocates to 1; it does not free the `buffer_arg`,
 *          meaning that it only reallocates the buffer to the lowest size possible (that can only holds 1 byte '\0').
 * @attention Freeing the buffer is users responsibility.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. <code>memset()</code> failed.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @retval [3] Failure. <code>_unstdstring_buffershrink()</code> failed.
 */
extern u8 unstdstring_bufferclear(
        void *const buffer_arg
);


//! [add / remove]
//! [pop / push]
/**
 * @brief Appends a character (ANSI, 8bit) at the end of the string buffer.
 * @param to_buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param from_buffer_arg Should be an 8bit, ANSI character.
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. <code>_unstdstring_bufferextend()</code> failed.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `to_buffer_arg` is NULL. See `to_buffer_arg`.
 */
extern u8 unstdstring_pushchar8(
        void *const to_buffer_arg,
        const u8 from_buffer_arg
);

/**
 * @brief Appends a character (ANSI, 16bit) at the end of the string buffer.
 * @param to_buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param from_buffer_arg Should be a 16bit, ANSI character.
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. <code>_unstdstring_bufferextend()</code> failed.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `to_buffer_arg` is NULL. See `to_buffer_arg`.
 */
extern u8 unstdstring_pushchar16(
        void *const to_buffer_arg,
        const u16 from_buffer_arg
);

/**
 * @brief Pops back the last character (ANSI, 8bit) from buffer.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param out_error_arg Will contain a number (u8) indicating the state of the operation.<br>
 *                    Pass `NULL` to ignore.
 * @returns The popped character from end-of-the-buffer or 0 in case of failure which is not very reliable.<br>
 *          It's best practice to always check for errors (only if you do give a shit).<br>
 *          See `out_error_arg`.
 * @OutParam <strong>out_error_arg</strong>
 * @OutParamValue [0] Failure. <code>_unstdstring_buffershrink()</code> failed.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 */
extern u8 unstdstring_popchar8(
        void *const buffer_arg,
        u8 *const out_error_arg
);

/**
 * @brief Pops back the last character (ANSI, 16bit) from buffer.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param out_error_arg Will contain a number (u16) indicating the state of the operation.<br>
 *                    Pass `NULL` to ignore.
 * @returns The popped character from end-of-the-buffer or 0 in case of failure which is not very reliable.<br>
 *          It's best practice to always check for errors (only if you do give a shit).<br>
 *          See `out_error_arg`.
 * @OutParam <strong>out_error_arg</strong>
 * @OutParamValue [0] Failure. <code>_unstdstring_buffershrink()</code> failed.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 */
extern u16 unstdstring_popchar16(
        void *const buffer_arg,
        u8 *const out_error_arg
);

/**
 * @brief Appends a string at the end of the string buffer (`to_buffer_arg`).
 * @param to_buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param from_buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array / constant buffer.
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. code>_unstdstring_bufferextend()</code> failed.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `to_buffer_arg` is NULL. See `to_buffer_arg`.
 * @retval [3] Insufficient parameter. `from_buffer_arg` is NULL. See `from_buffer_arg`.
 */
extern u8 unstdstring_appendstr(
        void *const to_buffer_arg,
        const char *const from_buffer_arg
);

#endif /* UNSTDLIB_UNSTDSTRING_H */