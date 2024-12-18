//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#include "DayOneParser.h"

#include <string>

#include "InputFileReader.h"

namespace AdventOfCode::DayOne::Parser {

    auto parseFile(const std::filesystem::path &inputFilePath) -> std::pair<std::vector<int>,
            std::vector<int>> {
        std::vector<int> firstList{};
        std::vector<int> secondList{};
        parseFile(inputFilePath, [&](auto first, auto second) {
            firstList.push_back(std::forward<int>(first));
            secondList.push_back(std::forward<int>(second));
        });
        return {firstList, secondList};
    }

    auto parseFile(const std::filesystem::path &inputFilePath,
                   const HandleEntryCallbackFunction &&handleEntryCallbackFunction) -> void {
        InputFileReader::readLines(inputFilePath, [&](auto &&line) -> void {
            int first = std::stoi(line);
            int second = std::stoi(line.substr(8));
            handleEntryCallbackFunction(first, second);
        });
    }

} // AdventOfCode::DayOne::Parser
