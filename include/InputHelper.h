#ifndef ADVENTOFCODE2022_INPUTHELPER_H
#define ADVENTOFCODE2022_INPUTHELPER_H

#include <bits/stdc++.h>
#include "Converter.h"

#if defined(WIN32) || defined(_WIN32)
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif

using namespace std;

class InputHelper {
private:
    static string GetInputFilePath(int day);
    static string GetExampleInputFilePath(int day);
    static string GetOutputFilePath(int day);
    static string GetDayDirPath(int day);
public:
    static vector<string> GetInput(int day);
    static vector<string> GetExampleInput(int day);
    static void WriteOutput(int day, const string& example1, const string& example2, const string& part1, const string& part2);
};


#endif //ADVENTOFCODE2022_INPUTHELPER_H
