#include "unstdstring.h"

#include <ctype.h>
#include "unstdbool.h"
#include <stdlib.h>
#include <string.h>


extern u64l unstdstring_strlen8(const char *const buffer_arg) {
    if (buffer_arg == NULL || *buffer_arg == '\0') {
        return 0;
    }

    u64l len = 0;
    while (buffer_arg[++len] != '\0');
    return len;
}


extern u64l unstdstring_strlen16(const u16 *const buffer_arg) {
    if (buffer_arg == NULL || *buffer_arg == '\0') {
        return 0;
    }

    u64l len = 0;
    while (((u16 *) buffer_arg)[++len] != '\0');

    return len;
}


bool unstdstring_charcmp(const u8 f_buffer_arg, const u8 s_buffer_arg) {
    return f_buffer_arg == s_buffer_arg;
}


bool unstdstring_strcmp(const char *const f_buffer_arg, const char *const s_buffer_arg) {
    return f_buffer_arg != NULL && s_buffer_arg != NULL ? !strcmp(f_buffer_arg, s_buffer_arg) : false;
}


bool unstdstring_strcmpignorecase(const char *const f_buffer_arg, const char *const s_buffer_arg) {
    if (f_buffer_arg == NULL && s_buffer_arg == NULL) {
        return false;
    }

    char *lowered_f_buffer_arg = unstdstring_tolowerstrcopy(f_buffer_arg);
    char *lowered_s_buffer_arg = unstdstring_tolowerstrcopy(s_buffer_arg);
    bool strcmp_result = unstdstring_strcmp(lowered_f_buffer_arg, lowered_s_buffer_arg);
    free(lowered_s_buffer_arg);
    free(lowered_f_buffer_arg);
    return strcmp_result;
}


bool unstdstring_startswithchar(const char *const buffer_arg, const char checkon_arg) {
    if (buffer_arg == NULL) {
        return false;
    }

    if (strlen(buffer_arg) < 1) {
        return false;
    }

    return *buffer_arg == checkon_arg;
}


bool unstdstring_startswithcharignorecase(const char *const buffer_arg, const char checkon_arg) {
    if (buffer_arg == NULL) {
        return false;
    }

    if (strlen(buffer_arg) < 1) {
        return false;
    }

    return tolower(*buffer_arg) == tolower(checkon_arg);
}


bool unstdstring_endswithchar(const char *const buffer_arg, const char checkon_arg) {
    if (buffer_arg == NULL) {
        return false;
    }

    if (strlen(buffer_arg) < 1) {
        return false;
    }

    return buffer_arg[strlen(buffer_arg) - 1] == checkon_arg;
}


bool unstdstring_endswithcharignorecase(const char *const buffer_arg, const char checkon_arg) {
    if (buffer_arg == NULL) {
        return false;
    }

    if (strlen(buffer_arg) < 1) {
        return false;
    }

    return tolower(buffer_arg[strlen(buffer_arg) - 1]) == tolower(checkon_arg);
}


void unstdstring_tolowerstr(char *const buffer_arg) {
    for (size_t i = 0; buffer_arg[i] != '\0'; buffer_arg[i] = (char) tolower(buffer_arg[i]), i++);
}


char *unstdstring_tolowerstrcopy(const char *const buffer_arg) {
    if (buffer_arg == NULL) {
        return NULL;
    }

    char *allocationPtr = (char *) calloc(strlen(buffer_arg) + 1, sizeof(char));
    if (allocationPtr == NULL) {
        return NULL;
    }

    for (size_t i = 0; buffer_arg[i] != '\0'; allocationPtr[i] = (char) tolower(buffer_arg[i]), i++) {
        if (buffer_arg[i] == '\0') { allocationPtr[i] = '\0'; }
    }

    return allocationPtr;
}


void unstdstring_tolowerstrarray(char (*const buffer_arg)[]) {
    for (size_t i = 0; (*buffer_arg)[i]; i++) { (*buffer_arg)[i] = (char) tolower((*buffer_arg)[i]); }
}


void unstdstring_toupperstr(char *const buffer_arg) {
    for (size_t i = 0; buffer_arg[i] != '\0'; buffer_arg[i] = (char) toupper(buffer_arg[i]), i++);
}


char *unstdstring_toupperstrcopy(const char *const buffer_arg) {
    if (buffer_arg == NULL) {
        return NULL;
    }

    char *allocationPtr = (char *) calloc(strlen(buffer_arg) + 1, sizeof(char));
    if (allocationPtr == NULL) {
        return NULL;
    }

    for (size_t i = 0; buffer_arg[i] != '\0'; allocationPtr[i] = (char) toupper(buffer_arg[i]), i++) {
        if (buffer_arg[i] == '\0') { allocationPtr[i] = '\0'; }
    }

    return allocationPtr;
}


void unstdstring_toupperstrarray(char (*const buffer_arg)[]) {
    for (size_t i = 0; (*buffer_arg)[i]; i++) { (*buffer_arg)[i] = (char) toupper((*buffer_arg)[i]); }
}


bool unstdstring_isasciicontrolchar(const u8 buffer_arg) {
    return buffer_arg >= 0 && buffer_arg <= 31 || buffer_arg == 127;
}


bool unstdstring_isasciiprintablechar(const u8 buffer_arg) {
    return buffer_arg >= 32 && buffer_arg <= 126;
}


bool unstdstring_isasciiextendedchar(const u8 buffer_arg) {
    return buffer_arg >= 128 && buffer_arg <= 255;
}

bool unstdstring_isasciivisiblechar(const u8 buffer_arg) {
    return unstdstring_isasciiprintablechar(buffer_arg) || unstdstring_isasciiextendedchar(buffer_arg);
}

bool unstdstring_isasciichar(const u8 buffer_arg) {
    return buffer_arg >= 0 && buffer_arg <= 255;
}

bool unstdstring_isalphabeticchar(const u8 buffer_arg) {
    return buffer_arg >= 'a' && buffer_arg <= 'z' || buffer_arg >= 'A' && buffer_arg <= 'Z';
}


bool unstdstring_isalphanumericchar(const u8 buffer_arg) {
    return unstdstring_isalphabeticchar(buffer_arg) || buffer_arg >= '0' && buffer_arg <= '9';
}


bool unstdstring_isdigitchar(const u8 buffer_arg) {
    return buffer_arg >= '0' && buffer_arg <= '9';
}


bool unstdstring_ishexchar(const u8 buffer_arg) {
    return unstdstring_isdigitchar(buffer_arg) || buffer_arg >= 'a' && buffer_arg <= 'f' ||
           buffer_arg >= 'A' && buffer_arg <= 'F';
}


bool unstdstring_iswhitespace(const u8 buffer_arg) {
    return buffer_arg == 32 || buffer_arg == 9
           || buffer_arg == 10 || buffer_arg == 11
           || buffer_arg == 12 || buffer_arg == 13;
}


u8 _unstdstring_bufferextend(void *buffer_arg, const u64 bytes_arg) {
    if (buffer_arg == NULL) {
        return 2;
    }

    if (bytes_arg < 1) {
        return 3;
    }

    const size_t size_buffer_arg = strlen(buffer_arg);
    char *realloc_result = (char *) realloc(
            (void *) buffer_arg,
            size_buffer_arg + bytes_arg + 1
    );
    if (realloc_result == NULL) {
        return 0;
    }

    if (memset(buffer_arg + size_buffer_arg, 0, bytes_arg + 1) == NULL) {
        return 4;
    }

    return 1;
}


u8 _unstdstring_buffershrink(void *buffer_arg, const u64 bytes_arg) {
    if (buffer_arg == NULL) {
        return 2;
    }

    if (bytes_arg < 1) {
        return 3;
    }

    const size_t size_buffer_arg = strlen(buffer_arg);
    if (size_buffer_arg < 1) {
        return 4;
    }

    if (bytes_arg > size_buffer_arg) {
        return 5;
    }

    char *realloc_result = (char *) realloc(
            (void *) buffer_arg,
            size_buffer_arg == bytes_arg ? 1 : size_buffer_arg - bytes_arg
    );
    if (realloc_result == NULL) {
        return 0;
    }

    if (memset(buffer_arg + size_buffer_arg - bytes_arg, 0, bytes_arg + 1) == NULL) {
        return 6;
    }

    return 1;
}


char *unstdstring_bufferstringinit8(const char *const buffer_arg, u8 *const out_error_arg) {
    char *buffer = NULL;

    size_t size_buffer_arg = buffer_arg == NULL ? 0 : strlen(buffer_arg);

    buffer = (char *) malloc(size_buffer_arg + 1);
    if (buffer == NULL) {
        if (out_error_arg != NULL) {
            *out_error_arg = 0;
            return NULL;
        }
    }

    if (memset(buffer, 0, size_buffer_arg + 1) == NULL) {
        if (out_error_arg != NULL) {
            *out_error_arg = 2;
            return NULL;
        }
    }

    if (buffer_arg != NULL) {
        if (!unstdstring_strcmp(strcpy(buffer, buffer_arg), buffer_arg)) {
            if (out_error_arg != NULL) {
                *out_error_arg = 3;
                return NULL;
            }
        }
    }

    if (out_error_arg != NULL) {
        *out_error_arg = 1;
    }

    return buffer;
}


u8 unstdstring_bufferclear(void *const buffer_arg) {
    if (buffer_arg == NULL) {
        return 2;
    }

    return _unstdstring_buffershrink(buffer_arg, strlen(buffer_arg)) == 1 ? 1 : 3;
}


u8 unstdstring_pushchar8(void *const to_buffer_arg, const u8 from_buffer_arg) {
    if (to_buffer_arg == NULL) {
        return 2;
    }

    if (_unstdstring_bufferextend(to_buffer_arg, sizeof(u8)) != 1) {
        return 0;
    }
    const size_t size_to_buffer_arg = strlen(to_buffer_arg);

    ((u8 *) to_buffer_arg)[size_to_buffer_arg] = from_buffer_arg;
    ((u8 *) to_buffer_arg)[size_to_buffer_arg + 1] = 0;
    return 1;
}


u8 unstdstring_popchar8(void *const buffer_arg, u8 *const out_error_arg) {
    if (buffer_arg == NULL) {
        if (out_error_arg != NULL) {
            *out_error_arg = 2;
            return 0;
        }
    }

    u8 temp_char_holder = ((u8 *) buffer_arg)[strlen(buffer_arg) - 1];

    if (_unstdstring_buffershrink(buffer_arg, sizeof(u8)) != 1) {
        if (out_error_arg != NULL) {
            *out_error_arg = 0;
            return 0;
        }
    }

    if (out_error_arg != NULL) {
        *out_error_arg = 1;
    }
    return temp_char_holder;
}


u8 unstdstring_pushchar16(void *const to_buffer_arg, const u16 from_buffer_arg) {
    if (to_buffer_arg == NULL) {
        return 2;
    }

    if (_unstdstring_bufferextend(to_buffer_arg, sizeof(u16)) != 1) {
        return 0;
    }

    const u64l size_to_buffer_arg = unstdstring_strlen16(to_buffer_arg);

    ((u16 *) to_buffer_arg)[size_to_buffer_arg] = from_buffer_arg;
    ((u16 *) to_buffer_arg)[size_to_buffer_arg + 1] = 0;

    return 1;
}


u8 unstdstring_appendstr(void *const to_buffer_arg, const char *const from_buffer_arg) {
    if (to_buffer_arg == NULL) {
        return 2;
    }

    if (from_buffer_arg == NULL) {
        return 3;
    }

    size_t length_from_buffer_arg_temp = strlen(from_buffer_arg);
    if (!_unstdstring_bufferextend(to_buffer_arg, length_from_buffer_arg_temp)) {
        return 0;
    }

    strcat(to_buffer_arg, from_buffer_arg);

    return 1;
}