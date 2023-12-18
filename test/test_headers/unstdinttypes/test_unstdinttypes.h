#include "../../_test_common.h"

// Headers
#include "../../../src/unstdinttypes.h"


//! [unsigned_maximumM]
void test_unstdinttypes_unstdinttypes_unsigned_maximumM(void) {
    // [Succeeds]
    u8t test_1 = unstdinttypes_unsigned_maximumM(u8t);
    assert(test_1 > 0);
    assert(test_1 != 100);


    u16t test_2 = unstdinttypes_unsigned_maximumM(u16t);
    assert(test_2 > 0);
    assert(test_2 != 100);

    u64lt test_3 = unstdinttypes_unsigned_maximumM(u64lt);
    assert(test_3 > 1024);
    assert(test_3 != 100);

    _notify("[+]", "`unstdinttypes_unsigned_maximumM()` passed");
}


void test_unstdinttypes(void) {
    test_unstdinttypes_unstdinttypes_unsigned_maximumM();

    _notify("[+]", "`unstdinttypes` passed");
}
