//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#ifndef DAY_ONE_PARSER_H
#define DAY_ONE_PARSER_H

#include <filesystem>
#include <functional>
#include <vector>
#include <fstream>
#include <utility>

namespace AdventOfCode::DayOne::Parser {

    using HandleEntryCallbackFunction = std::function<void(int, int)>;

    const auto kDayOneInputFilePath = "../src/data/input_day_one.txt";

    /**
     * Parse the complete file.
     *
     * @param inputFilePath path to read from
     * @return two lists parsed from the file
     */
    auto parseFile(const std::filesystem::path &inputFilePath) -> std::pair<std::vector<int>,
            std::vector<int>>;

    /**
     * Parse the file one pair of values at a time, providing each one to a specified handler.
     *
     * @param inputFilePath path to read from
     * @param handleEntryCallback callback to process each parsed pair of values
     */
    auto parseFile(const std::filesystem::path &inputFilePath,
                   const HandleEntryCallbackFunction &&handleEntryCallback) -> void;

} // AdventOfCode::DayOne::Parser

#endif //DAY_ONE_PARSER_H
