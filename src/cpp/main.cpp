#include <iostream>

#include "generated/AdventOfCodeConfig.h"
#include "DayOne.h"
#include "DayTwo.h"

int main() {
    std::cout << "Advent of Code 2024" << std::endl;
    std::cout << "Version: " << ADVENT_OF_CODE_VERSION_MAJOR << "." << ADVENT_OF_CODE_VERSION_MINOR
          << "." << ADVENT_OF_CODE_VERSION_PATCH << std::endl;
    std::cout << std::endl;

    AdventOfCode::DayOne::run();
    std::cout << std::endl;
    AdventOfCode::DayTwo::run();

    return 0;
}
