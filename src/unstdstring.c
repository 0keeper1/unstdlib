#include "unstdstring.h"

#include <ctype.h>
#include "unstdbool.h"
#include "unstdinttypes.h"
#include <stdlib.h>
#include <string.h>


/**
 * @brief Good Stuff, dont mind me.
 */
#ifndef __unstdstring_bufferencoding
#define __unstdstring_bufferencoding
typedef enum : u8t {
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


u64lt unstdstring_strlen8(const char *const buffer_arg) {
    if (!buffer_arg || !*buffer_arg) {
        return 0;
    }

    u64lt len = 0;
    while (buffer_arg[++len]);

    return len;
}


u64lt unstdstring_strlen16(const u16t *const buffer_arg) {
    if (!buffer_arg || !*buffer_arg) {
        return 0;
    }

    u64lt len = 0;
    while (((u16t *) buffer_arg)[++len]);

    return len;
}


bool unstdstring_charcmp8(const u8t f_buffer_arg, const u8t s_buffer_arg) {
    return f_buffer_arg == s_buffer_arg;
}


bool unstdstring_strcmp8(const char *const f_buffer_arg, const char *const s_buffer_arg) {
    if (!f_buffer_arg || !s_buffer_arg) {
        return false;
    }

    if (!*f_buffer_arg && !*s_buffer_arg) {
        return true;
    }

    if (!*f_buffer_arg || !*s_buffer_arg) {
        return false;
    }

    return !strcmp(f_buffer_arg, s_buffer_arg);
}


bool unstdstring_strcmp16(const u16t *const f_buffer_arg, const u16t *const s_buffer_arg) {
    if (!f_buffer_arg || !s_buffer_arg) {
        return false;
    }

    if (!*f_buffer_arg && !*s_buffer_arg) {
        return true;
    }

    if (!*f_buffer_arg || !*s_buffer_arg) {
        return false;
    }

    u64lt length_s_buffer_arg = unstdstring_strlen16(s_buffer_arg);
    u64lt length_f_buffer_arg = unstdstring_strlen16(f_buffer_arg);

    if (length_s_buffer_arg != length_f_buffer_arg) {
        return false;
    }

    for (u64lt buffer_arg_ptr = 0; ((u16t *) s_buffer_arg)[buffer_arg_ptr]; buffer_arg_ptr++) {
        if (((u16t *) s_buffer_arg)[buffer_arg_ptr] != ((u16t *) f_buffer_arg)[buffer_arg_ptr]) {
            return false;
        }
    }

    return true;
}


bool unstdstring_strcmpignorecase8(const char *const f_buffer_arg, const char *const s_buffer_arg) {
    if (!f_buffer_arg || !s_buffer_arg) {
        return false;
    }

    if (!*f_buffer_arg && !*s_buffer_arg) {
        return true;
    }

    if (!*f_buffer_arg || !*s_buffer_arg) {
        return false;
    }

    u64lt length_s_buffer_arg = unstdstring_strlen8(s_buffer_arg);
    u64lt length_f_buffer_arg = unstdstring_strlen8(f_buffer_arg);

    if (length_s_buffer_arg != length_f_buffer_arg) {
        return false;
    }

    for (u64lt buffer_arg_ptr = 0; ((u8t *) s_buffer_arg)[buffer_arg_ptr]; buffer_arg_ptr++) {
        if (tolower(((u8t *) s_buffer_arg)[buffer_arg_ptr]) != tolower(((u8t *) f_buffer_arg)[buffer_arg_ptr])) {
            return false;
        }
    }

    return true;
}


bool unstdstring_startswithchar8(const char *const buffer_arg, const char checkon_arg) {
    if (!buffer_arg) {
        return false;
    }

    if (unstdstring_strlen8(buffer_arg) < 1) {
        return false;
    }

    return *buffer_arg == checkon_arg;
}


bool unstdstring_startswithcharignorecase8(const char *const buffer_arg, const char checkon_arg) {
    if (!buffer_arg) {
        return false;
    }

    if (unstdstring_strlen8(buffer_arg) < 1) {
        return false;
    }

    return tolower(*buffer_arg) == tolower(checkon_arg);
}


bool unstdstring_endswithchar8(const char *const buffer_arg, const char checkon_arg) {
    if (!buffer_arg) {
        return false;
    }

    if (unstdstring_strlen8(buffer_arg) < 1) {
        return false;
    }

    return buffer_arg[unstdstring_strlen8(buffer_arg) - 1] == checkon_arg;
}


bool unstdstring_endswithcharignorecase8(const char *const buffer_arg, const char checkon_arg) {
    if (!buffer_arg) {
        return false;
    }

    if (unstdstring_strlen8(buffer_arg) < 1) {
        return false;
    }

    return tolower(buffer_arg[unstdstring_strlen8(buffer_arg) - 1]) == tolower(checkon_arg);
}


void unstdstring_tolowerstr(char *const buffer_arg) {
    for (u64lt i = 0; buffer_arg[i]; buffer_arg[i] = (char) tolower(buffer_arg[i]), i++);
}


char *unstdstring_tolowerstrcopy(const char *const buffer_arg) {
    if (!buffer_arg) {
        return NULL;
    }

    u64lt length_buffer_arg = unstdstring_strlen8(buffer_arg);
    if (length_buffer_arg < 1) {
        return NULL;
    }

    char *allocationPtr = (char *) calloc(length_buffer_arg + 1, sizeof(char));
    if (!allocationPtr) {
        return NULL;
    }

    for (u64lt i = 0; buffer_arg[i]; allocationPtr[i] = (char) tolower(buffer_arg[i]), i++);

    return allocationPtr;
}


void unstdstring_tolowerstrarray(char (*const buffer_arg)[]) {
    for (u64lt i = 0; (*buffer_arg)[i]; i++) { (*buffer_arg)[i] = (char) tolower((*buffer_arg)[i]); }
}


void unstdstring_toupperstr(char *const buffer_arg) {
    for (u64lt i = 0; buffer_arg[i]; buffer_arg[i] = (char) toupper(buffer_arg[i]), i++);
}


char *unstdstring_toupperstrcopy(const char *const buffer_arg) {
    if (buffer_arg == NULL) {
        return NULL;
    }

    u64lt length_buffer_arg = unstdstring_strlen8(buffer_arg);
    if (length_buffer_arg < 1) {
        return NULL;
    }

    char *allocationPtr = (char *) calloc(length_buffer_arg + 1, sizeof(char));
    if (allocationPtr == NULL) {
        return NULL;
    }

    for (u64lt i = 0; buffer_arg[i]; allocationPtr[i] = (char) toupper(buffer_arg[i]), i++);

    return allocationPtr;
}


void unstdstring_toupperstrarray(char (*const buffer_arg)[]) {
    for (u64lt i = 0; (*buffer_arg)[i]; i++) { (*buffer_arg)[i] = (char) toupper((*buffer_arg)[i]); }
}


bool unstdstring_isasciicontrolchar(const u8t buffer_arg) {
    return buffer_arg >= 0 && buffer_arg <= 31 || buffer_arg == 127;
}


bool unstdstring_isasciiprintablechar(const u8t buffer_arg) {
    return buffer_arg >= 32 && buffer_arg <= 126;
}


bool unstdstring_isasciiextendedchar(const u8t buffer_arg) {
    return buffer_arg >= 128 && buffer_arg <= 255;
}

bool unstdstring_isasciivisiblechar(const u8t buffer_arg) {
    return unstdstring_isasciiprintablechar(buffer_arg) || unstdstring_isasciiextendedchar(buffer_arg);
}

bool unstdstring_isasciichar(const u8t buffer_arg) {
    return buffer_arg >= 0 && buffer_arg <= 255;
}

bool unstdstring_isalphabeticchar(const u8t buffer_arg) {
    return buffer_arg >= 'a' && buffer_arg <= 'z'
           || buffer_arg >= 'A' && buffer_arg <= 'Z';
}


bool unstdstring_isalphanumericchar(const u8t buffer_arg) {
    return unstdstring_isalphabeticchar(buffer_arg)
           || buffer_arg >= '0' && buffer_arg <= '9';
}


bool unstdstring_isdigitchar(const u8t buffer_arg) {
    return buffer_arg >= '0' && buffer_arg <= '9';
}


bool unstdstring_ishexchar(const u8t buffer_arg) {
    return unstdstring_isdigitchar(buffer_arg)
           || buffer_arg >= 'a' && buffer_arg <= 'f'
           || buffer_arg >= 'A' && buffer_arg <= 'F';
}


bool unstdstring_iswhitespace(const u8t buffer_arg) {
    return buffer_arg == 32 || buffer_arg == 9
           || buffer_arg == 10 || buffer_arg == 11
           || buffer_arg == 12 || buffer_arg == 13;
}


u8t _unstdstring_bufferextend(void *buffer_arg, const u32lt bytes_arg, const u8t encoding_arg) {
    if (!buffer_arg) {
        return 2;
    }

    if (bytes_arg < 1) {
        return 3;
    }

    u64lt size_buffer_arg;

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

    char *realloc_result = (char *) realloc(
            (void *) buffer_arg,
            size_buffer_arg * encoding_arg + bytes_arg * encoding_arg + encoding_arg
    );
    if (!realloc_result) {
        return 0;
    }

    if (!memset(buffer_arg + size_buffer_arg * encoding_arg,
                0,
                bytes_arg * encoding_arg + encoding_arg)) {
        return 5;
    }

    return 1;
}


u8t _unstdstring_buffershrink(void *buffer_arg, const u32lt bytes_arg, const u8t encoding_arg) {
    if (!buffer_arg) {
        return 2;
    }

    if (bytes_arg < 1) {
        return 3;
    }

    u64lt size_buffer_arg;

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

    char *realloc_result = (char *) realloc(
            (void *) buffer_arg,
            size_buffer_arg == bytes_arg
            ? encoding_arg
            : size_buffer_arg * encoding_arg - bytes_arg * encoding_arg - encoding_arg
    );
    if (!realloc_result) {
        return 0;
    }

    if (!memset(buffer_arg + size_buffer_arg * encoding_arg - bytes_arg * encoding_arg,
                0,
                bytes_arg * encoding_arg + encoding_arg)) {
        return 7;
    }

    return 1;
}


char *unstdstring_bufferstringinit8(const char *const buffer_arg, u8t *const out_error_arg) {
    u64lt size_buffer_arg = !buffer_arg ? 0 : unstdstring_strlen8(buffer_arg);

    char *buffer = (char *) malloc(size_buffer_arg + 1);
    if (!buffer) {
        if (out_error_arg) {
            *out_error_arg = 0;
        }
        return NULL;
    }

    if (!memset(buffer, 0, size_buffer_arg + 1)) {
        if (out_error_arg) {
            *out_error_arg = 2;
        }
        return NULL;
    }

    if (buffer_arg) {
        if (!unstdstring_strcmp8(strcpy(buffer, buffer_arg), buffer_arg)) {
            if (out_error_arg) {
                *out_error_arg = 3;
            }
            return NULL;
        }
    }

    if (out_error_arg) {
        *out_error_arg = 1;
    }

    return buffer;
}


u16t *unstdstring_bufferstringinit16(const u16t *const buffer_arg, u8t *const out_error_arg) {
    u64lt size_bytes_buffer_arg = !buffer_arg ? 0 : (unstdstring_strlen16((const u16t *) buffer_arg) * 2);

    u16t *buffer = (u16t *) malloc(size_bytes_buffer_arg + 2);
    if (buffer == NULL) {
        if (out_error_arg) {
            *out_error_arg = 0;
        }
        return NULL;
    }

    if (!memset(buffer, 0, size_bytes_buffer_arg + 2)) {
        if (out_error_arg) {
            *out_error_arg = 2;
        }
        return NULL;
    }

    if (buffer_arg) {
        if (!unstdstring_strcmp16(
                (u16t *) memcpy((char *) buffer,
                                (char *) buffer_arg,
                                size_bytes_buffer_arg),
                buffer_arg)) {
            if (out_error_arg) {
                *out_error_arg = 3;
            }
            return NULL;
        }
    }

    if (out_error_arg) {
        *out_error_arg = 1;
    }

    return buffer;
}


u8t unstdstring_bufferclear8(void *const buffer_arg) {
    if (!buffer_arg) {
        return 2;
    }

    return _unstdstring_buffershrink(buffer_arg, unstdstring_strlen8(buffer_arg), _unstdstring_bufferencoding_UTF8) == 1
           ? 1 : 3;
}


u8t unstdstring_pushchar8(void *const to_buffer_arg, const u8t from_buffer_arg) {
    if (!to_buffer_arg) {
        return 2;
    }

    if (_unstdstring_bufferextend(to_buffer_arg, 1, _unstdstring_bufferencoding_UTF8) != 1) {
        return 0;
    }

    const u64lt size_to_buffer_arg = unstdstring_strlen8(to_buffer_arg);

    ((u8t *) to_buffer_arg)[size_to_buffer_arg] = from_buffer_arg;
    ((u8t *) to_buffer_arg)[size_to_buffer_arg + 1] = 0;
    return 1;
}


u8t unstdstring_pushchar16(void *const to_buffer_arg, const u16t from_buffer_arg) {
    if (!to_buffer_arg) {
        return 2;
    }

    if (_unstdstring_bufferextend(to_buffer_arg, 1, _unstdstring_bufferencoding_UTF16) != 1) {
        return 0;
    }

    const u64lt size_to_buffer_arg = unstdstring_strlen16(to_buffer_arg);

    ((u16t *) to_buffer_arg)[size_to_buffer_arg] = from_buffer_arg;
    ((u16t *) to_buffer_arg)[size_to_buffer_arg + 1] = 0;

    return 1;
}


u8t unstdstring_popchar8(void *const buffer_arg, u8t *const out_error_arg) {
    if (!buffer_arg) {
        if (out_error_arg) {
            *out_error_arg = 2;
        }
        return 0;
    }

    u8t temp_char_holder = ((u8t *) buffer_arg)[unstdstring_strlen8(buffer_arg) - 1];

    if (_unstdstring_buffershrink(buffer_arg, 1, _unstdstring_bufferencoding_UTF8) != 1) {
        if (out_error_arg) {
            *out_error_arg = 0;
        }
        return 0;
    }

    if (out_error_arg) {
        *out_error_arg = 1;
    }

    return temp_char_holder;
}


u16t unstdstring_popchar16(void *const buffer_arg, u8t *const out_error_arg) {
    if (!buffer_arg) {
        if (out_error_arg) {
            *out_error_arg = 2;
        }
        return 0;
    }

    u16t temp_char_holder = ((u16t *) buffer_arg)[unstdstring_strlen16(buffer_arg) - 1];

    if (_unstdstring_buffershrink(buffer_arg, 1, _unstdstring_bufferencoding_UTF16) != 1) {
        if (out_error_arg) {
            *out_error_arg = 0;
        }
        return 0;
    }

    if (out_error_arg) {
        *out_error_arg = 1;
    }

    return temp_char_holder;
}


u8t unstdstring_appendstr8(void *const to_buffer_arg, const char *const from_buffer_arg) {
    if (!to_buffer_arg) {
        return 2;
    }

    if (!from_buffer_arg) {
        return 3;
    }

    u64lt length_from_buffer_arg_temp = unstdstring_strlen8(from_buffer_arg);
    if (!_unstdstring_bufferextend(to_buffer_arg, length_from_buffer_arg_temp, _unstdstring_bufferencoding_UTF8)) {
        return 0;
    }

    strcat(to_buffer_arg, from_buffer_arg);

    return 1;
}