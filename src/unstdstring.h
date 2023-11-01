#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


//! [cmp]
/**
 *
 * @param fBufferArg a pointer to a null-terminated buffer
 * @param sBufferArg a pointer to a null-terminated buffer
 * @return true if both buffers are identical to each other otherwise false
 */
bool unstd_strcmp(const char *const fBufferArg, const char *const sBufferArg);


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
 * @return whether a character is within the range A-Z, a-z or not
 */
bool unstd_isalphabeticchar(const unsigned char bufferArg);

/**
 *
 * @param bufferArg should be a character
 * @return whether a character is within the range A-Z, a-z, 0-9 or not
 */
bool unstd_isalphanumericchar(const unsigned char bufferArg);

/**
*
* @param bufferArg should be a character
* @return whether a character is within the range A-Z, a-z, 0-9 or not
*/
bool unstd_isdigitchar(const unsigned char bufferArg);
