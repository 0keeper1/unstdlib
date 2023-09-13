#include "unstdstring.h"

bool endswith(const char *const stringArg, const char checkOnArg) {
    if (stringArg[strlen(stringArg) - 1] == checkOnArg) { return true;}
    else {return false;}
}


bool endswithignorecase(const char *const stringArg, const char checkOnArg) {
    if (tolower(stringArg[strlen(stringArg) - 1]) == tolower(checkOnArg)) { return true;}
    else {return false;}
}
