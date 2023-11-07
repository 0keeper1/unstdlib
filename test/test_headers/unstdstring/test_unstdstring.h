#include <dont/Beautifier/beautifier-c.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Headers
#include "../../../src/unstdstring.h"

//! [charcmp]
void test_unstd_charcmp(void) {
    // [Succeeds]
    assert(unstd_charcmp('0', '0'));
    assert(unstd_charcmp(2, 2));
    assert(unstd_charcmp('`', '`'));

    // [Fails]
    assert(!unstd_charcmp(' ', '2'));

    notify("[+]", "`unstd_charcmp()` passed");
}

//! [strcmp]
void test_unstd_strcmp(void) {
    // [Succeeds]
    assert(unstd_strcmp("0", "0"));
    assert(unstd_strcmp("\0", "\0"));
    assert(unstd_strcmp("\x1\n", "\x1\n"));
    assert(unstd_strcmp("\x33", "\x33"));
    assert(unstd_strcmp("\n\n\n\r\r\r", "\n\n\n\r\r\r"));

    // [Fails]
    assert(!unstd_strcmp("\10", "0"));
    assert(!unstd_strcmp(0, 0));
    assert(!unstd_strcmp("32", "0"));
    assert(!unstd_strcmp("\n\n\n\r\r\r\b", "\n\n\n\r\r\r"));
    assert(!unstd_strcmp(NULL, NULL));

    notify("[+]", "`unstd_strcmp()` passed");
}

//! [strcmpignorecase]
void test_unstd_strcmpignorecase(void) {
    // [Succeeds]
    assert(unstd_strcmpignorecase("0", "0"));
    assert(unstd_strcmpignorecase("\0", "\0"));
    assert(unstd_strcmpignorecase("\x1\n", "\x1\n"));
    assert(unstd_strcmpignorecase("\x33", "\x33"));
    assert(unstd_strcmpignorecase("\n\n\n\r\r\r", "\n\n\n\r\r\r"));
    assert(unstd_strcmpignorecase("\n\n\n\r\r\r", "\n\n\n\r\r\r"));
    assert(unstd_strcmpignorecase("Hello World", "hello world"));

    // [Fails]
    assert(!unstd_strcmpignorecase("\0", "0"));
    assert(!unstd_strcmpignorecase(0, 0));
    assert(!unstd_strcmpignorecase("32", "0"));
    assert(!unstd_strcmpignorecase("\n\n\n\r\r\r\b", "\n\n\n\r\r\r"));
    assert(!unstd_strcmpignorecase(NULL, NULL));
    assert(!unstd_strcmpignorecase("Hello World!", "hello world"));


    notify("[+]", "`unstd_strcmpignorecase()` passed");
}

//! [startswithchar]
void test_unstd_startswithchar(void) {
    char *test_buffer = "Hello, world!";

    // [Succeeds]
    assert(unstd_startswithchar(test_buffer, 'H'));

    // [Fails]
    assert(!unstd_startswithchar(test_buffer, 'a'));
    assert(!unstd_startswithchar(test_buffer, ' '));
    assert(!unstd_startswithchar(test_buffer, '\42'));
    assert(!unstd_startswithchar(test_buffer, '\n'));
    assert(!unstd_startswithchar(test_buffer, '\r'));
    assert(!unstd_startswithchar(test_buffer, '$'));
    assert(!unstd_startswithchar(test_buffer, 0xff));
    assert(!unstd_startswithchar(test_buffer, -2));
    assert(!unstd_startswithchar(test_buffer, 0));
    assert(!unstd_startswithchar(test_buffer, '\0'));

    notify("[+]", "`unstd_startswithchar()` passed");
}

//! [startswithcharignorecase]
void test_unstd_startswithcharignorecase(void) {
    char *test_buffer = "Hello, world";

    // [Succeeds]
    assert(unstd_startswithcharignorecase(test_buffer, 'h'));
    assert(unstd_startswithcharignorecase(test_buffer, 'H'));

    // [Fails]
    assert(!unstd_startswithcharignorecase(test_buffer, ' '));
    assert(!unstd_startswithcharignorecase(test_buffer, '\42'));
    assert(!unstd_startswithcharignorecase(test_buffer, '\n'));
    assert(!unstd_startswithcharignorecase(test_buffer, '\r'));
    assert(!unstd_startswithcharignorecase(test_buffer, '$'));
    assert(!unstd_startswithcharignorecase(test_buffer, 0xff));
    assert(!unstd_startswithcharignorecase(test_buffer, -2));
    assert(!unstd_startswithcharignorecase(test_buffer, 0));
    assert(!unstd_startswithcharignorecase(test_buffer, '\0'));

    notify("[+]", "`unstd_startswithcharignorecase()` passed");
}

//! [endswithchar]
void test_unstd_endswithchar(void) {
    char *test_buffer = "Hello, world!";

    // [Succeeds]
    assert(unstd_endswithchar(test_buffer, '!'));

    // [Fails]
    assert(!unstd_endswithchar(test_buffer, 'a'));
    assert(!unstd_endswithchar(test_buffer, ' '));
    assert(!unstd_endswithchar(test_buffer, '\42'));
    assert(!unstd_endswithchar(test_buffer, '\n'));
    assert(!unstd_endswithchar(test_buffer, '\r'));
    assert(!unstd_endswithchar(test_buffer, '$'));
    assert(!unstd_endswithchar(test_buffer, 0xff));
    assert(!unstd_endswithchar(test_buffer, -2));
    assert(!unstd_endswithchar(test_buffer, 0));
    assert(!unstd_endswithchar(test_buffer, '\0'));

    notify("[+]", "`unstd_endswithchar()` passed");
}

//! [endswithcharignorecase]
void test_unstd_endswithcharignorecase(void) {
    char *test_buffer = "Hello, world";

    // [Succeeds]
    assert(unstd_endswithcharignorecase(test_buffer, 'd'));
    assert(unstd_endswithcharignorecase(test_buffer, 'D'));

    // [Fails]
    assert(!unstd_endswithcharignorecase(test_buffer, ' '));
    assert(!unstd_endswithcharignorecase(test_buffer, '\42'));
    assert(!unstd_endswithcharignorecase(test_buffer, '\n'));
    assert(!unstd_endswithcharignorecase(test_buffer, '\r'));
    assert(!unstd_endswithcharignorecase(test_buffer, '$'));
    assert(!unstd_endswithcharignorecase(test_buffer, 0xff));
    assert(!unstd_endswithcharignorecase(test_buffer, -2));
    assert(!unstd_endswithcharignorecase(test_buffer, 0));
    assert(!unstd_endswithcharignorecase(test_buffer, '\0'));

    notify("[+]", "`unstd_endswithcharignorecase()` passed");
}

//! [tolowerstr]
void test_unstd_tolowerstr(void) {
    // heap-allocated test
    char *test_buffer_heap_allocated = (char *) malloc(32);
    char *const test_buffer_heap_allocated_copy = (char *) malloc(32);

    strcpy(test_buffer_heap_allocated_copy, test_buffer_heap_allocated);
    strcpy(test_buffer_heap_allocated, "Hello, world!");

    unstd_tolowerstr(test_buffer_heap_allocated);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_heap_allocated_copy, test_buffer_heap_allocated));
    free(test_buffer_heap_allocated);

    // c-array test
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_copy[sizeof(test_buffer_c_array)] = {'\0'};

    strcpy(test_buffer_c_array_copy, test_buffer_c_array);

    unstd_tolowerstr(test_buffer_c_array);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_c_array_copy, test_buffer_c_array));

    notify("[+]", "`unstd_tolowerstr()` passed");
}

//! [tolowerstrcopy]
void test_unstd_tolowerstrcopy(void) {
    // heap-allocated test
    char *test_buffer_heap_allocated = (char *) malloc(32);
    char *test_buffer_heap_allocated_result = NULL;

    strcpy(test_buffer_heap_allocated, "Hello, world!");

    test_buffer_heap_allocated_result = unstd_tolowerstrcopy(test_buffer_heap_allocated);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_heap_allocated_result, test_buffer_heap_allocated));
    free(test_buffer_heap_allocated);


    // c-array test
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_result[sizeof(test_buffer_c_array)] = {'\0'};

    char *test_buffer_c_array_result_temp = unstd_tolowerstrcopy(test_buffer_c_array);
    strcpy(test_buffer_c_array_result, test_buffer_c_array_result_temp);
    free(test_buffer_c_array_result_temp);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_c_array_result, test_buffer_c_array));

    // constant test
    const char *test_buffer_constant = "Hello, World!";
    char *test_buffer_constant_result = unstd_tolowerstrcopy(test_buffer_constant);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_heap_allocated_result, test_buffer_constant));
    free(test_buffer_constant_result);

    notify("[+]", "`unstd_tolowerstrcopy()` passed");
}

//! [tolowerstrarray]
void test_unstd_tolowerstrarray(void) {
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_copy[sizeof(test_buffer_c_array)] = {'\0'};

    strcpy(test_buffer_c_array_copy, test_buffer_c_array);

    unstd_tolowerstrarray(&test_buffer_c_array);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_c_array_copy, test_buffer_c_array));

    notify("[+]", "`unstd_tolowerstrarray()` passed");
}


//! [toupperstr]
void test_unstd_toupperstr(void) {
    // heap-allocated test
    char *test_buffer_heap_allocated = (char *) malloc(32);
    char *const test_buffer_heap_allocated_copy = (char *) malloc(32);

    strcpy(test_buffer_heap_allocated_copy, test_buffer_heap_allocated);
    strcpy(test_buffer_heap_allocated, "Hello, world!");

    unstd_toupperstr(test_buffer_heap_allocated);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_heap_allocated_copy, test_buffer_heap_allocated));
    free(test_buffer_heap_allocated);

    // c-array test
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_copy[sizeof(test_buffer_c_array)] = {'\0'};

    strcpy(test_buffer_c_array_copy, test_buffer_c_array);

    unstd_toupperstr(test_buffer_c_array);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_c_array_copy, test_buffer_c_array));

    notify("[+]", "`unstd_toupperstr()` passed");
}


//! [toupperstrcopy]
void test_unstd_toupperstrcopy(void) {
    // heap-allocated test
    char *test_buffer_heap_allocated = (char *) malloc(32);
    char *test_buffer_heap_allocated_result = NULL;

    strcpy(test_buffer_heap_allocated, "Hello, world!");

    test_buffer_heap_allocated_result = unstd_toupperstrcopy(test_buffer_heap_allocated);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_heap_allocated_result, test_buffer_heap_allocated));
    free(test_buffer_heap_allocated);


    // c-array test
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_result[sizeof(test_buffer_c_array)] = {'\0'};

    char *test_buffer_c_array_result_temp = unstd_toupperstrcopy(test_buffer_c_array);
    strcpy(test_buffer_c_array_result, test_buffer_c_array_result_temp);
    free(test_buffer_c_array_result_temp);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_c_array_result, test_buffer_c_array));

    // constant test
    const char *test_buffer_constant = "Hello, World!";
    char *test_buffer_constant_result = unstd_toupperstrcopy(test_buffer_constant);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_heap_allocated_result, test_buffer_constant));
    free(test_buffer_constant_result);

    notify("[+]", "`unstd_toupperstrcopy()` passed");
}

//! [toupperstrarray]
void test_unstd_toupperstrarray(void) {
    char test_buffer_c_array[] = "Hello, world!";
    char test_buffer_c_array_copy[sizeof(test_buffer_c_array)] = {'\0'};

    strcpy(test_buffer_c_array_copy, test_buffer_c_array);

    unstd_toupperstrarray(&test_buffer_c_array);

    // [Succeeds]
    assert(!unstd_strcmp(test_buffer_c_array_copy, test_buffer_c_array));

    notify("[+]", "`unstd_toupperstrarray()` passed");
}

//! [isasciicontrolchar]
void test_unstd_isasciicontrolchar(void) {
    // [Succeeds]
    for (unsigned char ascii_buffer = 0x0; ascii_buffer <= 0x1F; ascii_buffer++) {
        assert(unstd_isasciicontrolchar(ascii_buffer));
    }
    assert(unstd_isasciicontrolchar(0x7F));

    notify("[+]", "`unstd_isasciicontrolchar()` passed");
}

//! [isasciiprintablechar]
void test_unstd_isasciiprintablechar(void) {
    // [Succeeds]
    for (unsigned char ascii_buffer = 0x20; ascii_buffer <= 0x7E; ascii_buffer++) {
        assert(unstd_isasciiprintablechar(ascii_buffer));
    }

    notify("[+]", "`unstd_isasciiprintablechar()` passed");
}

//! [isasciiextendedchar]
void test_unstd_isasciiextendedchar(void) {
    // [Succeeds]
    for (unsigned char ascii_buffer = 0x80; ascii_buffer >= 0x80 && ascii_buffer <= 0xFF; ascii_buffer++) {
        assert(unstd_isasciiextendedchar(ascii_buffer));
    }

    notify("[+]", "`unstd_isasciiextendedchar()` passed");
}

//! [isalphabeticchar]
void test_unstd_isalphabeticchar(void) {
    // [Succeeds]
    // [A-Z]
    for (unsigned char char_buffer = 'A'; char_buffer <= (unsigned char) 'Z'; char_buffer++) {
        assert(unstd_isalphabeticchar(char_buffer));
    }

    // [a-z]
    for (unsigned char char_buffer = 'a'; char_buffer <= (unsigned char) 'z'; char_buffer++) {
        assert(unstd_isalphabeticchar(char_buffer));
    }

    // [Fails]
    assert(!unstd_isalphabeticchar('0'));

    notify("[+]", "`unstd_isalphabeticchar()` passed");
}

//! [isalphanumericchar]
void test_unstd_isalphanumericchar(void) {
    // [Succeeds]
    // [A-Z]
    for (unsigned char char_buffer = 'A'; char_buffer <= (unsigned char) 'Z'; char_buffer++) {
        assert(unstd_isalphanumericchar(char_buffer));
    }

    // [a-z]
    for (unsigned char char_buffer = 'a'; char_buffer <= (unsigned char) 'z'; char_buffer++) {
        assert(unstd_isalphanumericchar(char_buffer));
    }

    // [0-9]
    for (unsigned char char_buffer = '0'; char_buffer <= (unsigned char) '9'; char_buffer++) {
        assert(unstd_isalphanumericchar(char_buffer));
    }

    // [Fails]
    assert(!unstd_isalphanumericchar('-'));

    notify("[+]", "`unstd_isalphanumericchar()` passed");
}

//! [isdigitchar]
void test_unstd_isdigitchar(void) {
    // [Succeeds]
    // [0-9]
    for (unsigned char char_buffer = '0'; char_buffer <= (unsigned char) '9'; char_buffer++) {
        assert(unstd_isdigitchar(char_buffer));
    }

    // [Fails]
    assert(!unstd_isdigitchar('a'));
    assert(!unstd_isdigitchar(2));
    assert(!unstd_isdigitchar(0));
    assert(!unstd_isdigitchar(255));

    notify("[+]", "`unstd_isdigitchar()` passed");
}

//! [ishexchar]
void test_unstd_ishexchar(void) {
    // [Succeeds]
    // [A-F]
    for (unsigned char char_buffer = 'A'; char_buffer <= (unsigned char) 'F'; char_buffer++) {
//        printf("%c\n", char_buffer);
        assert(unstd_ishexchar(char_buffer));
    }

    // [a-f]
    for (unsigned char char_buffer = 'a'; char_buffer <= (unsigned char) 'f'; char_buffer++) {
        assert(unstd_ishexchar(char_buffer));
    }

    // [0-9]
    for (unsigned char char_buffer = '0'; char_buffer <= (unsigned char) '9'; char_buffer++) {
        assert(unstd_ishexchar(char_buffer));
    }

    // [Fails]
    assert(!unstd_ishexchar('g'));
    assert(!unstd_ishexchar('h'));
    assert(!unstd_ishexchar(255));
    assert(!unstd_ishexchar(0));

    notify("[+]", "`unstd_ishexchar()` passed");
}

//! [iswhitespace]
void test_unstd_iswhitespace(void) {
    // [Succeeds]
    assert(unstd_iswhitespace(' '));
    assert(unstd_iswhitespace('\t'));
    assert(unstd_iswhitespace('\r'));
    assert(unstd_iswhitespace('\n'));
    assert(unstd_iswhitespace(10));
    assert(unstd_iswhitespace(11));
    assert(unstd_iswhitespace(12));
    assert(unstd_iswhitespace(13));

    // [Fails]
    assert(!unstd_iswhitespace('\b'));
    assert(!unstd_iswhitespace('a'));
    assert(!unstd_iswhitespace('\2'));

    notify("[+]", "`unstd_iswhitespace()` passed");
}

//! [stringinit]
void test_unstd_stringinit(void) {
    unstd_string test_string_buffer = unstd_stringinit("Hello World!");

    // [Succeeds]
    assert(test_string_buffer.length == 12);
    assert(unstd_strcmp(test_string_buffer.buffer, "Hello World!"));

    // [Fails]
    assert(test_string_buffer.length != 0);

    unstd_stringfree(&test_string_buffer);
    notify("[+]", "`unstd_stringinit()` passed");
}

//! [stringpushchar]
void test_unstd_stringpushchar(void) {
    unstd_string test_string_buffer = unstd_stringinit("Hello World");

    unstd_stringpushchar(&test_string_buffer, '!');

    // [Succeeds]
    assert(test_string_buffer.length == 12);
    assert(unstd_strcmp(test_string_buffer.buffer, "Hello World!"));

    unstd_stringpushchar(&test_string_buffer, ' ');

    assert(test_string_buffer.length == 13);
    assert(unstd_strcmp(test_string_buffer.buffer, "Hello World! "));

    // [Fails]
    assert(test_string_buffer.length != 0);
    assert(!unstd_endswithchar(test_string_buffer.buffer, '+'));

    unstd_stringfree(&test_string_buffer);
    notify("[+]", "`unstd_stringpushchar()` passed");
}

//! [stringpushchar]
void test_unstd_stringpopchar(void) {
    unstd_string test_string_buffer = unstd_stringinit("Hello World!");

    unstd_stringpopchar(&test_string_buffer);

    // [Succeeds]
    assert(test_string_buffer.length == 11);
    assert(unstd_strcmp(test_string_buffer.buffer, "Hello World"));

    assert(unstd_stringpopchar(&test_string_buffer) == 'd');
    assert(test_string_buffer.length == 10);

    // [Fails]
    assert(test_string_buffer.length != 0);
    assert(!unstd_endswithchar(test_string_buffer.buffer, '!'));

    unstd_stringfree(&test_string_buffer);
    notify("[+]", "`unstd_stringpushchar()` passed");
}

//! [stringappendstr]
void test_unstd_stringappendstr(void) {
    unstd_string test_string_buffer = unstd_stringinit("Hello");

    unstd_stringappendstr(&test_string_buffer, " fuckin' world");

    // [Succeeds]
    assert(test_string_buffer.length == 19);
    assert(unstd_strcmp(test_string_buffer.buffer, "Hello fuckin' world"));

    // [Fails]
    assert(test_string_buffer.length != 0);
    assert(!unstd_endswithchar(test_string_buffer.buffer, 'o'));

    unstd_stringfree(&test_string_buffer);
    notify("[+]", "`unstd_stringappendstr()` passed");
}


void test_unstdstring(void) {
    //! [compare]
    test_unstd_charcmp();
    test_unstd_strcmp();
    test_unstd_strcmpignorecase();

    //! [startswith]
    test_unstd_startswithchar();
    test_unstd_startswithcharignorecase();

    //! [endswith]
    test_unstd_endswithchar();
    test_unstd_endswithcharignorecase();

    //! [tolower]
    test_unstd_tolowerstr();
    test_unstd_tolowerstrcopy();
    test_unstd_tolowerstrarray();

    //! [toupper]
    test_unstd_toupperstr();
    test_unstd_toupperstrcopy();
    test_unstd_toupperstrarray();

    //! [is]
    //! [isascii]
    test_unstd_isasciicontrolchar();
    test_unstd_isasciiprintablechar();
    test_unstd_isasciiextendedchar();

    test_unstd_isalphabeticchar();
    test_unstd_isalphanumericchar();
    test_unstd_isdigitchar();
    test_unstd_ishexchar();
    test_unstd_iswhitespace();

    //! [string]
    test_unstd_stringinit();
    test_unstd_stringpushchar();
    test_unstd_stringpopchar();
    test_unstd_stringappendstr();

    notify("[+]", "`unstdstring` passed");
}
