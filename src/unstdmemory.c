#include "unstdmemory.h"


unsigned char unstdmemory_stringbufferclear(void *const bufferArg) {
    if (bufferArg == NULL) {
        return 3;
    }

    return memset(bufferArg, 0, strlen(bufferArg) + 1) == NULL ? 0 : 1;
}
