//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "DayTwo.h"

#include "DayTwoParser.h"

namespace AdventOfCode::DayTwo {

    constexpr int kDayTwoPartOneAnswer = 572;
    constexpr int kDayTwoPartTwoAnswer = 0;

    TEST(DayTwo, partOne) {
        const Input input = Parser::parseFile(Parser::kDayTwoInputFilePath);
        int result = partOneSolution(input);

        EXPECT_EQ(kDayTwoPartOneAnswer, result);
    }

    TEST(DayTwo, partTwo) {
        const Input input = Parser::parseFile(Parser::kDayTwoInputFilePath);
        int result = partTwoSolution(input);

        EXPECT_EQ(kDayTwoPartTwoAnswer, result);
    }

    TEST(DayTwo, benchmarkPartOne) {
        const Input input = Parser::parseFile(Parser::kDayTwoInputFilePath);

        ankerl::nanobench::Bench().run("Day 2 Part 1", [&]() {
            ankerl::nanobench::doNotOptimizeAway(partOneSolution(input));
        });
    }

    TEST(DayTwo, benchmarkPartTwo) {
        const Input input = Parser::parseFile(Parser::kDayTwoInputFilePath);

        ankerl::nanobench::Bench().run("Day 2 Part 2", [&]() {
            ankerl::nanobench::doNotOptimizeAway(partTwoSolution(input));
        });
    }

} // AdventOfCode::DayOne