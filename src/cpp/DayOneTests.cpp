//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "DayOne.h"

#include "DayOneParser.h"

namespace AdventOfCode::DayOne {

    constexpr int kDayOnePuzzleOneAnswer = 2742123;
    constexpr int kDayOnePartTwoAnswer = 21328497;

    TEST(DayOne, puzzleOne) {
        const Input input = Parser::parseFile(Parser::kDayOneInputFilePath);
        int result = partOneSolution(input);

        EXPECT_EQ(kDayOnePuzzleOneAnswer, result);
    }

    TEST(DayOne, partTwo) {
        const Input input = Parser::parseFile(Parser::kDayOneInputFilePath);
        int result = partTwoSolution(input);

        EXPECT_EQ(kDayOnePartTwoAnswer, result);
    }

    TEST(DayOneParser, benchmarkPuzzleOne) {
        const Input input = Parser::parseFile(Parser::kDayOneInputFilePath);

        ankerl::nanobench::Bench().run("Day 1 Puzzle 1", [&]() {
            ankerl::nanobench::doNotOptimizeAway(partOneSolution(input));
        });
    }

    TEST(DayOneParser, benchmarkPartTwo) {
        const Input input = Parser::parseFile(Parser::kDayOneInputFilePath);

        ankerl::nanobench::Bench().run("Day 1 Part 2", [&]() {
            ankerl::nanobench::doNotOptimizeAway(partTwoSolution(input));
        });
    }

} // AdventOfCode::DayOne
