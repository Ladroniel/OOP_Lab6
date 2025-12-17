cmake_minimum_required(VERSION 3.16)
project(OOP_Lab6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB LAB06_SRC CONFIGURE_DEPENDS src/*.cpp)

add_executable(lab06 ${LAB06_SRC})
target_include_directories(lab06 PRIVATE include)

if (UNIX)
    target_link_libraries(lab06 PRIVATE pthread)
endif()


enable_testing()
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SRC CONFIGURE_DEPENDS tests/*.cpp)

set(CORE_SRC ${LAB06_SRC})
list(FILTER CORE_SRC EXCLUDE REGEX ".*/main\\.cpp$")

add_executable(lab06_tests
    ${TEST_SRC}
    ${CORE_SRC}
)

target_include_directories(lab06_tests PRIVATE include)

target_link_libraries(lab06_tests
    PRIVATE
        gtest
        gtest_main
)

if (UNIX)
    target_link_libraries(lab06_tests PRIVATE pthread)
endif()

add_test(NAME Lab06Tests COMMAND lab06_tests)

