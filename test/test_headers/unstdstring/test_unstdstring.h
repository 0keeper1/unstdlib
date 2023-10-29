#include <dont/Beautifier/beautifier-c.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Headers
#include "../../../src/unstdstring.h"

//! [strcmp]
void test_unstd_strcmp(void) {
    // [Succeeds]
    assert(unstd_strcmp("0", "0"));
    assert(unstd_strcmp("\0", "\0"));
    assert(unstd_strcmp("\x1\n", "\x1\n"));
    assert(unstd_strcmp("\x33", "\x33"));
    assert(unstd_strcmp("\n\n\n\r\r\r", "\n\n\n\r\r\r"));

    // [Fails]
    assert(!unstd_strcmp("\0", "0"));
    assert(!unstd_strcmp(0, 0));
    assert(!unstd_strcmp("32", "0"));
    assert(!unstd_strcmp("\n\n\n\r\r\r\b", "\n\n\n\r\r\r"));
    assert(!unstd_strcmp(NULL, NULL));

    notify("[+]", "`unstd_strcmp()` passed");
}

//! [endswith]
void test_unstd_endswith(void) {
    char *test_buffer = "Hello, world!";

    // [Succeeds]
    assert(unstd_endswith(test_buffer, '!'));

    // [Fails]
    assert(!unstd_endswith(test_buffer, 'a'));
    assert(!unstd_endswith(test_buffer, ' '));
    assert(!unstd_endswith(test_buffer, '\42'));
    assert(!unstd_endswith(test_buffer, '\n'));
    assert(!unstd_endswith(test_buffer, '\r'));
    assert(!unstd_endswith(test_buffer, '$'));
    assert(!unstd_endswith(test_buffer, 0xff));
    assert(!unstd_endswith(test_buffer, -2));
    assert(!unstd_endswith(test_buffer, 0));
    assert(!unstd_endswith(test_buffer, '\0'));

    notify("[+]", "`unstd_endswith()` passed");
}

//! [endswithignorecase]
void test_unstd_endswithignorecase(void) {
    char *test_buffer = "Hello, world";

    // [Succeeds]
    assert(unstd_endswithignorecase(test_buffer, 'd'));
    assert(unstd_endswithignorecase(test_buffer, 'D'));

    // [Fails]
    assert(!unstd_endswithignorecase(test_buffer, ' '));
    assert(!unstd_endswithignorecase(test_buffer, '\42'));
    assert(!unstd_endswithignorecase(test_buffer, '\n'));
    assert(!unstd_endswithignorecase(test_buffer, '\r'));
    assert(!unstd_endswithignorecase(test_buffer, '$'));
    assert(!unstd_endswithignorecase(test_buffer, 0xff));
    assert(!unstd_endswithignorecase(test_buffer, -2));
    assert(!unstd_endswithignorecase(test_buffer, 0));
    assert(!unstd_endswithignorecase(test_buffer, '\0'));

    notify("[+]", "`unstd_endswithignorecase()` passed");
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

//! [isasciicontrolcharacter]
void test_unstd_isasciicontrolcharacter(void) {
    for (unsigned char ascii_buffer = 0x0; ascii_buffer <= 0x1F; ascii_buffer++) {
        assert(unstd_isasciicontrolcharacter(ascii_buffer));
    }
    assert(unstd_isasciicontrolcharacter(0x7F));

    notify("[+]", "`unstd_isasciicontrolcharacter()` passed");
}

//! [isasciiprintablecharacter]
void test_unstd_isasciiprintablecharacter(void) {
    for (unsigned char ascii_buffer = 0x20; ascii_buffer <= 0x7E; ascii_buffer++) {
        assert(unstd_isasciiprintablecharacter(ascii_buffer));
    }

    notify("[+]", "`unstd_isasciiprintablecharacter()` passed");
}

//! [isasciiextendedcharacter]
void test_unstd_isasciiextendedcharacter(void) {
    for (unsigned char ascii_buffer = 0x80; ascii_buffer >= 0x80 && ascii_buffer <= 0xFF; ascii_buffer++) {
        assert(unstd_isasciiextendedcharacter(ascii_buffer));
    }

    notify("[+]", "`unstd_isasciiextendedcharacter()` passed");
}


void test_unstdstring(void) {
    test_unstd_strcmp();

    test_unstd_endswith();
    test_unstd_endswithignorecase();

    test_unstd_tolowerstr();
    test_unstd_tolowerstrcopy();
    test_unstd_tolowerstrarray();

    test_unstd_toupperstr();
    test_unstd_toupperstrcopy();
    test_unstd_toupperstrarray();

    test_unstd_isasciicontrolcharacter();
    test_unstd_isasciiprintablecharacter();
    test_unstd_isasciiextendedcharacter();

    notify("[+]", "`unstdstring` passed");
}
