#include "unstdstring.h"


bool unstd_charcmp(const unsigned char fBufferArg, const unsigned char sBufferArg) {
    return fBufferArg == sBufferArg;
}


bool unstd_strcmp(const char *const fBufferArg, const char *const sBufferArg) {
    return fBufferArg != NULL && sBufferArg != NULL ? !strcmp(fBufferArg, sBufferArg) : false;
}


bool unstd_strcmpignorecase(const char *const fBufferArg, const char *const sBufferArg) {
    if (fBufferArg == NULL && sBufferArg == NULL) {
        return false;
    }

    char *lowered_fBufferArg = unstd_tolowerstrcopy(fBufferArg);
    char *lowered_sBufferArg = unstd_tolowerstrcopy(sBufferArg);
    bool strcmp_result = unstd_strcmp(lowered_fBufferArg, lowered_sBufferArg);
    free(lowered_sBufferArg);
    free(lowered_fBufferArg);
    return strcmp_result;
}


bool unstd_startswithchar(const char *const bufferArg, const char checkOnArg) {
    if (bufferArg == NULL) {
        return false;
    }

    if (strlen(bufferArg) < 1) {
        return false;
    }

    return *bufferArg == checkOnArg;
}


bool unstd_startswithcharignorecase(const char *const bufferArg, const char checkOnArg) {
    if (bufferArg == NULL) {
        return false;
    }

    if (strlen(bufferArg) < 1) {
        return false;
    }

    return tolower(*bufferArg) == tolower(checkOnArg);
}


bool unstd_endswithchar(const char *const bufferArg, const char checkOnArg) {
    if (bufferArg == NULL) {
        return false;
    }

    if (strlen(bufferArg) < 1) {
        return false;
    }

    return bufferArg[strlen(bufferArg) - 1] == checkOnArg;
}


bool unstd_endswithcharignorecase(const char *const bufferArg, const char checkOnArg) {
    if (bufferArg == NULL) {
        return false;
    }

    if (strlen(bufferArg) < 1) {
        return false;
    }

    return tolower(bufferArg[strlen(bufferArg) - 1]) == tolower(checkOnArg);
}


void unstd_tolowerstr(char *const bufferArg) {
    for (size_t i = 0; bufferArg[i] != '\0'; bufferArg[i] = (char) tolower(bufferArg[i]), i++);
}


char *unstd_tolowerstrcopy(const char *const bufferArg) {
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


void unstd_tolowerstrarray(char (*const bufferArg)[]) {
    for (size_t i = 0; (*bufferArg)[i]; i++) { (*bufferArg)[i] = (char) tolower((*bufferArg)[i]); }
}


void unstd_toupperstr(char *const bufferArg) {
    for (size_t i = 0; bufferArg[i] != '\0'; bufferArg[i] = (char) toupper(bufferArg[i]), i++);
}


char *unstd_toupperstrcopy(const char *const bufferArg) {
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


void unstd_toupperstrarray(char (*const bufferArg)[]) {
    for (size_t i = 0; (*bufferArg)[i]; i++) { (*bufferArg)[i] = (char) toupper((*bufferArg)[i]); }
}


bool unstd_isasciicontrolchar(const unsigned char bufferArg) {
    return bufferArg >= 0 && bufferArg <= 31 || bufferArg == 127;
}


bool unstd_isasciiprintablechar(const unsigned char bufferArg) {
    return bufferArg >= 32 && bufferArg <= 126;
}


bool unstd_isasciiextendedchar(const unsigned char bufferArg) {
    return bufferArg >= 128 && bufferArg <= 255;
}


bool unstd_isalphabeticchar(const unsigned char bufferArg) {
    return bufferArg >= 'a' && bufferArg <= 'z' || bufferArg >= 'A' && bufferArg <= 'Z';
}


bool unstd_isalphanumericchar(const unsigned char bufferArg) {
    return unstd_isalphabeticchar(bufferArg) || bufferArg >= '0' && bufferArg <= '9';
}


bool unstd_isdigitchar(const unsigned char bufferArg) {
    return bufferArg >= '0' && bufferArg <= '9';
}


bool unstd_ishexchar(const unsigned char bufferArg) {
    return unstd_isdigitchar(bufferArg) || bufferArg >= 'a' && bufferArg <= 'f' || bufferArg >= 'A' && bufferArg <= 'F';
}


bool unstd_iswhitespace(const unsigned char bufferArg) {
    return bufferArg == 32 || bufferArg == 9
           || bufferArg == 10 || bufferArg == 11
           || bufferArg == 12 || bufferArg == 13;
}

//! [string]
bool _unstd_stringextend(unstd_string *const stringEntityArg, const unsigned long sizeArg) {
    if (!stringEntityArg) {
        return false;
    }

    void *buffer_holder = realloc(stringEntityArg->buffer, stringEntityArg->length + sizeArg + 1);
    if (buffer_holder == NULL) {
        return false;
    }

    stringEntityArg->buffer = (char *) buffer_holder;
    stringEntityArg->length += sizeArg;
    return true;
}


bool _unstd_stringshrink(unstd_string *const stringEntityArg, const unsigned long sizeArg) {
    if (!stringEntityArg) {
        return false;
    }

    void *buffer_holder = realloc(stringEntityArg->buffer, stringEntityArg->length - sizeArg - 1);
    if (buffer_holder == NULL) {
        return false;
    }

    stringEntityArg->buffer = (char *) buffer_holder;
    stringEntityArg->length -= sizeArg;
    return true;
}


unstd_string unstd_stringinit(const char *const bufferArg) {
    unstd_string string_temp = {
            .length = 0,
            .buffer = NULL
    };

    if (bufferArg != NULL) {
        string_temp.length = strlen(bufferArg);
        string_temp.buffer = (char *) malloc(string_temp.length + 1);
        if (string_temp.buffer == NULL) {
            return string_temp;
        }
        memset(string_temp.buffer, 0, string_temp.length + 1);
        strcpy(string_temp.buffer, bufferArg);
    }

    return string_temp;
}


void unstd_stringfree(const unstd_string *const stringEntityArg) {
    if (!stringEntityArg) {
        return;
    }

    free(stringEntityArg->buffer);
}


void unstd_stringpushchar(unstd_string *const stringEntityArg, const unsigned char bufferArg) {
    if (!stringEntityArg) {
        return;
    }

    if (!_unstd_stringextend(stringEntityArg, 1)) {
        return;
    }

    stringEntityArg->buffer[stringEntityArg->length - 1] = (char) bufferArg;
}


char unstd_stringpopchar(unstd_string *const stringEntityArg) {
    if (!stringEntityArg) {
        return -1;
    }

    char temp_char_holder = stringEntityArg->buffer[stringEntityArg->length - 1];
    stringEntityArg->buffer[stringEntityArg->length - 1] = '\0';

    if (!_unstd_stringshrink(stringEntityArg, 1)) {
        return -1;
    }

    return temp_char_holder;
}


bool unstd_stringappendstr(unstd_string *const stringEntityArg, const char *const bufferArg) {
    if (!stringEntityArg) {
        return false;
    }

    if (!bufferArg) {
        return false;
    }

    size_t length_bufferArg_temp = strlen(bufferArg);

    if (!_unstd_stringextend(stringEntityArg, length_bufferArg_temp)) {
        return false;
    }

    strcat(stringEntityArg->buffer, bufferArg);

    return true;
}