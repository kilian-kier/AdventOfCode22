#ifndef ADVENTOFCODE2022_UTILS_H
#define ADVENTOFCODE2022_UTILS_H

#include <bits/stdc++.h>
#include "Converter.h"

using namespace std;

class Utils {
public:
    static vector<string> splitToString(const string& source, const string& delimiters = " ");
    static vector<int> splitToInt(const string& source, const string& delimiters = " ");
};


#endif //ADVENTOFCODE2022_UTILS_H
