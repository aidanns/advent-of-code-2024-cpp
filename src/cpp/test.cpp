#include <gtest/gtest.h>
#include <nanobench.h>

namespace AdventOfCode::DayZero {

    TEST(DayZero, placeholder) {
        EXPECT_EQ(0, 0);
    }

    TEST(DayZero, placeholderBenchmark) {
        ankerl::nanobench::Bench().run("Day 0 Placeholder", [&]() {});
    }
} // AdventOfCode
