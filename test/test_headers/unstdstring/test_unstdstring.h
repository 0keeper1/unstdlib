#include "../../_test_common.h"

// Headers
#include "../../../src/unstdstring.h"

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

    strcpy(test_buffer_heap_allocated_copy, test_buffer_heap_allocated);
    strcpy(test_buffer_heap_allocated, "Hello, world!");

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

    strcpy(test_buffer_heap_allocated_copy, test_buffer_heap_allocated);
    strcpy(test_buffer_heap_allocated, "Hello, world!");

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

//! [stringinit]
void test_unstdstring_stringinit(void) {
    unstdstring_string test_string_buffer = unstdstring_stringinit("Hello World!");

    // [Succeeds]
    assert(test_string_buffer.length == 12);
    assert(unstdstring_strcmp(test_string_buffer.buffer, "Hello World!"));

    // [Fails]
    assert(test_string_buffer.length != 0);

    unstdstring_stringfree(&test_string_buffer);
    _notify("[+]", "`unstdstring_stringinit()` passed");
}

//! [stringpushchar]
void test_unstdstring_stringpushchar(void) {
    unstdstring_string test_string_buffer = unstdstring_stringinit("Hello World");

    unstdstring_stringpushchar(&test_string_buffer, '!');

    // [Succeeds]
    assert(test_string_buffer.length == 12);
    assert(unstdstring_strcmp(test_string_buffer.buffer, "Hello World!"));

    unstdstring_stringpushchar(&test_string_buffer, ' ');

    assert(test_string_buffer.length == 13);
    assert(unstdstring_strcmp(test_string_buffer.buffer, "Hello World! "));

    // [Fails]
    assert(test_string_buffer.length != 0);
    assert(!unstdstring_endswithchar(test_string_buffer.buffer, '+'));

    unstdstring_stringfree(&test_string_buffer);
    _notify("[+]", "`unstdstring_stringpushchar()` passed");
}

//! [stringpushchar]
void test_unstdstring_stringpopchar(void) {
    unstdstring_string test_string_buffer = unstdstring_stringinit("Hello World!");

    unstdstring_stringpopchar(&test_string_buffer);

    // [Succeeds]
    assert(test_string_buffer.length == 11);
    assert(unstdstring_strcmp(test_string_buffer.buffer, "Hello World"));

    assert(unstdstring_stringpopchar(&test_string_buffer) == 'd');
    assert(test_string_buffer.length == 10);

    // [Fails]
    assert(test_string_buffer.length != 0);
    assert(!unstdstring_endswithchar(test_string_buffer.buffer, '!'));

    unstdstring_stringfree(&test_string_buffer);
    _notify("[+]", "`unstdstring_stringpushchar()` passed");
}

//! [stringappendstr]
void test_unstdstring_stringappendstr(void) {
    unstdstring_string test_string_buffer = unstdstring_stringinit("Hello");

    unstdstring_stringappendstr(&test_string_buffer, " fuckin' world");

    // [Succeeds]
    assert(test_string_buffer.length == 19);
    assert(unstdstring_strcmp(test_string_buffer.buffer, "Hello fuckin' world"));

    // [Fails]
    assert(test_string_buffer.length != 0);
    assert(!unstdstring_endswithchar(test_string_buffer.buffer, 'o'));

    unstdstring_stringfree(&test_string_buffer);
    _notify("[+]", "`unstdstring_stringappendstr()` passed");
}

//! [stringclear]
void test_unstdstring_stringclear(void) {
    unstdstring_string test_string_buffer = unstdstring_stringinit("Hello");

    unstdstring_stringclear(&test_string_buffer);

    // [Succeeds]
    assert(test_string_buffer.length == 0);
    assert(unstdstring_strcmp(test_string_buffer.buffer, ""));

    // [Fails]
    assert(!(test_string_buffer.length != 0));
    assert(!unstdstring_endswithchar(test_string_buffer.buffer, 'o'));

    unstdstring_stringfree(&test_string_buffer);
    _notify("[+]", "`unstdstring_stringclear()` passed");
}


void test_unstdstring(void) {
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

    test_unstdstring_isalphabeticchar();
    test_unstdstring_isalphanumericchar();
    test_unstdstring_isdigitchar();
    test_unstdstring_ishexchar();
    test_unstdstring_iswhitespace();

    //! [string]
    test_unstdstring_stringinit();
    test_unstdstring_stringpushchar();
    test_unstdstring_stringpopchar();
    test_unstdstring_stringappendstr();
    test_unstdstring_stringclear();
    

    _notify("[+]", "`unstdstring` passed");
}
