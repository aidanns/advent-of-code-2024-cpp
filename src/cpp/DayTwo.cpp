//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#include "DayTwo.h"

#include <iostream>

namespace AdventOfCode::DayTwo {

    auto run() -> void {
        const auto input = Parser::parseFile(Parser::kDayTwoInputFilePath);
        std::cout << "Day Two:" << std::endl;
        std::cout << partOneSolution(input) << std::endl;
        std::cout << partTwoSolution(input) << std::endl;
    }

    auto partOneSolution(const Input &input) -> int {
        return 0;
    }

    auto partTwoSolution(const Input &input) -> int {
        return 0;
    }

} // AdventOfCode::DayTwo
