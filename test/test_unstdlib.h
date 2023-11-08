#ifndef UNSTDLIB_TEST_UNSTDLIB_HPP
#define UNSTDLIB_TEST_UNSTDLIB_HPP

#include "_test_common.h"
#include "test_headers/unstdstring/test_unstdstring.h"
#include "test_headers/unstdmemory/test_unstdmemory.h"


void test_unstdlib_all(void) {
    test_unstdstring();
    test_unstdmemory();
}

#endif //UNSTDLIB_TEST_UNSTDLIB_HPP
