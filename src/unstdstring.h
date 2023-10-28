#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


bool unstd_strcmp(const char *const fBufferArg, const char *const sBufferArg);

bool unstd_endswith(const char *const stringArg, const char checkOnArg);
bool unstd_endswithignorecase(const char *const stringArg, const char checkOnArg);

void unstd_tolowerstr(char *const bufferArg);
char *unstd_tolowerstrcopy(const char *const bufferArg);
void unstd_tolowerstrarray(char (*const bufferArg)[]);

void unstd_toupperstr(char *const bufferArg);
char *unstd_toupperstrcopy(const char *const bufferArg);
void unstd_toupperstrarray(char (*const bufferArg)[]);

bool unstd_isasciicontrolcharacter(const unsigned char bufferArg);