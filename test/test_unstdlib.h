#ifndef UNSTDLIB_TEST_UNSTDLIB_H
#define UNSTDLIB_TEST_UNSTDLIB_H

#include "_test_common.h"
#include "test_headers/unstdstring/test_unstdstring.h"
#include "test_headers/unstdmemory/test_unstdmemory.h"
#include "test_headers/unstdpair/test_unstdpair.h"
#include "test_headers/unstdio/test_unstdio.h"


void test_unstdlib_all(void) {
    test_unstdmemory();
    test_unstdstring();
    test_unstdio();
    test_unstdpair();
}

#endif /* UNSTDLIB_TEST_UNSTDLIB_H */
