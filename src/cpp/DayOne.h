//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#ifndef ADVENT_OF_CODE_2024_CPP_DAY_ONE_H
#define ADVENT_OF_CODE_2024_CPP_DAY_ONE_H

#include <vector>
#include <algorithm>

namespace AdventOfCode::DayOne {

    using Input = std::pair<std::vector<int>, std::vector<int>>;

    /**
     * Generate solutions for both puzzles and print the output to stdout.
     */
    auto run() -> void;

    /**
     * Returns the output for day one puzzle one.
     */
    auto partOneSolution(const Input &input) -> int;

    /**
     * Returns the answer for day one puzzle two.
     */
    auto partTwoSolution(const Input &input) -> int;

} // AdventOfCode::DayOne

#endif //ADVENT_OF_CODE_2024_CPP_DAY_ONE_H
