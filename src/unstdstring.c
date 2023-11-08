#include "unstdstring.h"


bool unstdstring_charcmp(const unsigned char fBufferArg, const unsigned char sBufferArg) {
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


bool unstdstring_isasciicontrolchar(const unsigned char bufferArg) {
    return bufferArg >= 0 && bufferArg <= 31 || bufferArg == 127;
}


bool unstdstring_isasciiprintablechar(const unsigned char bufferArg) {
    return bufferArg >= 32 && bufferArg <= 126;
}


bool unstdstring_isasciiextendedchar(const unsigned char bufferArg) {
    return bufferArg >= 128 && bufferArg <= 255;
}


bool unstdstring_isalphabeticchar(const unsigned char bufferArg) {
    return bufferArg >= 'a' && bufferArg <= 'z' || bufferArg >= 'A' && bufferArg <= 'Z';
}


bool unstdstring_isalphanumericchar(const unsigned char bufferArg) {
    return unstdstring_isalphabeticchar(bufferArg) || bufferArg >= '0' && bufferArg <= '9';
}


bool unstdstring_isdigitchar(const unsigned char bufferArg) {
    return bufferArg >= '0' && bufferArg <= '9';
}


bool unstdstring_ishexchar(const unsigned char bufferArg) {
    return unstdstring_isdigitchar(bufferArg) || bufferArg >= 'a' && bufferArg <= 'f' || bufferArg >= 'A' && bufferArg <= 'F';
}


bool unstdstring_iswhitespace(const unsigned char bufferArg) {
    return bufferArg == 32 || bufferArg == 9
           || bufferArg == 10 || bufferArg == 11
           || bufferArg == 12 || bufferArg == 13;
}

//! [string]
bool _unstdstring_stringextend(unstdstring_string *const stringEntityArg, const unsigned long sizeArg) {
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


bool _unstdstring_stringshrink(unstdstring_string *const stringEntityArg, const unsigned long sizeArg) {
    if (!stringEntityArg) {
        return false;
    }

    void *buffer_holder = realloc(
            stringEntityArg->buffer,
            stringEntityArg->length == sizeArg ? 1 : stringEntityArg->length - sizeArg - 1);
    if (buffer_holder == NULL) {
        return false;
    }

    stringEntityArg->buffer = (char *) buffer_holder;
    stringEntityArg->length -= sizeArg;
    return true;
}


unstdstring_string unstdstring_stringinit(const char *const bufferArg) {
    unstdstring_string string_temp = {
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


void unstdstring_stringfree(const unstdstring_string *const stringEntityArg) {
    if (!stringEntityArg) {
        return;
    }

    free(stringEntityArg->buffer);
}


void unstdstring_stringclear(unstdstring_string *const stringEntityArg) {
    if (!stringEntityArg) {
        return;
    }


    memset(stringEntityArg->buffer, 0, stringEntityArg->length + 1);

    if (!_unstdstring_stringshrink(stringEntityArg, stringEntityArg->length)) {
        return;
    }
}


void unstdstring_stringpushchar(unstdstring_string *const stringEntityArg, const unsigned char bufferArg) {
    if (!stringEntityArg) {
        return;
    }

    if (!_unstdstring_stringextend(stringEntityArg, 1)) {
        return;
    }

    stringEntityArg->buffer[stringEntityArg->length - 1] = (char) bufferArg;
}


char unstdstring_stringpopchar(unstdstring_string *const stringEntityArg) {
    if (!stringEntityArg) {
        return -1;
    }

    char temp_char_holder = stringEntityArg->buffer[stringEntityArg->length - 1];
    stringEntityArg->buffer[stringEntityArg->length - 1] = '\0';

    if (!_unstdstring_stringshrink(stringEntityArg, 1)) {
        return -1;
    }

    return temp_char_holder;
}


bool unstdstring_stringappendstr(unstdstring_string *const stringEntityArg, const char *const bufferArg) {
    if (!stringEntityArg) {
        return false;
    }

    if (!bufferArg) {
        return false;
    }

    size_t length_bufferArg_temp = strlen(bufferArg);

    if (!_unstdstring_stringextend(stringEntityArg, length_bufferArg_temp)) {
        return false;
    }

    strcat(stringEntityArg->buffer, bufferArg);

    return true;
}