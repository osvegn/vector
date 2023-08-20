set(VECTOR_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests/functional)

function (create_test)
    set (test_name TEST_NAME)
    set (test_src TEST_SRC TEST_DEPS TEST_INCLUDE)
    cmake_parse_arguments(create_test "" "${test_name}" "${test_src}" ${ARGN})

    if (NOT DEFINED create_test_TEST_NAME)
        message (FATAL_ERROR "create_test: TEST_NAME not defined")
    endif()
    if (NOT DEFINED create_test_TEST_SRC)
        message (FATAL_ERROR "create_test: TEST_SRC not defined")
    endif()

    set (SRC "${create_test_TEST_SRC}")
    set (TEST_NAME "test_${create_test_TEST_NAME}")
    set (TEST_DEPS "${create_test_TEST_DEPS}")
    set (TEST_INCLUDE "${create_test_TEST_INCLUDE}")
    add_executable(${TEST_NAME} ${SRC})
    target_include_directories(${TEST_NAME} PRIVATE ${TEST_INCLUDE})
    target_link_libraries(${TEST_NAME} ${TEST_DEPS} ${CRITERION_LIB})
    add_test(${TEST_NAME} ${TEST_NAME})
endfunction()

set(SRC
    ${VECTOR_TESTS_ROOT}/vector_of_int.c
)

create_test(
    TEST_NAME vector_of_int
    TEST_SRC ${SRC}
    TEST_DEPS vector
    TEST_INCLUDE ${PROJECT_SOURCE_DIR}/include
)

set(SRC
    ${VECTOR_TESTS_ROOT}/vector_of_string.c
)

create_test(
    TEST_NAME vector_of_string
    TEST_SRC ${SRC}
    TEST_DEPS vector
    TEST_INCLUDE ${PROJECT_SOURCE_DIR}/include
)
