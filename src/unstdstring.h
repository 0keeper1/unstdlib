#ifndef UNSTDLIB_UNSTDSTRING_H
#define UNSTDLIB_UNSTDSTRING_H

#include "unstdinttypes.h"
#include "unstdbool.h"
#include "_unstdcommon.h"


/**
 * @brief Good Stuff, dont mind me.
 */
#ifndef __unstdstring_bufferencoding
#define __unstdstring_bufferencoding
#define _unstdstring_encode_as_utf8(string_arg) u8##string_arg
#define _unstdstring_encode_as_utf16(string_arg) u##string_arg
#define _unstdstring_encode_as_utf32(string_arg) U##string_arg

#define _unstdstring_encode_as_widechar(string_arg) L##string_arg
#define _unstdstring_encode_as_raw(string_arg) R##string_arg
#define _unstdstring_encode_as_raw_widechar(string_arg) LR##string_arg

#define _unstdstring_encode_as_raw_utf8(string_arg) u8R##string_arg
#define _unstdstring_encode_as_raw_utf16(string_arg) uR##string_arg
#define _unstdstring_encode_as_raw_utf32(string_arg) UR##string_arg
#endif /* __unstdstring_bufferencoding */


//! [strlen]
/**
 * @brief Counts the number of UTF-8 characters (bytes (u8t)) inside `buffer_arg`.
 * @note Returns 0 if `buffer_arg` is NULL.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @returns Number of UTF-8 characters (bytes (u8t)) in `buffer_arg`.
 */
extern u64lt unstdstring_strlen8(
        const char *const buffer_arg
);

/**
 * @brief Counts the number of UTF-16 characters (double-bytes (u16t)) inside `buffer_arg`.
 * @note Returns 0 if `buffer_arg` is NULL.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated.
 * @returns Number of UTF-16 characters (double-bytes (u16t)) in `buffer_arg`.
 */
extern u64lt unstdstring_strlen16(
        const u16t *const buffer_arg
);

/**
 * @brief Counts the number of UTF-32 characters (quad-bytes (u32t)) inside `buffer_arg`.
 * @note Returns 0 if `buffer_arg` is NULL.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated.
 * @returns Number of UTF-32 characters (quad-bytes (u32t)) in `buffer_arg`.
 */
extern u64lt unstdstring_strlen32(
        const u32t *const buffer_arg
);


//! [compare]
/**
 *
 * @param f_buffer_arg Should be an UTF-8 character.
 * @param s_buffer_arg Should be a UTF-8 character.
 * @returns True if both buffers are identical otherwise False.
 */
extern bool unstdstring_charcmp8(
        const u8t f_buffer_arg,
        const u8t s_buffer_arg
);

/**
 *
 * @param f_buffer_arg Should be an UTF-16 character.
 * @param s_buffer_arg Should be a UTF-16 character.
 * @returns True if both buffers are identical otherwise False.
 */
extern bool unstdstring_charcmp16(
        const u16t f_buffer_arg,
        const u16t s_buffer_arg
);

/**
 *
 * @param f_buffer_arg Should be an UTF-32 character.
 * @param s_buffer_arg Should be a UTF-32 character.
 * @returns True if both buffers are identical otherwise False.
 */
extern bool unstdstring_charcmp32(
        const u32t f_buffer_arg,
        const u32t s_buffer_arg
);

/**
 * @brief Checks if two UTF-8 strings are identical.
 * @details Its just a wrapper around the C's </code>strlen()</code>.
 * @param f_buffer_arg A pointer to a null-terminated buffer.
 * @param s_buffer_arg A pointer to a null-terminated buffer.
 * @returns True if both buffers are identical otherwise False.
 */
extern bool unstdstring_strcmp8(
        const char *const f_buffer_arg,
        const char *const s_buffer_arg
);

/**
 * @brief Checks if two UTF-16 strings are identical.
 * @details Compares `s_buffer_arg` by `f_buffer_arg`.<br><br>
 *          It returns true if both `f_buffer_arg` and `s_buffer_arg` are '\0'.<br>
 *          It returns false in case of length inequality.
 * @param f_buffer_arg A pointer to a null-terminated buffer.
 * @param s_buffer_arg A pointer to a null-terminated buffer.
 * @returns True if both buffers are identical otherwise False. See `details` for more details.
 */
extern bool unstdstring_strcmp16(
        const u16t *const f_buffer_arg,
        const u16t *const s_buffer_arg
);

/**
 * @brief Checks if two UTF-32 strings are identical.
 * @details Compares `s_buffer_arg` by `f_buffer_arg`.<br><br>
 *          It returns true if both `f_buffer_arg` and `s_buffer_arg` are '\0'.<br>
 *          It returns false in case of length inequality.
 * @param f_buffer_arg A pointer to a null-terminated buffer.
 * @param s_buffer_arg A pointer to a null-terminated buffer.
 * @returns True if both buffers are identical otherwise False. See `details` for more details.
 */
extern bool unstdstring_strcmp32(
        const u32t *const f_buffer_arg,
        const u32t *const s_buffer_arg
);

/**
 *
 * @param f_buffer_arg A pointer to a null-terminated buffer.
 * @param s_buffer_arg A pointer to a null-terminated buffer.
 * @returns True if both buffers are identical otherwise False.
 */
extern bool unstdstring_strcmpignorecase8(
        const char *const f_buffer_arg,
        const char *const s_buffer_arg
);

/**
 *
 * @param f_buffer_arg A pointer to a null-terminated buffer.
 * @param s_buffer_arg A pointer to a null-terminated buffer.
 * @returns True if both buffers are identical otherwise False.
 */
extern bool unstdstring_strcmpignorecase16(
        const u16t *const f_buffer_arg,
        const u16t *const s_buffer_arg
);

/**
 *
 * @param f_buffer_arg A pointer to a null-terminated buffer.
 * @param s_buffer_arg A pointer to a null-terminated buffer.
 * @returns True if both buffers are identical otherwise False.
 */
extern bool unstdstring_strcmpignorecase32(
        const u32t *const f_buffer_arg,
        const u32t *const s_buffer_arg
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
 * @param buffer_arg A pointer to a null-terminated buffer.
 * @param checkon_arg The character which the function performs the operation on.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_startswithchar16(
        const u16t *const buffer_arg,
        const u16t checkon_arg
);

/**
 *
 * @param buffer_arg A pointer to a null-terminated buffer.
 * @param checkon_arg The character which the function performs the operation on.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_startswithchar32(
        const u32t *const buffer_arg,
        const u32t checkon_arg
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
extern bool unstdstring_endswithchar8(
        const char *const buffer_arg,
        const char checkon_arg
);

/**
 *
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @param checkon_arg The character which the function performs the operation on.
 * @returns A pointer to the first character of the modified buffer.
 */
extern bool unstdstring_endswithcharignorecase8(
        const char *const buffer_arg,
        const char checkon_arg
);


//! [tolower]
/**
 *
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
extern void unstdstring_tolowerstr8(
        char *const buffer_arg
);

/**
 *
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array / constant buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
extern char *unstdstring_tolowerstrcopy8(
        const char *const buffer_arg
);

/**
 *
 * @param buffer_arg Should be a reference to a null-terminated c-array of characters.
 * @returns A pointer to the first character of the modified buffer.
 */
extern void unstdstring_tolowerstrarray8(
        char (*const buffer_arg)[]
);


//! [toupper]
/**
 *
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
extern void unstdstring_toupperstr8(
        char *const buffer_arg
);

/**
 *
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer.
 * @returns A pointer to the first character of the modified buffer.
 */
extern char *unstdstring_toupperstrcopy8(
        const char *const buffer_arg
);

/**
 *
 * @param buffer_arg Should be a reference to a null-terminated c-array of characters.
 * @returns A pointer to the first character of the modified buffer.
 */
extern void unstdstring_toupperstrarray8(
        char (*const buffer_arg)[]
);


//! [is]
//! [isascii]
/**
 * @brief Whether a character is an ASCII control character or not.
 * @param buffer_arg Should be an ASCII (u8t) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isasciicontrolchar(
        const u8t buffer_arg
);

/**
 * @brief Whether a character is an ASCII printable character or not.
 * @param buffer_arg Should be an ASCII (u8t) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isasciiprintablechar(
        const u8t buffer_arg
);

/**
 * @brief Whether a character is an ASCII extended character or not.
 * @param buffer_arg Should be an ASCII (u8t) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isasciiextendedchar(
        const u8t buffer_arg
);

/**
 * @brief Whether a character is an ASCII visible character or not.
 * @param buffer_arg Should be an ASCII (u8t) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isasciivisiblechar(
        const u8t buffer_arg
);

/**
 * @brief Whether a character is an ASCII or not.
 * @note I know i know, it's pretty dump.
 * @param buffer_arg Should be an ASCII (u8t) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isasciichar(
        const u8t buffer_arg
);

/**
 * @brief Whether a character is within the ranges A-Z, a-z or not.
 * @param buffer_arg Should be an ASCII (u8t) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isalphabeticchar(
        const u8t buffer_arg
);

/**
 * @brief Whether a character is within the ranges A-Z, a-z, 0-9 or not.
 * @param buffer_arg Should be an ASCII (u8t) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isalphanumericchar(
        const u8t buffer_arg
);

/**
 * @brief Whether a character is within the range 0-9 or not.
 * @param buffer_arg Should be an ASCII (u8t) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_isdigitchar(
        const u8t buffer_arg
);

/**
 * @brief Whether a character is within the ranges A-f, a-f, 0-9 or not.
 * @param buffer_arg Should be an ASCII (u8t) character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_ishexchar(
        const u8t buffer_arg
);

/**
 * @brief Whether a character is a whitespace or not.
 * @param buffer_arg Should be a character.
 * @returns A boolean indicating the state of the operation.
 */
extern bool unstdstring_iswhitespace(
        const u8t buffer_arg
);


//! [buffer]
//! [manipulation]
//! [resize]
/**
 * @internal This function should not be called directly (dont play around with it if you got no idea what you are doing).
 * @brief Extends the buffer by reallocating it according to the `bytes_arg` param.
 * @details Extends the memory `bytes_arg` bytes, then zeros-out the newly reallocated (extended) memory.<br>
 *          Be aware that it depends on <code>strlen()</code>; consider passing a buffer with (minimum_buffer_length >= 1) length.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param bytes_arg Number of bytes to extend the buffer by.<br><br>
 *                <strong>Maximum bytes_arg size</strong>: UNLIMITED (till your memory/system goes kaboom).<br>
 *                <strong>Minimum bytes_arg size</strong>: 1.
 * @param encoding_arg Number of bytes for each character within the buffer.<br>
 *                 (use `_unstdstring_bufferencoding` enum if you have no idea what you are doing).
 * @returns A number (u8t) indicating the state of the operation.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @retval [3] Insufficient parameter. `bytes_arg` does not meet the minimum required length. See `bytes_arg`.
 * @retval [4] Insufficient parameter. `encoding_arg` is not a valid encoding. See `encoding_arg`.
 * @retval [5] Failure. Failed to reallocate.
 * @retval [6] Failure. <code>memset()</code> failed.
 */
extern u8t _unstdstring_bufferextend(
        void *buffer_arg,
        const u32lt bytes_arg,
        const u8t encoding_arg
);

/**
 * @internal This function should not be called directly (dont play around with it if you got no idea what you are doing).
 * @brief Shrinks down the buffer by reallocating it according to the `bytes_arg` param.
 * @details Shrinks the memory `bytes_arg` bytes, then zeros-out the newly reallocated (shrinked) memory.<br>
 *          Be aware that it depends on <code>strlen()</code>; consider passing a buffer with (minimum_buffer_length >= 1) length.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.<br><br>
 *                  <strong>Minimum buffer_arg length</strong>: 1 (should be enough to be able to get shrinked down).
 * @param bytes_arg Number of bytes to shrink the buffer by.<br><br>
 *                <strong>Maximum bytes_arg size</strong>: should be less than the size of `buffer_arg`.<br>
 *                <strong>Minimum bytes_arg size</strong>: 1.
 * @param encoding_arg Number of bytes for each character within the buffer.<br>
 *                 (use `_unstdstring_bufferencoding` enum if you have no idea what you are doing).
 * @returns A number (u8t) indicating the state of the operation.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @retval [3] Insufficient parameter. `bytes_arg` does not meet the minimum required length. See `bytes_arg`.
 * @retval [4] Insufficient parameter. `buffer_arg` does not meet the minimum required length. Buffer is too short to be shrinked. See `buffer_arg`.
 * @retval [5] Insufficient parameter. `bytes_arg` does not meet the maximum required length. See `bytes_arg`.
 * @retval [6] Insufficient parameter. `encoding_arg` is not a valid encoding. See `encoding_arg`.
 * @retval [7] Failure. <code>memset()</code> failed.
 * @retval [8] Failure. <code>realloc()</code> failed.
 */
extern u8t _unstdstring_buffershrink(
        void *buffer_arg,
        const u32lt bytes_arg,
        const u8t encoding_arg
);

/**
 * @brief Declares and initializes a valid, null-terminated heap-allocated UTF-8 string buffer.
 * @details It allocates 8 bits (1 bytes) for each character.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array / constant buffer.<br>
 *                  It gets assigned to the string (return) after declaration.<br>
 *                  Pass `NULL` to ignore.
 * @param out_error_arg Will contain a number (u8t) indicating the state of the operation. See `outparam` and `outvalue`s.<br>
 *                    It's considered best practice to always check for errors.<br>
 *                    Pass `NULL` to ignore.
 * @returns A pointer to the newly allocated string buffer or NULL, in case of failure.
 * @OutParam <strong>out_error_arg</strong> A number (u8t) indicating the state of the operation.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Failure. <code>malloc()<code> failed.
 * @OutParamValue [3] Failure <code>memset()</code> failed.
 * @OutParamValue [4] Failure <code>strcpy()</code> failed.
 */
extern char *unstdstring_bufferstringinit8(
        const char *const buffer_arg,
        u8t *const out_error_arg
);

/**
 * @brief Declares and initializes a valid, null-terminated heap-allocated UTF-16 string buffer.
 * @details It allocates 16 bits (2 bytes) for each character despite the character encoding.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array / constant buffer.<br>
 *                  It gets assigned to the string (return) after declaration.<br>
 *                  Pass `NULL` to ignore.
 * @param out_error_arg Will contain a number (u8t) indicating the state of the operation. See `outparam` and `outvalue`s.<br>
 *                    It's considered best practice to always check for errors.<br>
 *                    Pass `NULL` to ignore.
 * @returns A pointer to the newly allocated string buffer or NULL, in case of failure.
 * @OutParam <strong>out_error_arg</strong> A number (u8t) indicating the state of the operation.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Failure. <code>malloc()<code> failed.
 * @OutParamValue [3] Failure <code>memset()</code> failed.
 * @OutParamValue [4] Failure <code>memcpy()</code> failed.
 */
extern u16t *unstdstring_bufferstringinit16(
        const u16t *const buffer_arg,
        u8t *const out_error_arg
);

/**
 * @brief Declares and initializes a valid, null-terminated heap-allocated UTF-32 string buffer.
 * @details It allocates 32 bits (4 bytes) for each character despite the character encoding.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array / constant buffer.<br>
 *                  It gets assigned to the string (return) after declaration.<br>
 *                  Pass `NULL` to ignore.
 * @param out_error_arg Will contain a number (u8t) indicating the state of the operation. See `outparam` and `outvalue`s.<br>
 *                    It's considered best practice to always check for errors.<br>
 *                    Pass `NULL` to ignore.
 * @returns A pointer to the newly allocated string buffer or NULL, in case of failure.
 * @OutParam <strong>out_error_arg</strong> A number (u8t) indicating the state of the operation.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Failure. <code>malloc()<code> failed.
 * @OutParamValue [3] Failure <code>memset()</code> failed.
 * @OutParamValue [4] Failure <code>memcpy()</code> failed.
 */
extern u32t *unstdstring_bufferstringinit32(
        const u32t *const buffer_arg,
        u8t *const out_error_arg
);

/**
 * @brief Zeros all the bytes in `buffer_arg`.
 * @details This function only reallocates to 1 byte; it does not free the `buffer_arg`,<br>
 *          meaning that it only reallocates the buffer to the lowest size possible (that can only holds 1 byte '\0').
 * @attention Freeing the buffer is users responsibility.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @returns A number (u8t) indicating the state of the operation.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @retval [3] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @retval [4] Failure. <code>_unstdstring_buffershrink()</code> failed.
 */
extern u8t unstdstring_bufferclear8(
        char *const buffer_arg
);

/**
 * @brief Zeros all the bytes in `buffer_arg`.
 * @details This function only reallocates to 2 byte; it does not free the `buffer_arg`,<br>
 *          meaning that it only reallocates the buffer to the lowest size possible (that can only holds 2 bytes '\0').
 * @attention Freeing the buffer is users responsibility.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @returns A number (u8t) indicating the state of the operation.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @retval [3] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @retval [4] Failure. <code>_unstdstring_buffershrink()</code> failed.
 */
extern u8t unstdstring_bufferclear16(
        u16t *const buffer_arg
);


//! [add / remove]
//! [pop / push]
/**
 * @brief Appends a character (ANSI, 8bit) at the end of the string buffer.
 * @param to_buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param from_buffer_arg Should be an 8bit, ANSI character.
 * @returns A number (u8t) indicating the state of the operation.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `to_buffer_arg` is NULL. See `to_buffer_arg`.
 * @retval [3] Failure. <code>_unstdstring_bufferextend()</code> failed.
 */
extern u8t unstdstring_pushbackchar8(
        char *const to_buffer_arg,
        const u8t from_buffer_arg
);

/**
 * @brief Appends a character (ANSI, 16bit) at the end of the string buffer.
 * @param to_buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param from_buffer_arg Should be a 16bit, ANSI character.
 * @returns A number (u8t) indicating the state of the operation.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `to_buffer_arg` is NULL. See `to_buffer_arg`.
 * @retval [3] Failure. <code>_unstdstring_bufferextend()</code> failed.
 */
extern u8t unstdstring_pushbackchar16(
        u16t *const to_buffer_arg,
        const u16t from_buffer_arg
);

/**
 * @brief Pops back the last character (ANSI, 8bit) from buffer.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param out_error_arg Will contain a number (u8t) indicating the state of the operation.<br>
 *                    Pass `NULL` to ignore.
 * @returns The popped character from end-of-the-buffer or 0 in case of failure which is not very reliable.<br>
 *          It's best practice to always check for errors.<br>
 *          See `out_error_arg`.
 * @OutParam <strong>out_error_arg</strong> A number (u8t) indicating the state of the operation.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @OutParamValue [3] Insufficient parameter. `buffer_arg` is an empty string. See `buffer_arg`.
 * @OutParamValue [4] Failure. <code>_unstdstring_buffershrink()</code> failed.
 */
extern u8t unstdstring_popbackchar8(
        char *const buffer_arg,
        u8t *const out_error_arg
);

/**
 * @brief Pops back the last character (ANSI, 16bit) from buffer.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param out_error_arg Will contain a number (u16t) indicating the state of the operation.<br>
 *                    Pass `NULL` to ignore.
 * @returns The popped character from end-of-the-buffer or 0 in case of failure which is not very reliable.<br>
 *          It's best practice to always check for errors.<br>
 *          See `out_error_arg`.
 * @OutParam <strong>out_error_arg</strong> A number (u8t) indicating the state of the operation.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @OutParamValue [3] Insufficient parameter. `buffer_arg` is an empty string. See `buffer_arg`.
 * @OutParamValue [4] Failure. <code>_unstdstring_buffershrink()</code> failed.
 */
extern u16t unstdstring_popbackchar16(
        u16t *const buffer_arg,
        u8t *const out_error_arg
);

/**
 * @brief Appends a string at the end of the string buffer (`to_buffer_arg`).
 * @param to_buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param from_buffer_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array / constant buffer.
 * @returns A number (u8t) indicating the state of the operation.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `to_buffer_arg` is NULL. See `to_buffer_arg`.
 * @retval [3] Insufficient parameter. `from_buffer_arg` is NULL. See `from_buffer_arg`.
 * @retval [4] Insufficient parameter. `from_buffer_arg` is an empty string. See `from_buffer_arg`.
 * @retval [5] Failure. code>_unstdstring_bufferextend()</code> failed.
 */
extern u8t unstdstring_pushbackstr8(
        char *const to_buffer_arg,
        const char *const from_buffer_arg
);

/**
 * @brief Returns an specific part of the `buffer_arg` as an allocated copy.
 * @param buffer_arg Should be a pointer to a valid, null-terminated heap-allocated buffer.
 * @param start_arg Position of the first character to be copied as a substring.<br>
 *                  If this is greater than or equal to the `buffer_arg` length,<br>
 *                  it returns NULL and throws out_of_range. See `OutParamValue`
 * @param span_arg Number of characters to include in the substring<br>
 *                 (if the string is shorter or `span_arg` is zero or it goes out of index,<br>
 *                 as many characters as possible are read).
 * @returns A pointer to portion of the `buffer_arg` that starts at position `start_arg`<br>
 *          and spans `span_arg` characters. Returns NULL in case of failure.
 * @OutParam <strong>out_error_arg</strong> A number (u8t) indicating the state of the operation.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @OutParamValue [3] Insufficient parameter. `buffer_arg` is an empty string. See `buffer_arg`.
 * @OutParamValue [4] Failure. `start_arg` out_of_range.
 * @OutParamValue [5] Failure. <code>calloc()</code> failed.
 * @OutParamValue [6] Failure. <code>malloc()<code> failed.
 *
 */
extern char *unstdstring_substrcopy8(
        char *const buffer_arg,
        const u32lt start_arg,
        const u32lt span_arg,
        u8t *const out_error_arg
);

#endif /* UNSTDLIB_UNSTDSTRING_H */
