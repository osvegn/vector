set(VECTOR_SOURCE_ROOT ${PROJECT_SOURCE_DIR}/source)
set(VECTOR_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/include)
set(TARGET vector)
set(VECTOR_SOURCE
    ${VECTOR_SOURCE_ROOT}/vector.c
)

set_property(GLOBAL PROPERTY VECTOR_SOURCE ${VECTOR_SOURCE})

option(SHARED OFF)
if(SHARED)
    add_library(${TARGET} SHARED ${VECTOR_SOURCE})
else()
    add_library(${TARGET} ${VECTOR_SOURCE})
endif()

option(TESTING OFF)
if(TESTING)
    enable_testing()
    add_compile_options("-lcriterion" "--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_link_options("-lcriterion" "--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_subdirectory(tests)
endif()

target_include_directories(${TARGET}
    PUBLIC ${VECTOR_INCLUDE_ROOT}
)
