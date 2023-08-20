set(VECTOR_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests)
set(VECTOR_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/include)

set(TARGET vector_tests)
set(SOURCE
    ${VECTOR_TESTS_ROOT}/vector_tests.c
)

add_executable(${TARGET} ${SOURCE} ${VECTOR_SOURCE})

add_test(${TARGET} ${TARGET})

target_include_directories(${TARGET}
    PUBLIC ${VECTOR_INCLUDE_ROOT}
)
