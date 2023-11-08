#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


//! [string]
typedef struct {
    unsigned long int length;
    char *buffer;
} unstd_string;

/**
 * __INTERNAL__
 * extends the buffer by reallocating it according to the `sizeArg` param
 * @param stringEntityArg should be a pointer to a valid string entity
 * @param sizeArg amount of bytes to extend the buffer by
 * @return a boolean indicating the state of operation
 */
bool _unstd_stringextend(unstd_string *const stringEntityArg, const unsigned long int sizeArg);

/**
 * __INTERNAL__
 * shrink downs the buffer by reallocating it according to the `sizeArg` param
 * @param stringEntityArg should be a pointer to a valid string entity
 * @param sizeArg amount of bytes to shrink the buffer by
 */
bool _unstd_stringshrink(unstd_string *const stringEntityArg, const unsigned long int sizeArg);

/**
 * Declares and initializes a string entity
 * @param bufferArg gets assigned to the string after declaration. Pass `NULL` for nothing
 * @return a string entity
 */
unstd_string unstd_stringinit(const char *const bufferArg);

/**
 * frees the heap-allocated memory by string entity inside the `buffer` pointer
 * @param stringEntityArg should be a pointer to a valid string entity
 */
void unstd_stringfree(const unstd_string *const stringEntityArg);

/**
 * zeros all the bytes in buffer
 * @param stringEntityArg should be a pointer to a valid string entity
 */
void unstd_stringclear(unstd_string *const stringEntityArg);

/**
 * appends a character at the end of the string buffer
 * @param stringEntityArg should be a pointer to a valid string entity
 * @param bufferArg a character
 */
void unstd_stringpushchar(unstd_string *const stringEntityArg, const unsigned char bufferArg);

/**
 * pops back the last character from buffer
 * @param stringEntityArg should be a pointer to a valid string entity
 * @return the popped character from the end
 */
char unstd_stringpopchar(unstd_string *const stringEntityArg);

/**
 * appends a string to the buffer
 * @param stringEntityArg should be a pointer to a valid string entity
 * @param bufferArg a pointer to a null-terminated buffer
 * @return a boolean indicating the state of operation
 */
bool unstd_stringappendstr(unstd_string *const stringEntityArg, const char *const bufferArg);


//! [compare]
/**
 *
 * @param fBufferArg should be a character
 * @param sBufferArg should be a character
 * @return true if both buffers are identical to each other otherwise false
 */
bool unstd_charcmp(const unsigned char fBufferArg, const unsigned char sBufferArg);

/**
 *
 * @param fBufferArg a pointer to a null-terminated buffer
 * @param sBufferArg a pointer to a null-terminated buffer
 * @return true if both buffers are identical to each other otherwise false
 */
bool unstd_strcmp(const char *const fBufferArg, const char *const sBufferArg);

/**
 *
 * @param fBufferArg a pointer to a null-terminated buffer
 * @param sBufferArg a pointer to a null-terminated buffer
 * @return true if both buffers are identical to each other otherwise false
 */
bool unstd_strcmpignorecase(const char *const fBufferArg, const char *const sBufferArg);


//! [startswith]
/**
 *
 * @param bufferArg a pointer to a null-terminated buffer
 * @param checkOnArg the character which the function performs the operation on
 * @return a boolean indicating the state of operation
 */
bool unstd_startswithchar(const char *const bufferArg, const char checkOnArg);

/**
 *
 * @param bufferArg should be a pointer to a null-terminated heap-allocated / c-array buffer
 * @param checkOnArg the character which the function performs the operation on
 * @return a pointer to the first character of the modified buffer
 */
bool unstd_startswithcharignorecase(const char *const bufferArg, const char checkOnArg);


//! [endswith]
/**
 *
 * @param bufferArg a pointer to a null-terminated buffer
 * @param checkOnArg the character which the function performs the operation on
 * @return a boolean indicating the state of operation
 */
bool unstd_endswithchar(const char *const bufferArg, const char checkOnArg);

/**
 *
 * @param bufferArg should be a pointer to a null-terminated heap-allocated / c-array buffer
 * @param checkOnArg the character which the function performs the operation on
 * @return a pointer to the first character of the modified buffer
 */
bool unstd_endswithcharignorecase(const char *const bufferArg, const char checkOnArg);


//! [tolower]
/**
 *
 * @param bufferArg should be a pointer to a null-terminated heap-allocated / c-array buffer
 * @return a pointer to the first character of the modified buffer
 */
void unstd_tolowerstr(char *const bufferArg);

/**
 *
 * @param bufferArg should be a pointer to a null-terminated heap-allocated / c-array / constant buffer
 * @return a pointer to the first character of the modified buffer
 */
char *unstd_tolowerstrcopy(const char *const bufferArg);

/**
 *
 * @param bufferArg should be a reference to a null-terminated c-array of characters
 * @return a pointer to the first character of the modified buffer
 */
void unstd_tolowerstrarray(char (*const bufferArg)[]);


//! [toupper]
/**
 *
 * @param bufferArg should be a pointer to a null-terminated heap-allocated / c-array buffer
 * @return a pointer to the first character of the modified buffer
 */
void unstd_toupperstr(char *const bufferArg);

/**
 *
 * @param bufferArg should be a pointer to a null-terminated heap-allocated / c-array buffer
 * @return a pointer to the first character of the modified buffer
 */
char *unstd_toupperstrcopy(const char *const bufferArg);

/**
 *
 * @param bufferArg should be a reference to a null-terminated c-array of characters
 * @return a pointer to the first character of the modified buffer
 */
void unstd_toupperstrarray(char (*const bufferArg)[]);


//! [is]
//! [isascii]
/**
 *
 * @param bufferArg should be an ascii character
 * @return whether a character is an ASCII control character or not
 */
bool unstd_isasciicontrolchar(const unsigned char bufferArg);

/**
 *
 * @param bufferArg should be an ascii character
 * @return whether a character is an ASCII printable character or not
 */
bool unstd_isasciiprintablechar(const unsigned char bufferArg);

/**
 *
 * @param bufferArg should be an ascii character
 * @return whether a character is an ASCII extended character or not
 */
bool unstd_isasciiextendedchar(const unsigned char bufferArg);

/**
 *
 * @param bufferArg should be a character
 * @return whether a character is within the ranges A-Z, a-z or not
 */
bool unstd_isalphabeticchar(const unsigned char bufferArg);

/**
 *
 * @param bufferArg should be a character
 * @return whether a character is within the ranges A-Z, a-z, 0-9 or not
 */
bool unstd_isalphanumericchar(const unsigned char bufferArg);

/**
 *
 * @param bufferArg should be a character
 * @return whether a character is within the range 0-9 or not
 */
bool unstd_isdigitchar(const unsigned char bufferArg);

/**
 *
 * @param bufferArg should be a character
 * @return whether a character is within the ranges A-f, a-f, 0-9 or not
 */
bool unstd_ishexchar(const unsigned char bufferArg);

/**
 *
 * @param bufferArg should be a character
 * @return whether a character is within the ranges A-f, a-f, 0-9 or not
 */
bool unstd_iswhitespace(const unsigned char bufferArg);