cmake_minimum_required(VERSION 3.24)
project(AdventOfCode2022)

set(CMAKE_CXX_STANDARD 17)

add_executable(AdventOfCode2022 src/main.cpp include/main.h
        src/Helper/InputHelper.cpp include/InputHelper.h
        src/Helper/Solver.cpp include/Solver.h
        src/Helper/Converter.cpp include/Converter.h src/Helper/Utils.cpp include/Utils.h
        src/Day01/Day01Solver.cpp include/Day01Solver.h
        src/Day02/Day02Solver.cpp include/Day02Solver.h
        src/Day03/Day03Solver.cpp include/Day03Solver.h
        src/Day04/Day04Solver.cpp include/Day04Solver.h
        src/Day05/Day05Solver.cpp include/Day05Solver.h
        src/Day06/Day06Solver.cpp include/Day06Solver.h
        src/Day07/Day07Solver.cpp include/Day07Solver.h
        src/Day08/Day08Solver.cpp include/Day08Solver.h
        src/Day09/Day09Solver.cpp include/Day09Solver.h
        src/Day10/Day10Solver.cpp include/Day10Solver.h
        src/Day11/Day11Solver.cpp include/Day11Solver.h
        src/Day12/Day12Solver.cpp include/Day12Solver.h
        src/Day13/Day13Solver.cpp include/Day13Solver.h
        src/Day14/Day14Solver.cpp include/Day14Solver.h
        src/Day15/Day15Solver.cpp include/Day15Solver.h
        src/Day16/Day16Solver.cpp include/Day16Solver.h
        src/Day17/Day17Solver.cpp include/Day17Solver.h
        src/Day18/Day18Solver.cpp include/Day18Solver.h
        src/Day19/Day19Solver.cpp include/Day19Solver.h
        src/Day20/Day20Solver.cpp include/Day20Solver.h)
