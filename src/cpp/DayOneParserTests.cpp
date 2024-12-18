//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "DayOneParser.h"

namespace AdventOfCode::DayOne::Parser {

    constexpr size_t kDayOneInputNumberOfRows = 1000;
    constexpr int kDayOneInputFirstRowFirstElement = 19394;
    constexpr int kDayOneInputFirstRowSecondElement = 30201;
    constexpr int kDayOneInputLastRowFirstElement = 53640;
    constexpr int kDayOneInputLastRowSecondElement = 45703;

    TEST(DayOneParser, parses) {
        auto dayOneData = parseFile(kDayOneInputFilePath);

        EXPECT_EQ(kDayOneInputNumberOfRows, dayOneData.first.size());
        EXPECT_EQ(kDayOneInputFirstRowFirstElement, dayOneData.first.at(0));
        EXPECT_EQ(kDayOneInputFirstRowSecondElement, dayOneData.second.at(0));
        EXPECT_EQ(kDayOneInputLastRowFirstElement, dayOneData.first.at(999));
        EXPECT_EQ(kDayOneInputLastRowSecondElement, dayOneData.second.at(999));
    }

    TEST(DayOneParser, benchmarkParseComplete) {
        ankerl::nanobench::Bench().run("Day 1 Parse - Batch", [&]() {
            ankerl::nanobench::doNotOptimizeAway(Parser::parseFile(Parser::kDayOneInputFilePath));
        });
    }

    TEST(DayOneParser, benchmarkParseWithCallback) {
        ankerl::nanobench::Bench().run("Day 1 Parse - Callback", [&]() {
            std::vector<int> firstList;
            std::vector<int> secondList;
            Parser::parseFile(Parser::kDayOneInputFilePath,[&](auto first, auto second) {
                firstList.push_back(first);
                secondList.push_back(second);
            });
            ankerl::nanobench::doNotOptimizeAway(firstList);
            ankerl::nanobench::doNotOptimizeAway(secondList);
        });
    }
} // AdventOfCode::DayOne::Parser