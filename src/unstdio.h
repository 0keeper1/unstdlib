#ifndef UNSTDLIB_UNSTDIO_H
#define UNSTDLIB_UNSTDIO_H

#include <stdio.h>
#include <stdlib.h>
#include "unstdinttypes.h"
#include "unstdbool.h"

//! [macros]
/**
 * @brief Reads lines of bytes from the file pointer `fileptr_arg`
 *        and writes the content of the line to the buffer `line_data_arg`
 *        and the bytes of the line to line_bytes_arg.
 * @attention It should be used like any other scope-based loop. See `example`.
 * @param line_data_arg Will be declared and assigned.
 * @param line_bytes_arg Will be declared and assigned.
 * @example
 * <pre>
 * @code
 * FILE *fileptr_as_read = openfile(filepath_arg, "r");
 * if (fileptr_as_read == NULL) {
 *     // Error handling
 * }
 *
 * <strong>unstdio_freadlinesM</strong>(line, bytes, fileptr_as_read) {
 *     printf("Retrieved bytes of the current line %zu:\n", bytes);
 *     printf("line content: %s\n", line);
 * }
 * </pre>
 */
#define unstdio_freadlinesM(line_data_arg, line_bytes_arg, fileptr_arg)         \
__ssize_t line_bytes_arg;                                                       \
size_t len = 0;                                                                 \
char *line_data_arg = NULL;                                                     \
while ((line_bytes_arg = getline(&line_data_arg, &len, fileptr_arg)) != -1)

//! [file operations]
/**
 * @brief Opens a file in a more fancy shit way.
 * @param filepath_arg Should be a pointer to a valid, null-terminated heap-allocated / c-array buffer
 *                     containing a path to the desired file.
 * @param mod_arg The usual modes that you would pass to <code>fopen()</code> function.
 * @OutParam <strong>fileptr_arg</strong> Should be a pointer to a NULL FILE handle.
 * @OutParamValue [NULL] Failure. Refer to `retval`'s.
 * @OutParamValue [Valid Pointer] Success.
 * @returns A number (u8) indicating the state of the operation.
 * @retval [0] Failure. <code>realpath()</code> failed.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `fileptr_arg` is NULL. See `OutParam`.
 * @retval [3] Failure. <code>fopen()</code> failed.
 */
u8 unstdio_openfile(
        const char *const filepath_arg,
        const char *const mod_arg,
        const FILE *fileptr_arg
);

/**
 * @brief Gets the size of a file in bytes excluding the null-terminators
 *        (kinda like the number of characters in a file).
 * @param fileptr_arg Should be a valid pointer to a valid FILE handle.
 * @returns The number of bytes in the file pointed to by `fileptr_arg`, otherwise -1 in case of failure.
 */
s32l unstdio_getfilesize(
        FILE *const fileptr_arg
);

#endif //UNSTDLIB_UNSTDIO_H
