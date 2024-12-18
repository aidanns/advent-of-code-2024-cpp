//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#ifndef ADVENT_OF_CODE_2024_CPP_DAY_TWO_H
#define ADVENT_OF_CODE_2024_CPP_DAY_TWO_H

#include "DayTwoParser.h"

namespace AdventOfCode::DayTwo {

    using Input = std::vector<Parser::Report>;

    /**
     * Generate solutions for both parts and print the output to stdout.
     */
    auto run() -> void;

    /**
     * Returns the output for part one.
     */
    auto partOneSolution(const Input &input) -> int;

    /**
     * Returns the answer for part two.
     */
    auto partTwoSolution(const Input &input) -> int;

} // AdventOfCode::DayTwo

#endif //ADVENT_OF_CODE_2024_CPP_DAY_TWO_H
