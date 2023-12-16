#ifndef UNSTDLIB_UNSTDPAIR_H
#define UNSTDLIB_UNSTDPAIR_H

#define unstdpair_pair_onstackM(type_first_arg, type_second_arg)\
struct {                                                        \
    type_first_arg first;                                       \
    type_second_arg second;                                     \
}

#endif /* UNSTDLIB_UNSTDPAIR_H */