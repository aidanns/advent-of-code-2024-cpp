//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#include "DayTwo.h"

#include <iostream>
#include <span>

#include "DayTwoParser.h"

namespace AdventOfCode::DayTwo {

    auto run() -> void {
        const auto input = Parser::parseFile(Parser::kDayTwoInputFilePath);
        std::cout << "Day Two:" << std::endl;
        std::cout << partOneSolution(input) << std::endl;
        std::cout << partTwoSolution(input) << std::endl;
    }

    auto isSafeIncreasing(const Parser::Report &report) -> bool {
        if (report.size() <= 1) {
            return true;
        }

        auto previous = report.at(0);

        for (auto it = report.begin() + 1; it != report.end(); ++it) {
            if (*it <= previous || *it > previous + 3) {
                return false;
            }
            previous = *it;
        }
        return true;
    }

    auto isSafeDecreasing(const Parser::Report & report) -> bool {
        if (report.size() <= 1) {
            return true;
        }

        auto previous = report.at(0);

        for (auto it = report.begin() + 1; it != report.end(); ++it) {
            if (*it >= previous || *it < previous - 3) {
                return false;
            }
            previous = *it;
        }
        return true;
    }

    auto partOneSolution(const Input &input) -> int {
        auto safeReports = 0;
        for (const auto & report : input) {
            if (isSafeDecreasing(report) || isSafeIncreasing(report)) {
                safeReports++;
            }
        }
        return safeReports;
    }

    auto partTwoSolution(const Input &input) -> int {
        return 0;
    }

} // AdventOfCode::DayTwo
