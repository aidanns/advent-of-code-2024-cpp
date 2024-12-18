//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#ifndef ADVENT_OF_CODE_2024_CPP_DAY_TWO_PARSER_H
#define ADVENT_OF_CODE_2024_CPP_DAY_TWO_PARSER_H

#include <functional>
#include <filesystem>

namespace AdventOfCode::DayTwo::Parser {

    using Report = std::vector<int>;
    using HandleReportCallbackFunction = std::function<void(Report)>;

    const auto kDayTwoInputFilePath = "../src/data/input_day_two.txt";

    /**
     * Parse the complete file.
     *
     * @param inputFilePath path to read from
     * @return list of reports parsed from the file
     */
    auto parseFile(const std::filesystem::path &inputFilePath) -> std::vector<Report>;

    /**
     * Parse the file one Report at a time, providing each one to a specified handler.
     *
     * @param inputFilePath path to read from
     * @param handleReportCallback callback to process each parsed pair of values
     */
    auto parseFile(const std::filesystem::path &inputFilePath,
                   const HandleReportCallbackFunction &&handleReportCallback) -> void;


} // AdventOfCode::DayTwo::Parser

#endif //ADVENT_OF_CODE_2024_CPP_DAY_TWO_PARSER_H
