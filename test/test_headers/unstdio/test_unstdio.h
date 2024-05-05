#include "../../_test_common.h"

// Headers
#include "../../../src/unstdinttypes.h"
#include "../../../src/unstdio.h"


//! [openfile]
void test_unstdio_openfile(void) {
    FILE *fileptr = NULL;

    // [Succeeds]
    // Creating a new file.
    assert(unstdio_openfile("test_stringliteral.txt", "w", &fileptr) == 1);
    fclose(fileptr);

    // Trying to access thee previously created file with read permission.
    assert(unstdio_openfile("test_stringliteral.txt", "r", &fileptr) == 1);
    fclose(fileptr);

    // [Fails]
    // Trying to access a non-existent file.
    assert(unstdio_openfile("abc000.000", "r", &fileptr) == 0);

    // Trying to pass NULL file handle.
    assert(unstdio_openfile("abc000.000", "r", NULL) == 6);

    _notify("[+]", "`unstdio_openfile()` passed");
}

//! [isfdvalid]
void test_unstdio_isfdvalid(void) {
    FILE *fileptr = NULL;

    // [Succeeds]
    // Creating a new file.
    assert(unstdio_openfile("test_stringliteral.txt", "w", &fileptr) == 1);

    // Trying to check the previously created/opened file.
    assert(unstdio_isfdvalid(fileptr->_fileno));

    // [Fails]
    // Trying to check on a closed file.
    fclose(fileptr);
    assert(!unstdio_isfdvalid(fileptr->_fileno));

    _notify("[+]", "`unstdio_isfdvalid()` passed");
}

//! [isfilestreamvalid]
void test_unstdio_isfilestreamvalid(void) {
    FILE *fileptr = NULL;

    // [Succeeds]
    // Creating a new file.
    assert(unstdio_openfile("test_stringliteral.txt", "w", &fileptr) == 1);

    // Trying to check the previously created/opened file.
    assert(unstdio_isfilestreamvalid(fileptr));

    // [Fails]
    // Trying to check on a closed file.
    fclose(fileptr);
    assert(!unstdio_isfilestreamvalid(fileptr));

    _notify("[+]", "`unstdio_isfdvalid()` passed");
}

//! [closefile]
void test_unstdio_closefile(void) {
    FILE *fileptr = NULL;

    // [Succeeds]
    // Creating a new file.
    assert(unstdio_openfile("test_stringliteral.txt", "w", &fileptr) == 1);

    // Trying to close the previously created/opened file.
    assert(unstdio_closefile(fileptr) == 1);

    // [Fails]
    // Trying to pass NULL file handle.
    assert(unstdio_closefile(NULL) == 2);

    // Trying to double-close a file handle.
    assert(unstdio_closefile(fileptr) == 3);

    _notify("[+]", "`unstdio_closefile()` passed");
}

//! [removefile]
void test_unstdio_removefile(void) {
    FILE *fileptr = NULL;

    // [Succeeds]
    // Creating a new file.
    assert(unstdio_openfile("test_stringliteral.txt", "w", &fileptr) == 1);
    unstdio_closefile(fileptr);

    // Trying to remove the previously created/opened file.
    assert(unstdio_removefile("test_stringliteral.txt") == 1);

    // [Fails]
    // Trying to remove a non-existent file.
    assert(unstdio_removefile("abc000.000") == 5);

    // Trying to pass NULL filepath.
    assert(unstdio_removefile(NULL) == 2);

    // Trying to pass empty filepath.
    assert(unstdio_removefile("") == 3);

    _notify("[+]", "`unstdio_removefile()` passed");
}

//! [doesfileexist]
void test_unstdio_doesfileexist(void) {
    FILE *fileptr = NULL;

    // [Succeeds]
    // Creating a new file.
    assert(unstdio_openfile("test_stringliteral.txt", "w", &fileptr) == 1);
    unstdio_closefile(fileptr);

    // Trying to perform search on the previously created/opened file.
    assert(unstdio_doesfileexist("test_stringliteral.txt") == 1);

    // [Fails]
    // Trying to check a non-existent file.
    assert(unstdio_doesfileexist("abc000.000") == 0);

    // Trying to pass NULL filepath.
    assert(unstdio_doesfileexist(NULL) == 2);

    // Trying to pass empty filepath.
    assert(unstdio_doesfileexist("") == 3);

    _notify("[+]", "`unstdio_doesfileexist()` passed");
}

//! [isregularfile]
void test_unstdio_isregularfile(void) {
    FILE *fileptr = NULL;

    // [Succeeds]
    // Creating a new file.
    assert(unstdio_openfile("test_stringliteral.txt", "w", &fileptr) == 1);
    unstdio_closefile(fileptr);

    // Trying to perform search on the previously created/opened file.
    assert(unstdio_isregularfile("test_stringliteral.txt") == 1);

    // [Fails]
    // Trying to check a non-existent file.
    assert(unstdio_isregularfile("abc000.000") == 4);

    // Trying to pass NULL filepath.
    assert(unstdio_isregularfile(NULL) == 2);

    // Trying to pass empty filepath.
    assert(unstdio_isregularfile("") == 3);

    _notify("[+]", "`unstdio_isregularfile()` passed");
}

//! [getfilesize]
void test_unstdio_getfilesize(void) {
    FILE *fileptr = NULL;

    // [Succeeds]
    // Creating a new file.
    assert(unstdio_openfile("test_stringliteral.txt", "w+", &fileptr) == 1);

    // Writing 12 bytes of data into the previously created/opened file.
    fprintf(fileptr, "%s", "Hello world!");
    fflush(fileptr);

    // Trying to perform search on the previously created/opened file.
    assert(unstdio_getfilesize(fileptr) == 12);

    // [Fails]
    // Trying to pass NULL file stream.
    assert(unstdio_getfilesize(NULL) == -1);

    // Trying to pass closed/invalid file stream.
    unstdio_closefile(fileptr);
    assert(unstdio_getfilesize(fileptr) == -2);

    unstdio_closefile(fileptr);

    _notify("[+]", "`unstdio_getfilesize()` passed");
}


void test_unstdio(void) {
    test_unstdio_openfile();
    test_unstdio_isfdvalid();
    test_unstdio_isfilestreamvalid();
    test_unstdio_closefile();
    test_unstdio_removefile();
    test_unstdio_doesfileexist();
    test_unstdio_isregularfile();
    test_unstdio_getfilesize();

    _notify("[+]", "`unstdio` passed");
}