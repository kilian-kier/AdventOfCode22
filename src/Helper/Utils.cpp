#include "../../include/Utils.h"

vector<string> Utils::splitToString(const string &source, const string &delimiters) {
    unsigned long prev = 0;
    unsigned long currentPos;
    vector<string> results;

    while ((currentPos = source.find_first_of(delimiters, prev)) != string::npos) {
        if (currentPos > prev) {
            results.push_back(source.substr(prev, currentPos - prev));
        }
        prev = currentPos + 1;
    }
    if (prev < source.length()) {
        results.push_back(source.substr(prev));
    }
    return results;
}

vector<int> Utils::splitToInt(const string &source, const string &delimiters) {
    vector<string> v = splitToString(source, delimiters);
    vector<int> ret(v.size());
    for (int i = 0; i < v.size(); i++) {
        ret[i] = Converter::StringToInt(v[i]);
    }

    return ret;
}
