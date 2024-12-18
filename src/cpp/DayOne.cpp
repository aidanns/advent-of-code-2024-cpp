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
        std::vector<int> firstList{input.first};
        std::make_heap(firstList.begin(), firstList.end());

        std::vector<int> secondList{input.second};
        std::make_heap(secondList.begin(), secondList.end());

        auto sumOfDifferences = 0;

        while (!firstList.empty() && !secondList.empty()) {
            auto firstElement = firstList.front();
            std::pop_heap(firstList.begin(), firstList.end());
            firstList.pop_back();

            auto secondElement = secondList.front();
            std::pop_heap(secondList.begin(), secondList.end());
            secondList.pop_back();

            sumOfDifferences += abs(firstElement - secondElement);
        }

        return sumOfDifferences;
    }

    auto puzzleTwoSolution(const Input &input) -> int {
        return 0;
    }

} // AdventOfCode