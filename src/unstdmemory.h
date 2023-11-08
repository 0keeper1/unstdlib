#include <string.h>

/**
 * zeros all the bytes in `bufferArg`
 * @param bufferArg should be a heap-allocated buffer
 * @return a number indicating the state of operation
 * @return 0 - Failure
 * @return 1 - Success
 * @return 3 - Null Buffer
 */
unsigned char unstdmemory_stringbufferclear(void *const bufferArg);