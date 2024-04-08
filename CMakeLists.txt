project(Vector)

cmake_minimum_required(VERSION 3.25)

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

option(UNIT_TESTING OFF)
option(FUNCTIONAL_TESTING OFF)
option(TESTING OFF)
if(TESTING OR FUNCTIONAL_TESTING OR UNIT_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

target_include_directories(${TARGET}
    PUBLIC ${VECTOR_INCLUDE_ROOT}
)

set_target_properties(${TARGET}
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
