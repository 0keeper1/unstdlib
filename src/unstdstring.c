#include "unstdstring.h"


/**
 *
 * @param fBufferArg a pointer to a null-terminated buffer
 * @param sBufferArg a pointer to a null-terminated buffer
 * @return true if both buffers are identical to each other otherwise false
 */
bool unstd_strcmp(const char *const fBufferArg, const char *const sBufferArg) {
    return fBufferArg != NULL && sBufferArg != NULL ? !strcmp(fBufferArg, sBufferArg) : false;
}

/**
 *
 * @param bufferArg a pointer to a null-terminated buffer
 * @param checkOnArg the character which the function performs the operation on
 * @return a boolean indicating the state of operation
 */
bool unstd_endswith(const char *const bufferArg, const char checkOnArg) {
    return bufferArg[strlen(bufferArg) - 1] == checkOnArg ? true : false;
}

/**
 *
 * @param bufferArg a pointer to a null-terminated buffer
 * @param checkOnArg the character which the function performs the operation on
 * @return a boolean indicating the state of operation
 */
bool unstd_endswithignorecase(const char *const bufferArg, const char checkOnArg) {
    return tolower(bufferArg[strlen(bufferArg) - 1]) == tolower(checkOnArg) ? true : false;
}

/**
 *
 * @param bufferArg should be a pointer to a null-terminated heap-allocated / c-array buffer
 * @return a pointer to the first character of the modified buffer
 */
void unstd_tolowerstr(char *const bufferArg) {
    for (size_t i = 0; bufferArg[i] != '\0'; bufferArg[i] = (char) tolower(bufferArg[i]), i++);
}

/**
 *
 * @param bufferArg should be a pointer to a null-terminated heap-allocated / c-array / constant buffer
 * @return a pointer to the first character of the modified buffer
 */
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

/**
 *
 * @param bufferArg should be a reference to a null-terminated c-array of characters
 * @return a pointer to the first character of the modified buffer
 */
void unstd_tolowerstrarray(char (*const bufferArg)[]) {
    for (size_t i = 0; (*bufferArg)[i]; i++) { (*bufferArg)[i] = (char) tolower((*bufferArg)[i]); }
}

/**
 *
 * @param bufferArg should be a pointer to a null-terminated heap-allocated / c-array buffer
 * @return a pointer to the first character of the modified buffer
 */
void unstd_toupperstr(char *const bufferArg) {
    for (size_t i = 0; bufferArg[i] != '\0'; bufferArg[i] = (char) toupper(bufferArg[i]), i++);
}

/**
 *
 * @param bufferArg should be a pointer to a null-terminated heap-allocated / c-array buffer
 * @return a pointer to the first character of the modified buffer
 */
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

/**
 *
 * @param bufferArg should be a reference to a null-terminated c-array of characters
 * @return a pointer to the first character of the modified buffer
 */
void unstd_toupperstrarray(char (*const bufferArg)[]) {
    for (size_t i = 0; (*bufferArg)[i]; i++) { (*bufferArg)[i] = (char) toupper((*bufferArg)[i]); }
}

/**
 *
 * @param bufferArg should be an ascii character
 * @return whether a character is an ASCII control characters or not
 */
bool unstd_isasciicontrolcharacter(const unsigned char bufferArg) {
    return bufferArg >= 0 && bufferArg <= 31 || bufferArg == 127 ? true : false;
}

