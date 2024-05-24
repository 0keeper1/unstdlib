#ifndef UNSTDLIB_UNSTDPAIR_H
#define UNSTDLIB_UNSTDPAIR_H

#ifndef unstdpair_pairM
#define unstdpair_pairM(type_first_arg, type_second_arg)   \
    struct {                                               \
        type_first_arg first;                              \
        type_second_arg second;                            \
    }
#endif

#endif /* UNSTDLIB_UNSTDPAIR_H */
