cmake_minimum_required(VERSION 3.31)
project(advent_of_code_2024_cpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Statically link libraries so we can run in a Docker scratch container.
#set(BUILD_SHARED_LIBS OFF)
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2)
FetchContent_Declare(asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG asio-1-32-0
        CONFIGURE_COMMAND ""
        BUILD_COMMAND "")
FetchContent_Declare(
        nanobench
        GIT_REPOSITORY https://github.com/martinus/nanobench.git
        GIT_TAG v4.3.11
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(asio googletest nanobench)

add_library(asio INTERFACE)
target_include_directories(asio INTERFACE ${asio_SOURCE_DIR}/asio/include)
find_package(Threads)
target_link_libraries(asio INTERFACE Threads::Threads)

enable_testing()

configure_file(src/cmake/AdventOfCodeConfig.h.in src/cpp/generated/AdventOfCodeConfig.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src/cpp)

add_executable(
        advent_of_code_2024_cpp
        src/cpp/main.cpp
)

target_link_libraries(
        advent_of_code_2024_cpp PUBLIC
        ${EXTRA_LIBS}
        GTest::gtest_main
        asio
)

target_include_directories(
        advent_of_code_2024_cpp PUBLIC
        "${PROJECT_BINARY_DIR}"
        ${EXTRA_INCLUDES}
)

add_executable(
        advent_of_code_2024_cpp_test
        src/cpp/test.cpp
)

target_link_libraries(
        advent_of_code_2024_cpp_test PUBLIC
        ${EXTRA_LIBS}
        asio
        GTest::gtest_main
        nanobench
)

target_include_directories(
        advent_of_code_2024_cpp_test PUBLIC
        "${PROJECT_BINARY_DIR}"
        ${EXTRA_INCLUDES}
)

include(GoogleTest)
gtest_discover_tests(advent_of_code_2024_cpp_test)
