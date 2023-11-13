#include "unstdstring.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool unstdstring_charcmp(const u8 fBufferArg, const u8 sBufferArg) {
    return fBufferArg == sBufferArg;
}


bool unstdstring_strcmp(const char *const fBufferArg, const char *const sBufferArg) {
    return fBufferArg != NULL && sBufferArg != NULL ? !strcmp(fBufferArg, sBufferArg) : false;
}


bool unstdstring_strcmpignorecase(const char *const fBufferArg, const char *const sBufferArg) {
    if (fBufferArg == NULL && sBufferArg == NULL) {
        return false;
    }

    char *lowered_fBufferArg = unstdstring_tolowerstrcopy(fBufferArg);
    char *lowered_sBufferArg = unstdstring_tolowerstrcopy(sBufferArg);
    bool strcmp_result = unstdstring_strcmp(lowered_fBufferArg, lowered_sBufferArg);
    free(lowered_sBufferArg);
    free(lowered_fBufferArg);
    return strcmp_result;
}


bool unstdstring_startswithchar(const char *const bufferArg, const char checkOnArg) {
    if (bufferArg == NULL) {
        return false;
    }

    if (strlen(bufferArg) < 1) {
        return false;
    }

    return *bufferArg == checkOnArg;
}


bool unstdstring_startswithcharignorecase(const char *const bufferArg, const char checkOnArg) {
    if (bufferArg == NULL) {
        return false;
    }

    if (strlen(bufferArg) < 1) {
        return false;
    }

    return tolower(*bufferArg) == tolower(checkOnArg);
}


bool unstdstring_endswithchar(const char *const bufferArg, const char checkOnArg) {
    if (bufferArg == NULL) {
        return false;
    }

    if (strlen(bufferArg) < 1) {
        return false;
    }

    return bufferArg[strlen(bufferArg) - 1] == checkOnArg;
}


bool unstdstring_endswithcharignorecase(const char *const bufferArg, const char checkOnArg) {
    if (bufferArg == NULL) {
        return false;
    }

    if (strlen(bufferArg) < 1) {
        return false;
    }

    return tolower(bufferArg[strlen(bufferArg) - 1]) == tolower(checkOnArg);
}


void unstdstring_tolowerstr(char *const bufferArg) {
    for (size_t i = 0; bufferArg[i] != '\0'; bufferArg[i] = (char) tolower(bufferArg[i]), i++);
}


char *unstdstring_tolowerstrcopy(const char *const bufferArg) {
    if (bufferArg == NULL) {
        return NULL;
    }

    char *allocationPtr = (char *) calloc(strlen(bufferArg) + 1, sizeof(char));
    if (allocationPtr == NULL) {
        return NULL;
    }

    for (size_t i = 0; bufferArg[i] != '\0'; allocationPtr[i] = (char) tolower(bufferArg[i]), i++) {
        if (bufferArg[i] == '\0') { allocationPtr[i] = '\0'; }
    }

    return allocationPtr;
}


void unstdstring_tolowerstrarray(char (*const bufferArg)[]) {
    for (size_t i = 0; (*bufferArg)[i]; i++) { (*bufferArg)[i] = (char) tolower((*bufferArg)[i]); }
}


void unstdstring_toupperstr(char *const bufferArg) {
    for (size_t i = 0; bufferArg[i] != '\0'; bufferArg[i] = (char) toupper(bufferArg[i]), i++);
}


char *unstdstring_toupperstrcopy(const char *const bufferArg) {
    if (bufferArg == NULL) {
        return NULL;
    }

    char *allocationPtr = (char *) calloc(strlen(bufferArg) + 1, sizeof(char));
    if (allocationPtr == NULL) {
        return NULL;
    }

    for (size_t i = 0; bufferArg[i] != '\0'; allocationPtr[i] = (char) toupper(bufferArg[i]), i++) {
        if (bufferArg[i] == '\0') { allocationPtr[i] = '\0'; }
    }

    return allocationPtr;
}


void unstdstring_toupperstrarray(char (*const bufferArg)[]) {
    for (size_t i = 0; (*bufferArg)[i]; i++) { (*bufferArg)[i] = (char) toupper((*bufferArg)[i]); }
}


bool unstdstring_isasciicontrolchar(const u8 bufferArg) {
    return bufferArg >= 0 && bufferArg <= 31 || bufferArg == 127;
}


bool unstdstring_isasciiprintablechar(const u8 bufferArg) {
    return bufferArg >= 32 && bufferArg <= 126;
}


bool unstdstring_isasciiextendedchar(const u8 bufferArg) {
    return bufferArg >= 128 && bufferArg <= 255;
}


bool unstdstring_isalphabeticchar(const u8 bufferArg) {
    return bufferArg >= 'a' && bufferArg <= 'z' || bufferArg >= 'A' && bufferArg <= 'Z';
}


bool unstdstring_isalphanumericchar(const u8 bufferArg) {
    return unstdstring_isalphabeticchar(bufferArg) || bufferArg >= '0' && bufferArg <= '9';
}


bool unstdstring_isdigitchar(const u8 bufferArg) {
    return bufferArg >= '0' && bufferArg <= '9';
}


bool unstdstring_ishexchar(const u8 bufferArg) {
    return unstdstring_isdigitchar(bufferArg) || bufferArg >= 'a' && bufferArg <= 'f' ||
           bufferArg >= 'A' && bufferArg <= 'F';
}


bool unstdstring_iswhitespace(const u8 bufferArg) {
    return bufferArg == 32 || bufferArg == 9
           || bufferArg == 10 || bufferArg == 11
           || bufferArg == 12 || bufferArg == 13;
}


u8 _unstdstring_bufferextend(void *bufferArg, const u64 sizeArg) {
    if (bufferArg == NULL) {
        return 2;
    }

    if (sizeArg < 1) {
        return 3;
    }

    const size_t size_bufferArg = strlen(bufferArg);
    char *realloc_result = (char *) realloc(
            (void *) bufferArg,
            size_bufferArg + sizeArg + 1
    );
    if (realloc_result == NULL) {
        return 0;
    }

    if (memset(bufferArg + size_bufferArg, 0, sizeArg + 1) == NULL) {
        return 4;
    }

    return 1;
}


u8 _unstdstring_buffershrink(void *bufferArg, const u64 sizeArg) {
    if (bufferArg == NULL) {
        return 2;
    }

    if (sizeArg < 1) {
        return 3;
    }

    const size_t size_bufferArg = strlen(bufferArg);
    if (size_bufferArg < 1) {
        return 4;
    }

    if (sizeArg > size_bufferArg) {
        return 5;
    }

    char *realloc_result = (char *) realloc(
            (void *) bufferArg,
            size_bufferArg == sizeArg ? 1 : size_bufferArg - sizeArg
    );
    if (realloc_result == NULL) {
        return 0;
    }

    if (memset(bufferArg + size_bufferArg - sizeArg, 0, sizeArg + 1) == NULL) {
        return 6;
    }

    return 1;
}


char *unstdstring_bufferstringinit(const char *const bufferArg, u8 *const outErrorArg) {
    char *buffer = NULL;

    size_t size_bufferArg = bufferArg == NULL ? 0 : strlen(bufferArg);

    buffer = (char *) malloc(size_bufferArg + 1);
    if (buffer == NULL) {
        if (outErrorArg != NULL) {
            *outErrorArg = 0;
            return NULL;
        }
    }

    if (memset(buffer, 0, size_bufferArg + 1) == NULL) {
        if (outErrorArg != NULL) {
            *outErrorArg = 2;
            return NULL;
        }
    }

    if (bufferArg != NULL) {
        if (!unstdstring_strcmp(strcpy(buffer, bufferArg), bufferArg)) {
            if (outErrorArg != NULL) {
                *outErrorArg = 3;
                return NULL;
            }
        }
    }

    if (outErrorArg != NULL) {
        *outErrorArg = 1;
    }

    return buffer;
}


u8 unstdstring_bufferclear(void *const bufferArg) {
    if (bufferArg == NULL) {
        return 2;
    }

    return _unstdstring_buffershrink(bufferArg, strlen(bufferArg)) == 1 ? 1 : 3;
}


u8 unstdstring_pushchar8(void *const toBufferArg, const u8 fromBufferArg) {
    if (toBufferArg == NULL) {
        return 2;
    }

    if (_unstdstring_bufferextend(toBufferArg, 1) != 1) {
        return 0;
    }
    const size_t size_toBufferArg = strlen(toBufferArg);

    ((u8 *) toBufferArg)[size_toBufferArg] = fromBufferArg;
    ((u8 *) toBufferArg)[size_toBufferArg + 1] = 0;
    return 1;
}


u8 unstdstring_popchar8(void *const bufferArg, u8 *const outErrorArg) {
    if (bufferArg == NULL) {
        if (outErrorArg != NULL) {
            *outErrorArg = 2;
            return 0;
        }
    }

    u8 temp_char_holder = ((u8 *) bufferArg)[strlen(bufferArg) - 1];

    if (_unstdstring_buffershrink(bufferArg, 1) != 1) {
        if (outErrorArg != NULL) {
            *outErrorArg = 0;
            return 0;
        }
    }

    if (outErrorArg != NULL) {
        *outErrorArg = 1;
    }
    return temp_char_holder;
}


u8 unstdstring_appendstr(void *const toBufferArg, const char *const fromBufferArg) {
    if (toBufferArg == NULL) {
        return 2;
    }

    if (fromBufferArg == NULL) {
        return 3;
    }

    size_t length_fromBufferArg_temp = strlen(fromBufferArg);
    if (!_unstdstring_bufferextend(toBufferArg, length_fromBufferArg_temp)) {
        return 0;
    }

    strcat(toBufferArg, fromBufferArg);

    return 1;
}