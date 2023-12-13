#include "unstdstring.h"

#include <ctype.h>
#include "unstdbool.h"
#include <stdlib.h>
#include <string.h>


/**
 * @brief Good Stuff, dont mind me.
 */
#ifndef __unstdstring_bufferencoding
#define __unstdstring_bufferencoding
typedef enum : u8 {
    _unstdstring_bufferencoding_UTF8 = 1,
    _unstdstring_bufferencoding_UTF16 = 2,
    _unstdstring_bufferencoding_UTF32 = 4
} _unstdstring_bufferencoding;


#define _unstdstring_encode_as_utf8(string_arg) u8##string_arg
#define _unstdstring_encode_as_utf16(string_arg) u##string_arg
#define _unstdstring_encode_as_utf32(string_arg) U##string_arg
#define _unstdstring_encode_as_widechar(string_arg) L##string_arg
#define _unstdstring_encode_as_raw(string_arg) R##string_arg

#define _unstdstring_encode_as_raw_utf8(string_arg) u8R##string_arg
#define _unstdstring_encode_as_raw_utf16(string_arg) uR##string_arg
#define _unstdstring_encode_as_raw_utf32(string_arg) UR##string_arg
#define _unstdstring_encode_as_raw_widechar(string_arg) LR##string_arg
#endif /* __unstdstring_bufferencoding */


u64l unstdstring_strlen8(const char *const buffer_arg) {
    if (buffer_arg == NULL || *buffer_arg == 0) {
        return 0;
    }

    u64l len = 0;
    while (buffer_arg[++len] != 0);

    return len;
}


u64l unstdstring_strlen16(const u16 *const buffer_arg) {
    if (buffer_arg == NULL || *buffer_arg == '\0') {
        return 0;
    }

    u64l len = 0;
    while (((u16 *) buffer_arg)[++len] != 0);

    return len;
}


bool unstdstring_charcmp8(const u8 f_buffer_arg, const u8 s_buffer_arg) {
    return f_buffer_arg == s_buffer_arg;
}


bool unstdstring_strcmp8(const char *const f_buffer_arg, const char *const s_buffer_arg) {
    return f_buffer_arg != NULL && s_buffer_arg != NULL ? !strcmp(f_buffer_arg, s_buffer_arg) : false;
}


bool unstdstring_strcmp16(const u16 *const f_buffer_arg, const u16 *const s_buffer_arg) {
    if (f_buffer_arg == NULL || s_buffer_arg == NULL) {
        return false;
    }

    if (*f_buffer_arg == '\0' && *s_buffer_arg == '\0') {
        return true;
    }

    u64l length_s_buffer_arg = unstdstring_strlen16(s_buffer_arg);
    u64l length_f_buffer_arg = unstdstring_strlen16(f_buffer_arg);

    if (length_s_buffer_arg != length_f_buffer_arg) {
        return false;
    }

    for (size_t buffer_arg_ptr = 0; ((u16 *) s_buffer_arg)[++buffer_arg_ptr] != 0; buffer_arg_ptr++) {
        if (((u16 *) s_buffer_arg)[buffer_arg_ptr] != ((u16 *) f_buffer_arg)[buffer_arg_ptr]) { return false; }
    }

    return true;
}


bool unstdstring_strcmpignorecase8(const char *const f_buffer_arg, const char *const s_buffer_arg) {
    if (f_buffer_arg == NULL && s_buffer_arg == NULL) {
        return false;
    }

    char *lowered_f_buffer_arg = unstdstring_tolowerstrcopy(f_buffer_arg);
    char *lowered_s_buffer_arg = unstdstring_tolowerstrcopy(s_buffer_arg);
    bool strcmp_result = unstdstring_strcmp8(lowered_f_buffer_arg, lowered_s_buffer_arg);
    free(lowered_s_buffer_arg);
    free(lowered_f_buffer_arg);
    return strcmp_result;
}


bool unstdstring_startswithchar8(const char *const buffer_arg, const char checkon_arg) {
    if (buffer_arg == NULL) {
        return false;
    }

    if (strlen(buffer_arg) < 1) {
        return false;
    }

    return *buffer_arg == checkon_arg;
}


bool unstdstring_startswithcharignorecase8(const char *const buffer_arg, const char checkon_arg) {
    if (buffer_arg == NULL) {
        return false;
    }

    if (strlen(buffer_arg) < 1) {
        return false;
    }

    return tolower(*buffer_arg) == tolower(checkon_arg);
}


bool unstdstring_endswithchar8(const char *const buffer_arg, const char checkon_arg) {
    if (buffer_arg == NULL) {
        return false;
    }

    if (strlen(buffer_arg) < 1) {
        return false;
    }

    return buffer_arg[strlen(buffer_arg) - 1] == checkon_arg;
}


bool unstdstring_endswithcharignorecase8(const char *const buffer_arg, const char checkon_arg) {
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


u8 _unstdstring_bufferextend(void *buffer_arg, const u64 bytes_arg, const u8 encoding_arg) {
    if (buffer_arg == NULL) {
        return 2;
    }

    if (bytes_arg < 1) {
        return 3;
    }

    size_t size_buffer_arg;

    switch (encoding_arg) {
        case _unstdstring_bufferencoding_UTF8:
            size_buffer_arg = unstdstring_strlen8(buffer_arg);
            break;
        case _unstdstring_bufferencoding_UTF16:
            size_buffer_arg = unstdstring_strlen16(buffer_arg);
            break;
        case _unstdstring_bufferencoding_UTF32:
            // [under implementation]
            //size_buffer_arg = unstdstring_strlen32(buffer_arg);
            //break;
        default:
            return 4;
    }

    // `size_buffer_arg * encoding` gives the number of bytes within an encoded buffer.
    // `+ encoding` adds the actual number of bytes needed for a null-terminator
    // contrary to the buffer encoding.
    // [example]
    // utf-8 null-terminators --> 1 byte
    // utf-16 null-terminators --> 2 bytes
    // utf-32 null-terminators --> 4 bytes
    char *realloc_result = (char *) realloc(
            (void *) buffer_arg,
            size_buffer_arg * encoding_arg + bytes_arg * encoding_arg + encoding_arg
    );
    if (realloc_result == NULL) {
        return 0;
    }

    if (memset(buffer_arg + size_buffer_arg * encoding_arg,
               0,
               bytes_arg * encoding_arg + encoding_arg) == NULL) {
        return 5;
    }

    return 1;
}


u8 _unstdstring_buffershrink(void *buffer_arg, const u64 bytes_arg, const u8 encoding_arg) {
    if (buffer_arg == NULL) {
        return 2;
    }

    if (bytes_arg < 1) {
        return 3;
    }

    size_t size_buffer_arg;

    switch (encoding_arg) {
        case _unstdstring_bufferencoding_UTF8:
            size_buffer_arg = unstdstring_strlen8(buffer_arg);
            break;
        case _unstdstring_bufferencoding_UTF16:
            size_buffer_arg = unstdstring_strlen16(buffer_arg);
            break;
        case _unstdstring_bufferencoding_UTF32:
            // [under implementation]
            //size_buffer_arg = unstdstring_strlen32(buffer_arg);
            //break;
        default:
            return 6;
    }

    if (size_buffer_arg < 1) {
        return 4;
    }

    if (bytes_arg > size_buffer_arg) {
        return 5;
    }

    // size_buffer_arg * encoding gives the number of bytes within an encoded buffer
    // + encoding adds the actual number of bytes needed for a null-terminator
    // contrary to the buffer encoding.
    // [example]
    // utf-8 null-terminators --> 1 byte
    // utf-16 null-terminators --> 2 bytes
    // utf-32 null-terminators --> 4 bytes
    char *realloc_result = (char *) realloc(
            (void *) buffer_arg,
            size_buffer_arg == bytes_arg
            ? encoding_arg
            : size_buffer_arg * encoding_arg - bytes_arg * encoding_arg - encoding_arg
    );
    if (realloc_result == NULL) {
        return 0;
    }

    if (memset(buffer_arg + size_buffer_arg * encoding_arg - bytes_arg * encoding_arg,
               0,
               bytes_arg * encoding_arg + encoding_arg) == NULL) {
        return 7;
    }

    return 1;
}


char *unstdstring_bufferstringinit8(const char *const buffer_arg, u8 *const out_error_arg) {
    size_t size_buffer_arg = buffer_arg == NULL ? 0 : strlen(buffer_arg);

    char *buffer = (char *) malloc(size_buffer_arg + 1);
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
        if (!unstdstring_strcmp8(strcpy(buffer, buffer_arg), buffer_arg)) {
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


u16 *unstdstring_bufferstringinit16(const u16 *const buffer_arg, u8 *const out_error_arg) {
    size_t size_bytes_buffer_arg = buffer_arg == NULL ? 0 : (unstdstring_strlen16((const u16 *) buffer_arg) * 2);

    u16 *buffer = (u16 *) malloc(size_bytes_buffer_arg + 2);
    if (buffer == NULL) {
        if (out_error_arg != NULL) {
            *out_error_arg = 0;
            return NULL;
        }
    }

    if (memset(buffer, 0, size_bytes_buffer_arg + 2) == NULL) {
        if (out_error_arg != NULL) {
            *out_error_arg = 2;
            return NULL;
        }
    }

    if (buffer_arg != NULL) {
        if (!unstdstring_strcmp16(
                (u16 *) memcpy((char *) buffer,
                               (char *) buffer_arg,
                               size_bytes_buffer_arg),
                buffer_arg)) {
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


u8 unstdstring_bufferclear8(void *const buffer_arg) {
    if (buffer_arg == NULL) {
        return 2;
    }

    return _unstdstring_buffershrink(buffer_arg, strlen(buffer_arg), _unstdstring_bufferencoding_UTF8) == 1 ? 1 : 3;
}


u8 unstdstring_pushchar8(void *const to_buffer_arg, const u8 from_buffer_arg) {
    if (to_buffer_arg == NULL) {
        return 2;
    }

    if (_unstdstring_bufferextend(to_buffer_arg, 1, _unstdstring_bufferencoding_UTF8) != 1) {
        return 0;
    }
    const size_t size_to_buffer_arg = strlen(to_buffer_arg);

    ((u8 *) to_buffer_arg)[size_to_buffer_arg] = from_buffer_arg;
    ((u8 *) to_buffer_arg)[size_to_buffer_arg + 1] = 0;
    return 1;
}


u8 unstdstring_pushchar16(void *const to_buffer_arg, const u16 from_buffer_arg) {
    if (to_buffer_arg == NULL) {
        return 2;
    }

    if (_unstdstring_bufferextend(to_buffer_arg, 1, _unstdstring_bufferencoding_UTF16) != 1) {
        return 0;
    }

    const u64l size_to_buffer_arg = unstdstring_strlen16(to_buffer_arg);

    ((u16 *) to_buffer_arg)[size_to_buffer_arg] = from_buffer_arg;
    ((u16 *) to_buffer_arg)[size_to_buffer_arg + 1] = 0;

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

    if (_unstdstring_buffershrink(buffer_arg, 1, _unstdstring_bufferencoding_UTF8) != 1) {
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


u16 unstdstring_popchar16(void *const buffer_arg, u8 *const out_error_arg) {
    if (buffer_arg == NULL) {
        if (out_error_arg != NULL) {
            *out_error_arg = 2;
            return 0;
        }
    }

    u16 temp_char_holder = ((u16 *) buffer_arg)[unstdstring_strlen16(buffer_arg) - 1];

    if (_unstdstring_buffershrink(buffer_arg, 1, _unstdstring_bufferencoding_UTF16) != 1) {
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


u8 unstdstring_appendstr8(void *const to_buffer_arg, const char *const from_buffer_arg) {
    if (to_buffer_arg == NULL) {
        return 2;
    }

    if (from_buffer_arg == NULL) {
        return 3;
    }

    size_t length_from_buffer_arg_temp = strlen(from_buffer_arg);
    if (!_unstdstring_bufferextend(to_buffer_arg, length_from_buffer_arg_temp, _unstdstring_bufferencoding_UTF8)) {
        return 0;
    }

    strcat(to_buffer_arg, from_buffer_arg);

    return 1;
}