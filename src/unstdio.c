#include "unstdio.h"

#include <stdio.h>
#include <stdlib.h>
#include "unstdinttypes.h"
#include "unstdbool.h"

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