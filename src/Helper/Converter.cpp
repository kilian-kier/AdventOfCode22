#include "../../include/Converter.h"

string Converter::ZeroPadString(const string& str, int length) {
    int p = length - min(length, (int)str.size());
    return string(p, '0').append(str);
}

int Converter::StringToInt(const string &str) {
    return stoi(str);
}

double Converter::StringToDouble(const string &str) {
    return stod(str);
}
