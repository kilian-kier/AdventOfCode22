# AoC++

My solutions for [Advent Of Code 2022](https://adventofcode.com/) using the C++ Standard Library

## Why C++
Recently I've been using C++ primarily for competitive programming challenges. Mainly because this year I qualified for the [national Olympiad in Informatics](https://olimpiadi-informatica.it/index.php/news/item/210-olimpiadi-italiane-22.html) and only C++ was allowed there. Therefore I've trained many of these problems in C++. But for example the eval() function from Python would have been very helpful in parsing day 13... Despite this, I was able to work with it effectively but next year I'll probably switch to Python so I can focus on solving the problems and not on parsing.

## Usage
```shell
mkdir build && cd build
cmake ..
make
./AdventOfCode2022
```

## Directory Hierarchy
```
|—— .gitignore
|—— CMakeLists.txt
|—— README.md
|—— include
|    |—— Converter.h
|    |—— Day{$day}Solver.h
|    |—— InputHelper.h
|    |—— Solver.h
|    |—— Utils.h
|    |—— main.h
|—— src
|    |—— Day{$day}
|        |—— Day{$day}Solver.cpp
|        |—— example.txt
|        |—— input.txt
|        |—— output.txt
|    |—— Helper
|        |—— Converter.cpp
|        |—— InputHelper.cpp
|        |—— Solver.cpp
|        |—— Utils.cpp
|    |—— main.cpp
```