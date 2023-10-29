cmake_minimum_required(VERSION 3.25)
project(. C)

set(CMAKE_C_STANDARD 11)

#include_directories(src)
#include(CMakePrintHelpers)
#cmake_print_variables(library_files)

# ------------------------ [ unstdlib files ] ------------------------
set(locals_unstdlib
        src/lib.h
        src/_unstdcommon.h
        )

# - references
file(GLOB sources_unstdlib
        src/unstd*.c
        )

file(GLOB headers_unstdlib
        src/unstd*.h
        )

set(sources_and_headers_unstdlib
        ${sources_unstdlib}
        ${headers_unstdlib}
        )

set(all_unstdlib
        ${locals_unstdlib}
        ${sources_and_headers_unstdlib}
        )

# ------------------------ [ unstdlib testing ] ------------------------
# - locals
set(locals_test
        test/_test_common.h
        )

file(GLOB library_files ${sources_and_headers_unstdlib})
file(GLOB test_source_files test/test_headers/*/*.c)

add_library(. ${library_files})
foreach (test_source_file ${test_source_files})
    get_filename_component(test_source_file_name ${test_source_file} NAME_WE)
    add_executable(${test_source_file_name} ${test_source_file})
    target_link_libraries(${test_source_file_name} .)
endforeach (test_source_file ${test_source_files})

# ------------------------ [ unstdlib testing [all] ] ------------------------
set(test_unstdlib
        test/test_unstdlib.h
        test/test_unstdlib.c
        )

add_executable(test_all
        ${locals_test}
        ${test_unstdlib}
        ${all_unstdlib}
        )