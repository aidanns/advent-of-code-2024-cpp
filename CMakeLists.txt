cmake_minimum_required(VERSION 3.31)
project(advent_of_code_2024_cpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")

# Statically link libraries so we can run in a Docker scratch container.
#set(BUILD_SHARED_LIBS OFF)
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
        GIT_SHALLOW TRUE)
FetchContent_Declare(
        asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG asio-1-32-0
        GIT_SHALLOW TRUE)
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
        src/cpp/DayOne.cpp
        src/cpp/DayOne.h
        src/cpp/DayOneParser.cpp
        src/cpp/DayOneParser.h
        src/cpp/DayTwo.cpp
        src/cpp/DayTwo.h
        src/cpp/DayTwoParser.cpp
        src/cpp/DayTwoParser.h
        src/cpp/InputFileReader.cpp
        src/cpp/InputFileReader.h
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

target_compile_features(advent_of_code_2024_cpp PUBLIC cxx_std_23)

add_executable(
        advent_of_code_2024_cpp_test
        src/cpp/DayOne.cpp
        src/cpp/DayOne.h
        src/cpp/DayOneParser.cpp
        src/cpp/DayOneParser.h
        src/cpp/DayOneParserTests.cpp
        src/cpp/DayOneTests.cpp
        src/cpp/DayTwo.cpp
        src/cpp/DayTwo.h
        src/cpp/DayTwoParser.cpp
        src/cpp/DayTwoParser.h
        src/cpp/DayTwoParserTests.cpp
        src/cpp/DayTwoTests.cpp
        src/cpp/InputFileReader.cpp
        src/cpp/InputFileReader.h
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
