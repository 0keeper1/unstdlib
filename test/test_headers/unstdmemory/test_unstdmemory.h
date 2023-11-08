#include "../../_test_common.h"

// Headers
#include "../../../src/unstdmemory.h"


//! [stringbufferclear]
void test_unstdmemory_stringbufferclear(void) {
    // heap-allocated test
    char *test_buffer_heap_allocated = (char *) malloc(32);
    strcpy(test_buffer_heap_allocated, "Hello, world!");

    unsigned char test_result = unstdmemory_stringbufferclear(test_buffer_heap_allocated);

    // [Fails]
    assert(!(test_result == 3));
    assert(!(test_result == 0));

    // [Succeeds]
    assert(test_result == 1);
    assert(!*test_buffer_heap_allocated);

    _notify("[+]", "`unstdmemory_stringbufferclear()` passed");
}

void test_unstdmemory(void) {
    test_unstdmemory_stringbufferclear();

    _notify("[+]", "`unstdmemory` passed");
}