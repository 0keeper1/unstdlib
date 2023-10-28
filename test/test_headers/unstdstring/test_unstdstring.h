#include <dont/Beautifier/beautifier-c.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Headers
#include "unstdstring.h"

//! [endswith]
void test_unstd_endswith(void) {
    char *testStr = "Hello !";

    assert(unstd_endswith(testStr, '!') ? '+' : '-' == '+');
    assert(unstd_endswith(testStr, 'a') ? '+' : '-' == '-');
    assert(unstd_endswith(testStr, ' ') ? '+' : '-' == '-');
    assert(unstd_endswith(testStr, '\42') ? '+' : '-' == '-');
    assert(unstd_endswith(testStr, '\n') ? '+' : '-' == '-');
    assert(unstd_endswith(testStr, '\r') ? '+' : '-' == '-');
    assert(unstd_endswith(testStr, '$') ? '+' : '-' == '-');
    assert(unstd_endswith(testStr, 0xff) ? '+' : '-' == '-');
    assert(unstd_endswith(testStr, -2) ? '+' : '-' == '-');
    assert(unstd_endswith(testStr, 0) ? '+' : '-' == '-');
    assert(unstd_endswith(testStr, '\0') ? '+' : '-' == '-');
    notify("[+]", "`unstd_endswith()` passed");
}

//! [endswithignorecase]
void test_unstd_endswithignorecase(void) {
    char *testStr = "Hello World";

    assert(unstd_endswithignorecase(testStr, 'd') ? '+' : '-' == '-');
    assert(unstd_endswithignorecase(testStr, 'D') ? '+' : '-' == '+');
    assert(unstd_endswithignorecase(testStr, ' ') ? '+' : '-' == '-');
    assert(unstd_endswithignorecase(testStr, '\42') ? '+' : '-' == '-');
    assert(unstd_endswithignorecase(testStr, '\n') ? '+' : '-' == '-');
    assert(unstd_endswithignorecase(testStr, '\r') ? '+' : '-' == '-');
    assert(unstd_endswithignorecase(testStr, '$') ? '+' : '-' == '-');
    assert(unstd_endswithignorecase(testStr, 0xff) ? '+' : '-' == '-');
    assert(unstd_endswithignorecase(testStr, -2) ? '+' : '-' == '-');
    assert(unstd_endswithignorecase(testStr, 0) ? '+' : '-' == '-');
    assert(unstd_endswithignorecase(testStr, '\0') ? '+' : '-' == '-');
}

//! [tolowerstrcopy]
void test_unstd_tolowerstrcopy(void) {
    const char *input = "Hello, World!";
    char *result = unstd_tolowerstrcopy(input);
    printf("[%.100s]\n", result);
    free(result);

    printf("[%.100s]\n", unstd_tolowerstrcopy("HEEElooo!!!"));
}

//! [tolowerstr]
void test_unstd_tolowerstr(void) {
    char input[] = "Hello, World!";
    unstd_tolowerstr(&input);
    printf("[%.100s]\n", input);
    char input2[] = "Hello, WorldwW@RFE222!";
    printf("[%.100s]\n", unstd_tolowerstr(&input2));
}

//! [toupperstrcopy]
void test_unstd_toupperstrcopy(void) {
    const char *input = "Hello, World! toupperstrcopy";
    char *result = unstd_toupperstrcopy(input);
    printf("[%.100s]\n", result);
    free(result);

    printf("[%.100s]\n", unstd_toupperstrcopy("HEEElooo!!! toupperstrcopy"));
}

//! [toupperstr]
void test_unstd_toupperstr(void) {
    char input[] = "Hello, World!";
    unstd_toupperstr(&input);
    printf("[%.100s]\n", input);
    char input2[] = "Hello, WorldwW@RFE222!";
    printf("[%.100s]\n", unstd_toupperstr(&input2));
}

void test_unstdstring(void) {
    test_unstd_endswith();
    test_unstd_endswithignorecase();

    // test_endswithignorecase(); [+]
    // test_tolowerstrcopy(); [+]
    // test_tolowerstr(); [+]
//  test_toupperstr();
//  test_toupperstrcopy();
}
