#ifndef UNSTDLIB_H
#define UNSTDLIB_H

#ifdef __STDC__
#ifdef __STDC_VERSION__
#if (__STDC_VERSION__ < 201112L)
#error "Compiler's version should be at least C11."
#endif
#endif
#endif

#include "_unstdcommon.h"
#include "unstdinttypes.h"
#include "unstdbool.h"
#include "unstdmemory.h"
#include "unstdstring.h"
#include "unstdio.h"

#endif /* UNSTDLIB_H */