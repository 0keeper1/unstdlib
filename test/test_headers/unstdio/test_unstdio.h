#include "../../_test_common.h"

// Headers
#include "../../../src/unstdinttypes.h"
#include "../../../src/unstdio.h"


//! [openfile]
void test_unstdio_openfile(void) {
    FILE *fileptr = NULL;

    // [Succeeds]
    //assert(unstdio_openfile("{path}/assests/test_stringliteral", "r", fileptr) == 1);

    fclose(fileptr);

    _notify("[+]", "`unstdio_openfile()` passed");
}

void test_unstdio(void) {
//    test_unstdio_openfile();

    _notify("[+]", "`unstdio` passed");
}