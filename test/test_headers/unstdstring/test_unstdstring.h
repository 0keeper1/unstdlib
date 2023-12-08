#include "../../_test_common.h"

// Headers
#include "../../../src/unstdinttypes.h"
#include "../../../src/unstdstring.h"


//! [strlen8]
void test_unstdstring_strlen8(void) {
    // heap-allocated test
    char *test_buffer_heap_allocated = (char *) malloc(32);
    strcpy(test_buffer_heap_allocated, "Hello, world!");

    // [Succeeds]
    assert(unstdstring_strlen8(test_buffer_heap_allocated) == 13);
    free(test_buffer_heap_allocated);

    // c-array test
    char test_buffer_c_array[] = "Hello, world!";

    // [Succeeds]
    assert(unstdstring_strlen8(test_buffer_c_array) == 13);

    _notify("[+]", "`unstdstring_strlen8()` passed");
}

//! [charcmp]
void test_unstdstring_charcmp(void) {
    // [Succeeds]
    assert(unstdstring_charcmp('0', '0'));
    assert(unstdstring_charcmp(2, 2));
    assert(unstdstring_charcmp('`', '`'));

    // [Fails]
    assert(!unstdstring_charcmp(' ', '2'));

    _notify("[+]", "`unstdstring_charcmp()` passed");
}

//! [strcmp]
void test_unstdstring_strcmp(void) {
    // [Succeeds]
    assert(unstdstring_strcmp("0", "0"));
    assert(unstdstring_strcmp("\0", "\0"));
    assert(unstdstring_strcmp("\x1\n", "\x1\n"));
    assert(unstdstring_strcmp("\x33", "\x33"));
    assert(unstdstring_strcmp("\n\n\n\r\r\r", "\n\n\n\r\r\r"));

    // [Fails]
    assert(!unstdstring_strcmp("\10", "0"));
    assert(!unstdstring_strcmp(0, 0));
    assert(!unstdstring_strcmp("32", "0"));
    assert(!unstdstring_strcmp("\n\n\n\r\r\r\b", "\n\n\n\r\r\r"));
    assert(!unstdstring_strcmp(NULL, NULL));

    _notify("[+]", "`unstdstring_strcmp()` passed");
}

//! [strcmpignorecase]
void test_unstdstring_strcmpignorecase(void) {
    // [Succeeds]
    assert(unstdstring_strcmpignorecase("0", "0"));
    assert(unstdstring_strcmpignorecase("\0", "\0"));
    assert(unstdstring_strcmpignorecase("\x1\n", "\x1\n"));
    assert(unstdstring_strcmpignorecase("\x33", "\x33"));
    assert(unstdstring_strcmpignorecase("\n\n\n\r\r\r", "\n\n\n\r\r\r"));
    assert(unstdstring_strcmpignorecase("\n\n\n\r\r\r", "\n\n\n\r\r\r"));
    assert(unstdstring_strcmpignorecase("Hello World", "hello world"));

    // [Fails]
    assert(!unstdstring_strcmpignorecase("\0", "0"));
    assert(!unstdstring_strcmpignorecase(0, 0));
    assert(!unstdstring_strcmpignorecase("32", "0"));
    assert(!unstdstring_strcmpignorecase("\n\n\n\r\r\r\b", "\n\n\n\r\r\r"));
    assert(!unstdstring_strcmpignorecase(NULL, NULL));
    assert(!unstdstring_strcmpignorecase("Hello World!", "hello world"));


    _notify("[+]", "`unstdstring_strcmpignorecase()` passed");
}

//! [startswithchar]
void test_unstdstring_startswithchar(void) {
    char *test_buffer = "Hello, world!";

    // [Succeeds]
    assert(unstdstring_startswithchar(test_buffer, 'H'));

    // [Fails]
    assert(!unstdstring_startswithchar(test_buffer, 'a'));
    assert(!unstdstring_startswithchar(test_buffer, ' '));
    assert(!unstdstring_startswithchar(test_buffer, '\42'));
    assert(!unstdstring_startswithchar(test_buffer, '\n'));
    assert(!unstdstring_startswithchar(test_buffer, '\r'));
    assert(!unstdstring_startswithchar(test_buffer, '$'));
    assert(!unstdstring_startswithchar(test_buffer, 0xff));
    assert(!unstdstring_startswithchar(test_buffer, -2));
    assert(!unstdstring_startswithchar(test_buffer, 0));
    assert(!unstdstring_startswithchar(test_buffer, '\0'));

    _notify("[+]", "`unstdstring_startswithchar()` passed");
}

//! [startswithcharignorecase]
void test_unstdstring_startswithcharignorecase(void) {
    char *test_buffer = "Hello, world";

    // [Succeeds]
    assert(unstdstring_startswithcharignorecase(test_buffer, 'h'));
    assert(unstdstring_startswithcharignorecase(test_buffer, 'H'));

    // [Fails]
    assert(!unstdstring_startswithcharignorecase(test_buffer, ' '));
    assert(!unstdstring_startswithcharignorecase(test_buffer, '\42'));
    assert(!unstdstring_startswithcharignorecase(test_buffer, '\n'));
    assert(!unstdstring_startswithcharignorecase(test_buffer, '\r'));
    assert(!unstdstring_startswithcharignorecase(test_buffer, '$'));
    assert(!unstdstring_startswithcharignorecase(test_buffer, 0xff));
    assert(!unstdstring_startswithcharignorecase(test_buffer, -2));
    assert(!unstdstring_startswithcharignorecase(test_buffer, 0));
    assert(!unstdstring_startswithcharignorecase(test_buffer, '\0'));

    _notify("[+]", "`unstdstring_startswithcharignorecase()` passed");
}

//! [endswithchar]
void test_unstdstring_endswithchar(void) {
    char *test_buffer = "Hello, world!";

    // [Succeeds]
    assert(unstdstring_endswithchar(test_buffer, '!'));

    // [Fails]
    assert(!unstdstring_endswithchar(test_buffer, 'a'));
    assert(!unstdstring_endswithchar(test_buffer, ' '));
    assert(!unstdstring_endswithchar(test_buffer, '\42'));
    assert(!unstdstring_endswithchar(test_buffer, '\n'));
    assert(!unstdstring_endswithchar(test_buffer, '\r'));
    assert(!unstdstring_endswithchar(test_buffer, '$'));
    assert(!unstdstring_endswithchar(test_buffer, 0xff));
    assert(!unstdstring_endswithchar(test_buffer, -2));
    assert(!unstdstring_endswithchar(test_buffer, 0));
    assert(!unstdstring_endswithchar(test_buffer, '\0'));

    _notify("[+]", "`unstdstring_endswithchar()` passed");
}

//! [endswithcharignorecase]
void test_unstdstring_endswithcharignorecase(void) {
    char *test_buffer = "Hello, world";

    // [Succeeds]
    assert(unstdstring_endswithcharignorecase(test_buffer, 'd'));
    assert(unstdstring_endswithcharignorecase(test_buffer, 'D'));

    // [Fails]
    assert(!unstdstring_endswithcharignorecase(test_buffer, ' '));
    assert(!unstdstring_endswithcharignorecase(test_buffer, '\42'));
    assert(!unstdstring_endswithcharignorecase(test_buffer, '\n'));
    assert(!unstdstring_endswithcharignorecase(test_buffer, '\r'));
    assert(!unstdstring_endswithcharignorecase(test_buffer, '$'));
    assert(!unstdstring_endswithcharignorecase(test_buffer, 0xff));
    assert(!unstdstring_endswithcharignorecase(test_buffer, -2));
    assert(!unstdstring_endswithcharignorecase(test_buffer, 0));
    assert(!unstdstring_endswithcharignorecase(test_buffer, '\0'));

    _notify("[+]", "`unstdstring_endswithcharignorecase()` passed");
}

//! [tolowerstr]
void test_unstdstring_tolowerstr(void) {
    // heap-allocated test
    char *test_buffer_heap_allocated = (char *) malloc(32);
    char *const test_buffer_heap_allocated_copy = (char *) malloc(32);

    strcpy(test_buffer_heap_allocated, "Hello, world!");
    strcpy(test_buffer_heap_allocated_copy, test_buffer_heap_allocated);

    unstdstring_tolowerstr(test_buffer_heap_allocated);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_heap_allocated_copy, test_buffer_heap_allocated));
    free(test_buffer_heap_allocated);

    // c-array test
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_copy[sizeof(test_buffer_c_array)] = {'\0'};

    strcpy(test_buffer_c_array_copy, test_buffer_c_array);

    unstdstring_tolowerstr(test_buffer_c_array);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_c_array_copy, test_buffer_c_array));

    _notify("[+]", "`unstdstring_tolowerstr()` passed");
}

//! [tolowerstrcopy]
void test_unstdstring_tolowerstrcopy(void) {
    // heap-allocated test
    char *test_buffer_heap_allocated = (char *) malloc(32);
    char *test_buffer_heap_allocated_result = NULL;

    strcpy(test_buffer_heap_allocated, "Hello, world!");

    test_buffer_heap_allocated_result = unstdstring_tolowerstrcopy(test_buffer_heap_allocated);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_heap_allocated_result, test_buffer_heap_allocated));
    free(test_buffer_heap_allocated);


    // c-array test
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_result[sizeof(test_buffer_c_array)] = {'\0'};

    char *test_buffer_c_array_result_temp = unstdstring_tolowerstrcopy(test_buffer_c_array);
    strcpy(test_buffer_c_array_result, test_buffer_c_array_result_temp);
    free(test_buffer_c_array_result_temp);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_c_array_result, test_buffer_c_array));

    // constant test
    const char *test_buffer_constant = "Hello, World!";
    char *test_buffer_constant_result = unstdstring_tolowerstrcopy(test_buffer_constant);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_heap_allocated_result, test_buffer_constant));
    free(test_buffer_constant_result);

    _notify("[+]", "`unstdstring_tolowerstrcopy()` passed");
}

//! [tolowerstrarray]
void test_unstdstring_tolowerstrarray(void) {
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_copy[sizeof(test_buffer_c_array)] = {'\0'};

    strcpy(test_buffer_c_array_copy, test_buffer_c_array);

    unstdstring_tolowerstrarray(&test_buffer_c_array);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_c_array_copy, test_buffer_c_array));

    _notify("[+]", "`unstdstring_tolowerstrarray()` passed");
}


//! [toupperstr]
void test_unstdstring_toupperstr(void) {
    // heap-allocated test
    char *test_buffer_heap_allocated = (char *) malloc(32);
    char *const test_buffer_heap_allocated_copy = (char *) malloc(32);

    strcpy(test_buffer_heap_allocated, "Hello, world!");
    strcpy(test_buffer_heap_allocated_copy, test_buffer_heap_allocated);

    unstdstring_toupperstr(test_buffer_heap_allocated);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_heap_allocated_copy, test_buffer_heap_allocated));
    free(test_buffer_heap_allocated);

    // c-array test
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_copy[sizeof(test_buffer_c_array)] = {'\0'};

    strcpy(test_buffer_c_array_copy, test_buffer_c_array);

    unstdstring_toupperstr(test_buffer_c_array);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_c_array_copy, test_buffer_c_array));

    _notify("[+]", "`unstdstring_toupperstr()` passed");
}


//! [toupperstrcopy]
void test_unstdstring_toupperstrcopy(void) {
    // heap-allocated test
    char *test_buffer_heap_allocated = (char *) malloc(32);
    char *test_buffer_heap_allocated_result = NULL;

    strcpy(test_buffer_heap_allocated, "Hello, world!");

    test_buffer_heap_allocated_result = unstdstring_toupperstrcopy(test_buffer_heap_allocated);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_heap_allocated_result, test_buffer_heap_allocated));
    free(test_buffer_heap_allocated);


    // c-array test
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_result[sizeof(test_buffer_c_array)] = {'\0'};

    char *test_buffer_c_array_result_temp = unstdstring_toupperstrcopy(test_buffer_c_array);
    strcpy(test_buffer_c_array_result, test_buffer_c_array_result_temp);
    free(test_buffer_c_array_result_temp);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_c_array_result, test_buffer_c_array));

    // constant test
    const char *test_buffer_constant = "Hello, World!";
    char *test_buffer_constant_result = unstdstring_toupperstrcopy(test_buffer_constant);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_heap_allocated_result, test_buffer_constant));
    free(test_buffer_constant_result);

    _notify("[+]", "`unstdstring_toupperstrcopy()` passed");
}

//! [toupperstrarray]
void test_unstdstring_toupperstrarray(void) {
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_copy[sizeof(test_buffer_c_array)] = {'\0'};

    strcpy(test_buffer_c_array_copy, test_buffer_c_array);

    unstdstring_toupperstrarray(&test_buffer_c_array);

    // [Succeeds]
    assert(!unstdstring_strcmp(test_buffer_c_array_copy, test_buffer_c_array));

    _notify("[+]", "`unstdstring_toupperstrarray()` passed");
}

//! [isasciicontrolchar]
void test_unstdstring_isasciicontrolchar(void) {
    // [Succeeds]
    for (unsigned char ascii_buffer = 0x0; ascii_buffer <= 0x1F; ascii_buffer++) {
        assert(unstdstring_isasciicontrolchar(ascii_buffer));
    }
    assert(unstdstring_isasciicontrolchar(0x7F));

    _notify("[+]", "`unstdstring_isasciicontrolchar()` passed");
}

//! [isasciiprintablechar]
void test_unstdstring_isasciiprintablechar(void) {
    // [Succeeds]
    for (unsigned char ascii_buffer = 0x20; ascii_buffer <= 0x7E; ascii_buffer++) {
        assert(unstdstring_isasciiprintablechar(ascii_buffer));
    }

    _notify("[+]", "`unstdstring_isasciiprintablechar()` passed");
}

//! [isasciiextendedchar]
void test_unstdstring_isasciiextendedchar(void) {
    // [Succeeds]
    for (unsigned char ascii_buffer = 0x80; ascii_buffer >= 0x80 && ascii_buffer <= 0xFF; ascii_buffer++) {
        assert(unstdstring_isasciiextendedchar(ascii_buffer));
    }

    _notify("[+]", "`unstdstring_isasciiextendedchar()` passed");
}

//! [isasciivisiblechar]
void test_unstdstring_isasciivisiblechar(void) {
    // [Succeeds]
    for (unsigned char ascii_buffer = 0x20; ascii_buffer <= 0x7E; ascii_buffer++) {
        assert(unstdstring_isasciivisiblechar(ascii_buffer));
    }

    for (unsigned char ascii_buffer = 0x80; ascii_buffer >= 0x80 && ascii_buffer <= 0xFF; ascii_buffer++) {
        assert(unstdstring_isasciivisiblechar(ascii_buffer));
    }

    // [Fails]
    for (unsigned char ascii_buffer = 0x0; ascii_buffer <= 0x1F; ascii_buffer++) {
        assert(!unstdstring_isasciivisiblechar(ascii_buffer));
    }

    _notify("[+]", "`unstdstring_isasciivisiblechar()` passed");
}

//! [isasciichar]
void test_unstdstring_isasciichar(void) {
    // [Succeeds]
    for (unsigned char ascii_buffer = 0x00; ascii_buffer <= 0xFE;) {
        assert(unstdstring_isasciichar(++ascii_buffer));
    }

    _notify("[+]", "`unstdstring_isasciichar()` passed");
}


//! [isalphabeticchar]
void test_unstdstring_isalphabeticchar(void) {
    // [Succeeds]
    // [A-Z]
    for (unsigned char char_buffer = 'A'; char_buffer <= (unsigned char) 'Z'; char_buffer++) {
        assert(unstdstring_isalphabeticchar(char_buffer));
    }

    // [a-z]
    for (unsigned char char_buffer = 'a'; char_buffer <= (unsigned char) 'z'; char_buffer++) {
        assert(unstdstring_isalphabeticchar(char_buffer));
    }

    // [Fails]
    assert(!unstdstring_isalphabeticchar('0'));

    _notify("[+]", "`unstdstring_isalphabeticchar()` passed");
}

//! [isalphanumericchar]
void test_unstdstring_isalphanumericchar(void) {
    // [Succeeds]
    // [A-Z]
    for (unsigned char char_buffer = 'A'; char_buffer <= (unsigned char) 'Z'; char_buffer++) {
        assert(unstdstring_isalphanumericchar(char_buffer));
    }

    // [a-z]
    for (unsigned char char_buffer = 'a'; char_buffer <= (unsigned char) 'z'; char_buffer++) {
        assert(unstdstring_isalphanumericchar(char_buffer));
    }

    // [0-9]
    for (unsigned char char_buffer = '0'; char_buffer <= (unsigned char) '9'; char_buffer++) {
        assert(unstdstring_isalphanumericchar(char_buffer));
    }

    // [Fails]
    assert(!unstdstring_isalphanumericchar('-'));

    _notify("[+]", "`unstdstring_isalphanumericchar()` passed");
}

//! [isdigitchar]
void test_unstdstring_isdigitchar(void) {
    // [Succeeds]
    // [0-9]
    for (unsigned char char_buffer = '0'; char_buffer <= (unsigned char) '9'; char_buffer++) {
        assert(unstdstring_isdigitchar(char_buffer));
    }

    // [Fails]
    assert(!unstdstring_isdigitchar('a'));
    assert(!unstdstring_isdigitchar(2));
    assert(!unstdstring_isdigitchar(0));
    assert(!unstdstring_isdigitchar(255));

    _notify("[+]", "`unstdstring_isdigitchar()` passed");
}

//! [ishexchar]
void test_unstdstring_ishexchar(void) {
    // [Succeeds]
    // [A-F]
    for (unsigned char char_buffer = 'A'; char_buffer <= (unsigned char) 'F'; char_buffer++) {
//        printf("%c\n", char_buffer);
        assert(unstdstring_ishexchar(char_buffer));
    }

    // [a-f]
    for (unsigned char char_buffer = 'a'; char_buffer <= (unsigned char) 'f'; char_buffer++) {
        assert(unstdstring_ishexchar(char_buffer));
    }

    // [0-9]
    for (unsigned char char_buffer = '0'; char_buffer <= (unsigned char) '9'; char_buffer++) {
        assert(unstdstring_ishexchar(char_buffer));
    }

    // [Fails]
    assert(!unstdstring_ishexchar('g'));
    assert(!unstdstring_ishexchar('h'));
    assert(!unstdstring_ishexchar(255));
    assert(!unstdstring_ishexchar(0));

    _notify("[+]", "`unstdstring_ishexchar()` passed");
}

//! [iswhitespace]
void test_unstdstring_iswhitespace(void) {
    // [Succeeds]
    assert(unstdstring_iswhitespace(' '));
    assert(unstdstring_iswhitespace('\t'));
    assert(unstdstring_iswhitespace('\r'));
    assert(unstdstring_iswhitespace('\n'));
    assert(unstdstring_iswhitespace(10));
    assert(unstdstring_iswhitespace(11));
    assert(unstdstring_iswhitespace(12));
    assert(unstdstring_iswhitespace(13));

    // [Fails]
    assert(!unstdstring_iswhitespace('\b'));
    assert(!unstdstring_iswhitespace('a'));
    assert(!unstdstring_iswhitespace('\2'));

    _notify("[+]", "`unstdstring_iswhitespace()` passed");
}

//! [bufferstringinit8]
void test_unstdstring_bufferstringinit8(void) {
    u8 out_error_result = 0;
    char *test_buffer = unstdstring_bufferstringinit8("Hello World!", &out_error_result);

    // [Succeeds]
    assert(test_buffer != NULL);
    assert(unstdstring_strcmp(test_buffer, "Hello World!"));
    assert(out_error_result == 1);

    // [Fails]
    assert(out_error_result != 0);
    assert(out_error_result != 2);
    assert(out_error_result != 3);

    free(test_buffer);

    u8 out_error_result_2 = 0;
    char *test_buffer_2 = unstdstring_bufferstringinit8(NULL, &out_error_result_2);

    assert(unstdstring_strcmp(test_buffer_2, "\0"));
    assert(out_error_result_2 == 1);

    // [Fails]
    assert(out_error_result_2 != 0);
    assert(out_error_result_2 != 2);
    assert(out_error_result_2 != 3);

    free(test_buffer_2);

    _notify("[+]", "`unstdstring_bufferstringinit8()` passed");
}

//! [bufferclear]
void test_unstdstring_bufferclear(void) {
    // heap-allocated test
    char *test_buffer_heap_allocated = (char *) malloc(32);
    char *const test_buffer_heap_allocated_copy = (char *) malloc(32);

    strcpy(test_buffer_heap_allocated, "Hello, world!");
    strcpy(test_buffer_heap_allocated_copy, test_buffer_heap_allocated);

    u8 function_return_value = unstdstring_bufferclear(test_buffer_heap_allocated);

    // [Succeeds]
    assert(strlen(test_buffer_heap_allocated) != strlen(test_buffer_heap_allocated_copy));
    assert(!unstdstring_strcmp(test_buffer_heap_allocated, test_buffer_heap_allocated_copy));
    assert(function_return_value == 1);

    // [Fails]
    assert(function_return_value != 2);

    free(test_buffer_heap_allocated_copy);
    free(test_buffer_heap_allocated);

    // heap-allocated test - 2
    char *test_buffer_heap_allocated_2 = (char *) malloc(32);
    strcpy(test_buffer_heap_allocated_2, "Hello, world!");

    unsigned char function_return_value_2 = unstdstring_bufferclear(test_buffer_heap_allocated_2);

    // [Fails]
    assert(!(function_return_value_2 == 3));
    assert(!(function_return_value_2 == 0));

    // [Succeeds]
    assert(function_return_value_2 == 1);
    assert(!*test_buffer_heap_allocated_2);

    free(test_buffer_heap_allocated_2);

    _notify("[+]", "`unstdstring_bufferclear()` passed");
}

//! [pushchar8]
void test_unstdstring_pushchar8(void) {
    char *test_string_buffer = unstdstring_bufferstringinit8(NULL, NULL);
    // [Succeeds]
    assert(*test_string_buffer == '\0');

    unstdstring_pushchar8(test_string_buffer, '!');

    // [Succeeds]
    assert(strlen(test_string_buffer) == 1);
    assert(unstdstring_strcmp(test_string_buffer, "!"));

    unstdstring_pushchar8(test_string_buffer, ' ');

    assert(strlen(test_string_buffer) == 2);
    assert(unstdstring_strcmp(test_string_buffer, "! "));

    // [Fails]
    assert(strlen(test_string_buffer) != 0);
    assert(!unstdstring_endswithchar(test_string_buffer, '+'));

    free(test_string_buffer);

    _notify("[+]", "`unstdstring_pushchar8()` passed");
}

//! [pushchar16]
void test_unstdstring_pushchar16(void) {
    char *test_string_buffer = unstdstring_bufferstringinit8(NULL, NULL);
    // [Succeeds]
    assert(*test_string_buffer == '\0');

    unstdstring_pushchar16(test_string_buffer, L'ÿ');

    // [Succeeds]
    assert(strlen(test_string_buffer) == 1);
//    assert(unstdstring_strcmp(test_string_buffer, "ÿ"));

    unstdstring_pushchar16(test_string_buffer, ' ');

    assert(strlen(test_string_buffer) == 2);
    assert(unstdstring_strcmp(test_string_buffer, "! "));

    // [Fails]
    assert(strlen(test_string_buffer) != 0);
    assert(!unstdstring_endswithchar(test_string_buffer, '+'));

    free(test_string_buffer);

    _notify("[+]", "`unstdstring_pushchar16()` passed");
}

//! [popchar8]
void test_unstdstring_popchar8(void) {
    char *test_string_buffer = unstdstring_bufferstringinit8("Hello World!", NULL);

    u8 error_out_holder = 0;
    const u8 function_return_value = unstdstring_popchar8(test_string_buffer, &error_out_holder);

    // [Succeeds]
    assert(error_out_holder == 1);
    assert(strlen(test_string_buffer) == 11);
    assert(unstdstring_strcmp(test_string_buffer, "Hello World"));

    assert(unstdstring_popchar8(test_string_buffer, NULL) == 'd');
    assert(strlen(test_string_buffer) == 10);

    // [Fails]
    assert(strlen(test_string_buffer) != 0);
    assert(!unstdstring_endswithchar(test_string_buffer, '!'));

    free(test_string_buffer);

    _notify("[+]", "`unstdstring_popchar8()` passed");
}

//! [appendstr]
void test_unstdstring_appendstr(void) {
    char *test_string_buffer = unstdstring_bufferstringinit8("Hello", NULL);


    unstdstring_appendstr(test_string_buffer, " fuckin' world");

    // [Succeeds]
    assert(strlen(test_string_buffer) == 19);
    assert(unstdstring_strcmp(test_string_buffer, "Hello fuckin' world"));

    // [Fails]
    assert(test_string_buffer != 0);
    assert(!unstdstring_endswithchar(test_string_buffer, 'o'));

    free(test_string_buffer);


    _notify("[+]", "`unstdstring_appendstr()` passed");
}


void test_unstdstring(void) {
    //! [strlen]
    test_unstdstring_strlen8();

    //! [compare]
    test_unstdstring_charcmp();
    test_unstdstring_strcmp();
    test_unstdstring_strcmpignorecase();

    //! [startswith]
    test_unstdstring_startswithchar();
    test_unstdstring_startswithcharignorecase();

    //! [endswith]
    test_unstdstring_endswithchar();
    test_unstdstring_endswithcharignorecase();

    //! [tolower]
    test_unstdstring_tolowerstr();
    test_unstdstring_tolowerstrcopy();
    test_unstdstring_tolowerstrarray();

    //! [toupper]
    test_unstdstring_toupperstr();
    test_unstdstring_toupperstrcopy();
    test_unstdstring_toupperstrarray();

    //! [is]
    //! [isascii]
    test_unstdstring_isasciicontrolchar();
    test_unstdstring_isasciiprintablechar();
    test_unstdstring_isasciiextendedchar();
    test_unstdstring_isasciivisiblechar();
    test_unstdstring_isasciichar();


    test_unstdstring_isalphabeticchar();
    test_unstdstring_isalphanumericchar();
    test_unstdstring_isdigitchar();
    test_unstdstring_ishexchar();
    test_unstdstring_iswhitespace();

    //! [string]
    test_unstdstring_bufferstringinit8();
    test_unstdstring_bufferclear();
    test_unstdstring_pushchar8();
    //! under implementation
    //test_unstdstring_pushchar16();
    test_unstdstring_popchar8();
    test_unstdstring_appendstr();


    _notify("[+]", "`unstdstring` passed");
}