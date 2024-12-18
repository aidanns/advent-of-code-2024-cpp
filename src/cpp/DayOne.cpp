//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#include "DayOne.h"

#include <iostream>

#include "DayOneParser.h"

namespace AdventOfCode::DayOne {

    auto run() -> void {
        const Input input = Parser::parseFile(Parser::kDayOneInputFilePath);
        std::cout << "Day One:" << std::endl;
        std::cout << puzzleOneSolution(input) << std::endl;
        std::cout << puzzleTwoSolution(input) << std::endl;
    }

    auto puzzleOneSolution(const Input &input) -> int {
        return 0;
    }

    auto puzzleTwoSolution(const Input &input) -> int {
        return 0;
    }

} // AdventOfCode