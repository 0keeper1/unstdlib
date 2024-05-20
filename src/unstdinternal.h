#ifndef UNSTDLIB_UNSTDINTERNAL_H
#define UNSTDLIB_UNSTDINTERNAL_H

#include <memory.h>
#include "unstdinttypes.h"

typedef enum : u8t {
    UNSTDINTERNAL_ARG_STATE_DIRECT_NULL_PASSED,
    UNSTDINTERNAL_ARG_STATE_POINTER_TO_NULL_PASSED,
    UNSTDINTERNAL_ARG_STATE_POINTER_TO_VARIABLE_PASSED,
    UNSTDINTERNAL_ARG_STATE_COUNT
} UNSTDINTERNAL_ARG_STATE;


/**
 * @brief Verifies whether `arg_arg` is a NULL pointer or a direct NULL.<br>
 *        If the check is successful, it then determines whether `arg_arg` is<br>
 *        actually pointing to a variable or is just a NULL pointer.
 * @param arg_arg The argument on which the check gets performed on.
 * @returns An enum of type `UNSTDINTERNAL_ARG_STATE`, containing the result of the operation.
 */
u8t unstdinternal_check_arg_state(
        void **arg_arg
);

void unstdinternal_state_based_arg_assignment(
        void **arg_arg,
        const void *value_arg,
        const sizet bytes_arg
);

#define unstdinternal_state_based_arg_assignmentM(arg_arg, value_arg, type_arg) \
do {                                                                            \
    void **temp_arg = (void **) arg_arg;                                        \
    switch (unstdinternal_check_arg_state(temp_arg)) {                          \
        case UNSTDINTERNAL_ARG_STATE_POINTER_TO_VARIABLE_PASSED:                \
        *arg_arg = value_arg;                                                   \
        /* memcpy(*arg_arg, &value_arg, bytes_arg); */                          \
        break;                                                                  \
    case UNSTDINTERNAL_ARG_STATE_POINTER_TO_NULL_PASSED:                        \
        /* Static assignment */                                                 \
        /* *((unsigned char *) arg_arg) = value_arg; */                         \
        *((type_arg *) arg_arg) = value_arg;                                    \
        /* Dynamic assignment */                                                \
        /* *((typeof(**arg_arg) *) arg_arg) = value_arg; */                     \
        /* memcpy(arg_arg, &value_arg, bytes_arg); */                           \
        break;                                                                  \
    case UNSTDINTERNAL_ARG_STATE_DIRECT_NULL_PASSED:                            \
    default:                                                                    \
        break;                                                                  \
    }                                                                           \
} while (0)

int outerrsetu8(unsigned char **out_error_arg, unsigned char value);

void dop(unsigned char **out_error_arg);


#endif