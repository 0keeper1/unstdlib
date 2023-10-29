#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


bool unstd_strcmp(const char *const fBufferArg, const char *const sBufferArg);

bool unstd_endswithchar(const char *const bufferArg, const char checkOnArg);
bool unstd_endswithcharignorecase(const char *const bufferArg, const char checkOnArg);

void unstd_tolowerstr(char *const bufferArg);
char *unstd_tolowerstrcopy(const char *const bufferArg);
void unstd_tolowerstrarray(char (*const bufferArg)[]);

void unstd_toupperstr(char *const bufferArg);
char *unstd_toupperstrcopy(const char *const bufferArg);
void unstd_toupperstrarray(char (*const bufferArg)[]);

bool unstd_isasciicontrolchar(const unsigned char bufferArg);
bool unstd_isasciiprintablechar(const unsigned char bufferArg);
bool unstd_isasciiextendedchar(const unsigned char bufferArg);

bool unstd_isalphabeticchar(const unsigned char bufferArg);
bool unstd_isalphanumericchar(const unsigned char bufferArg);
bool unstd_isdigitchar(const unsigned char bufferArg);