//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#include "DayOne.h"

#include <iostream>
#include <unordered_map>

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

        std::unordered_map<int, int> firstMap{};
        std::unordered_map<int, int> secondMap{};

        for (const auto key : input.first) {
            if (firstMap.contains(key)) {
                auto newValue = firstMap.at(key) + 1;
                firstMap.insert_or_assign(key, newValue);
            } else {
                firstMap.insert_or_assign(key, 1);
            }
        }

        for (const auto key : input.second) {
            if (secondMap.contains(key)) {
                auto newValue = secondMap.at(key) + 1;
                secondMap.insert_or_assign(key, newValue);
            } else {
                secondMap.insert_or_assign(key, 1);
            }
        }

        int similarityScore = 0;

        for (const auto value : firstMap) {
            auto key = value.first;

            if (secondMap.contains(key)) {
                similarityScore += key * firstMap.at(key) * secondMap.at(key);
            }
        }

        return similarityScore;
    }

} // AdventOfCode