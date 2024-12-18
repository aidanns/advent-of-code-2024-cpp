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

    auto buildFrequencyMap(const std::vector<int> & values) -> std::unordered_map<int, int> {
        std::unordered_map<int, int> map{};

        for (const auto key : values) {
            if (map.contains(key)) {
                const auto newValue = map.at(key) + 1;
                map.insert_or_assign(key, newValue);
            } else {
                map.insert_or_assign(key, 1);
            }
        }

        return std::move(map);
    }

    auto puzzleTwoSolution(const Input &input) -> int {

        const auto firstMap = buildFrequencyMap(input.first);
        const auto secondMap = buildFrequencyMap(input.second);

        auto similarityScore = 0;

        for (const auto value : firstMap) {
            auto key = value.first;

            if (secondMap.contains(key)) {
                similarityScore += key * firstMap.at(key) * secondMap.at(key);
            }
        }

        return similarityScore;
    }

} // AdventOfCode