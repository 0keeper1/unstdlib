#include "unstdio.h"

#include <stdio.h>
#include <stdlib.h>
#include "unstdinttypes.h"
#include "unstdbool.h"


#ifndef unstdio_freadlinesM
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
#endif


u8 unstdio_openfile(const char *const filepath_arg, const char *const mod_arg, const FILE *fileptr_arg) {
    char *filepath_arg_realpath = NULL;
    if ((filepath_arg_realpath = realpath(filepath_arg, NULL)) == NULL) {
        return 0;
    }

    FILE *file_ptr = NULL;
    if ((file_ptr = fopen(filepath_arg_realpath, mod_arg)) == NULL) {
        return 2;
    }

    fileptr_arg = file_ptr;

    return 1;
}

s32l getfilesize(FILE *const fileptr_arg) {
    if (fseek(fileptr_arg, 0, SEEK_END) < 0) {
        return -1;
    }

    s32l filesize;
    if (ftell(fileptr_arg) < 0) {
        return -2;
    }

    if (fseek(fileptr_arg, 0, SEEK_SET) < 0) {
        return -1;
    }  /* same as `rewind(fileptr_arg)` */

    return filesize;
}