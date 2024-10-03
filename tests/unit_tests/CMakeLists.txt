set(VECTOR_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests)
set(CRITERION_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/submodules/Criterion/include)

set(CRITERION_LIB ${PROJECT_SOURCE_DIR}/submodules/Criterion/build/src/libcriterion.so.3.2.0)
# set(VECTOR_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/include)

# set(TARGET vector_tests)
set(SOURCES
    ${VECTOR_TESTS_ROOT}/vector_at.c
    ${VECTOR_TESTS_ROOT}/vector_back.c
    ${VECTOR_TESTS_ROOT}/vector_capacity.c
    ${VECTOR_TESTS_ROOT}/vector_clear.c
    ${VECTOR_TESTS_ROOT}/vector_constructor.c
    ${VECTOR_TESTS_ROOT}/vector_destructor.c
    ${VECTOR_TESTS_ROOT}/vector_emplace_back.c
    ${VECTOR_TESTS_ROOT}/vector_emplace.c
    ${VECTOR_TESTS_ROOT}/vector_empty.c
    ${VECTOR_TESTS_ROOT}/vector_erase.c
    ${VECTOR_TESTS_ROOT}/vector_front.c
    ${VECTOR_TESTS_ROOT}/vector_pop_back.c
    ${VECTOR_TESTS_ROOT}/vector_print.c
    ${VECTOR_TESTS_ROOT}/vector_print_at.c
    ${VECTOR_TESTS_ROOT}/vector_shrink_to_fit.c
    ${VECTOR_TESTS_ROOT}/vector_size.c
    ${VECTOR_TESTS_ROOT}/vector_swap.c
    ${VECTOR_TESTS_ROOT}/vector_operation_eq.c
)

add_compile_options("--coverage" "-fprofile-arcs" "-ftest-coverage")
add_link_options("--coverage" "-fprofile-arcs" "-ftest-coverage")

# add_executable(${TARGET} ${SOURCE} ${VECTOR_SOURCE})

# add_test(${TARGET} ${TARGET})

# target_include_directories(${TARGET}
#     PUBLIC ${VECTOR_INCLUDE_ROOT}
# )

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

foreach(SOURCE ${SOURCES})
    string(REPLACE "/" ";" SOURCE_LIST ${SOURCE})
    list(GET SOURCE_LIST -1 SOURCE_ITEM)
    string(REPLACE ".c" "" T_NAME ${SOURCE_ITEM})
    create_test(
        TEST_NAME ${T_NAME}
        TEST_SRC ${SOURCE}
        TEST_DEPS vector
        TEST_INCLUDE ${PROJECT_SOURCE_DIR}/include ${CRITERION_INCLUDE_ROOT}
    )
endforeach()
