#ifndef ADVENTOFCODE2022_CONVERTER_H
#define ADVENTOFCODE2022_CONVERTER_H

#include <bits/stdc++.h>

using namespace std;

class Converter {
public:
    static string ZeroPadString(const string& str, int length);
    static int StringToInt(const string& str);
    static double StringToDouble(const string& str);
};


#endif //ADVENTOFCODE2022_CONVERTER_H
