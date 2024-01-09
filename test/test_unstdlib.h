#ifndef UNSTDLIB_TEST_UNSTDLIB_H
#define UNSTDLIB_TEST_UNSTDLIB_H

#include "_test_common.h"
#include "test_headers/unstdinttypes/test_unstdinttypes.h"
#include "test_headers/_unstdcommon/test__unstdcommon.h"
#include "test_headers/unstditertools/test_unstditertools.h"
#include "test_headers/unstdmemory/test_unstdmemory.h"
#include "test_headers/unstdstring/test_unstdstring.h"
#include "test_headers/unstdpair/test_unstdpair.h"
#include "test_headers/unstdio/test_unstdio.h"
#include "test_headers/unstdvector/test_unstdvector.h"


void test_unstdlib_all(void) {
    test_unstdinttypes();
    test__unstdcommon();
    test_unstditertools();
    test_unstdmemory();
    test_unstdstring();
    test_unstdpair();
    test_unstdio();
    test_unstdvector();
}

#endif /* UNSTDLIB_TEST_UNSTDLIB_H */
