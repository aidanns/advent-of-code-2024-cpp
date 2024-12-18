//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "DayTwoParser.h"

namespace AdventOfCode::DayTwo::Parser {

    constexpr size_t kExpectedDayOneInputNumberOfRows = 1000;
    const Report kExpectedDayOneInputFirstRowReport{2, 5, 6, 8, 6};
    const Report kExpectedDayOneInputLastRowReport{26, 28, 29, 31, 32, 34};

    auto expectReportEqual(const Report & expected, const Report & observed) -> void {
        for (auto i = 0; i < expected.size(); ++i) {
            EXPECT_EQ(expected[i], observed[i]);
        }
    }

    TEST(DayTwoParser, parses) {
        auto dayTwoData = parseFile(kDayTwoInputFilePath);

        EXPECT_EQ(kExpectedDayOneInputNumberOfRows, dayTwoData.size());
        expectReportEqual(kExpectedDayOneInputFirstRowReport, dayTwoData.at(0));
        expectReportEqual(kExpectedDayOneInputLastRowReport, dayTwoData.at(999));
    }

    TEST(DayTwoParser, benchmarkParseComplete) {
        ankerl::nanobench::Bench().run("Day 2 Parse - Batch", [&]() {
            ankerl::nanobench::doNotOptimizeAway(Parser::parseFile(Parser::kDayTwoInputFilePath));
        });
    }

    TEST(DayTwoParser, benchmarkParseWithCallback) {
        ankerl::nanobench::Bench().run("Day 2 Parse - Callback", [&]() {
            std::vector<Report> reports{};
            Parser::parseFile(Parser::kDayTwoInputFilePath, [&](auto report) {
                reports.push_back(report);
            });
            ankerl::nanobench::doNotOptimizeAway(reports);
        });
    }

} // AdventOfCode::DayTwo::Parser