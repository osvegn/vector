project(Vector)

cmake_minimum_required(VERSION 3.25)

option(UNIT_TESTING OFF)
option(FUNCTIONAL_TESTING OFF)
option(TESTING OFF)
if(TESTING OR FUNCTIONAL_TESTING OR UNIT_TESTING)
    enable_testing()
    add_compile_options("--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_link_options("--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_subdirectory(tests)
endif()

add_subdirectory(source)
