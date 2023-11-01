#include "unstdstring.h"


bool unstd_strcmp(const char *const fBufferArg, const char *const sBufferArg) {
    return fBufferArg != NULL && sBufferArg != NULL ? !strcmp(fBufferArg, sBufferArg) : false;
}


bool unstd_endswithchar(const char *const bufferArg, const char checkOnArg) {
    return bufferArg[strlen(bufferArg) - 1] == checkOnArg;
}


bool unstd_endswithcharignorecase(const char *const bufferArg, const char checkOnArg) {
    return tolower(bufferArg[strlen(bufferArg) - 1]) == tolower(checkOnArg);
}


void unstd_tolowerstr(char *const bufferArg) {
    for (size_t i = 0; bufferArg[i] != '\0'; bufferArg[i] = (char) tolower(bufferArg[i]), i++);
}


char *unstd_tolowerstrcopy(const char *const bufferArg) {
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
    size_t strLength = strlen(bufferArg);
    char *allocationPtr = (char *) calloc(strLength + 1, sizeof(char));
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
