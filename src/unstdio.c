#include "unstdio.h"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
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


u8t unstdio_openfile(const char *const filepath_arg, const char *const mod_arg, FILE **fileptr_arg) {
    if (!filepath_arg) {
        return 2;
    }

    if (!*filepath_arg) {
        return 3;
    }

    if (!mod_arg) {
        return 4;
    }

    if (!*mod_arg) {
        return 5;
    }

    if (!fileptr_arg) {
        return 6;
    }

    FILE *file_ptr = NULL;
    if ((file_ptr = fopen(filepath_arg, mod_arg)) == NULL) {
        return 0;
    }

    *fileptr_arg = file_ptr;

    return 1;
}

s64t unstdio_closefile(FILE *const fileptr_arg) {
    if (!fileptr_arg) {
        return 2;
    }

    if (fclose(fileptr_arg) != 0) {
        return 0;
    }

    return 1;
}

u8t unstdio_removefile(const char *const filepath_arg) {
    if (!filepath_arg) {
        return 2;
    }

    if (!*filepath_arg) {
        return 3;
    }

    u8t doesfileexist_result = unstdio_doesfileexist(filepath_arg);
    if (doesfileexist_result == 2) {
        return 4;
    } else if (doesfileexist_result == 0) {
        return 5;
    }

    if (remove(filepath_arg) < 0) {
        return 0;
    }

    return 1;
}

u8t unstdio_doesfileexist(const char *const filepath_arg) {
    if (!filepath_arg) {
        return 2;
    }

    if (!*filepath_arg) {
        return 3;
    }

    s32t access_result = access(filepath_arg, F_OK);
    if (access_result >= 0) {
        return 1;
    } else {
        if (errno == ENOENT) {
            return 0;
        } else {
            return 4;
        }
    }
}

u8t unstdio_isregularfile(const char *const filepath_arg) {
    if (!filepath_arg) {
        return 2;
    }

    if (!*filepath_arg) {
        return 3;
    }

    struct stat path_stat;
    if (stat(filepath_arg, &path_stat)) {
        return 4;
    }

    return S_ISREG(path_stat.st_mode);
}

s64t unstdio_getfilesize(FILE *const fileptr_arg) {
    if (fseek(fileptr_arg, 0, SEEK_END) < 0) {
        return -3;
    }

    s64t filesize;
    if ((filesize = ftell(fileptr_arg)) < 0) {
        return -4;
    }

    if (fseek(fileptr_arg, 0, SEEK_SET) < 0) {
        return -3;
    }  /* same as `rewind(fileptr_arg)` */

    return filesize;
}
