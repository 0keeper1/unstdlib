#include "unstdstring.h"

char *tolowerstrcopy(const char *const strArg) {
  size_t strLength = strlen(strArg);
  char *allocationPtr = (char *)calloc(strLength + 1, sizeof(char));

  if (allocationPtr == NULL) {
    fprintf(stderr, "%.25s", "Failed to allocate memory");
    return NULL;
  }

  for (int i = 0; i < strLength; i++) {
    allocationPtr[i] = tolower((unsigned char)strArg[i]);
  }

  allocationPtr[strLength] = '\0';
  return allocationPtr;
}

bool endswith(const char *const stringArg, const char checkOnArg) {
  if (stringArg[strlen(stringArg) - 1] == checkOnArg) {
    return true;
  } else {
    return false;
  }
}

bool endswithignorecase(const char *const stringArg, const char checkOnArg) {
  if (tolower(stringArg[strlen(stringArg) - 1]) == tolower(checkOnArg)) {
    return true;
  } else {
    return false;
  }
}
