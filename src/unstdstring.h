#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tolowerstr(char (*strArg)[]);
char *tolowerstrcopy(const char *const strArg);
char *toupperstr(char (*strArg)[]);
char *toupperstrcopy(const char *const strArg);

bool endswith(const char *const stringArg, const char checkOnArg);
bool endswithignorecase(const char *const stringArg, const char checkOnArg);
