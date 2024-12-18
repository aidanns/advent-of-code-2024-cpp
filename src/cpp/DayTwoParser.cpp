//
// Created by Aidan Nagorcka-Smith on 18/12/2024.
//

#include "DayTwoParser.h"

#include "InputFileReader.h"

namespace AdventOfCode::DayTwo::Parser {

    auto parseFile(const std::filesystem::path &inputFilePath) -> std::vector<Report> {
        std::vector<Report> reports{};
        parseFile(inputFilePath, [&](auto report) {
            reports.push_back(report);
        });
        return reports;
    }

    auto parseFile(const std::filesystem::path &inputFilePath,
                   const HandleReportCallbackFunction &&handleReportCallback) -> void {
        InputFileReader::readLines(inputFilePath, [&](auto &&line) -> void {
            Report report{};

            std::string remaining_string = line;
            std::string::size_type numCharsProcessed = 1;

            while (!remaining_string.empty() && numCharsProcessed != 0) {
                report.push_back(std::stoi(remaining_string, &numCharsProcessed));
                remaining_string = remaining_string.substr(std::min(numCharsProcessed + 1,
                                                               remaining_string.size()));
            }

            handleReportCallback(std::move(report));
        });
    }

} // AdventOfCode::DayTwo::Parser
