#include "../../include/Day06Solver.h"

int occurrencesInSubstring(const string& s, char c) {
    int count = 0;
    unsigned long idx = s.find(c, 0);
    while (idx != string::npos) {
        count++;
        idx = s.find(c, idx + 1);
    }

    return count;
}

int Day06Solver::firstDuplicate(int length) {
    bool found;
    for (int i = 0; i < input.size() - length; i++) {
        found = false;
        string sub = input[0].substr(i, length);
        for (int j = 0; j < length; j++) {
            if (occurrencesInSubstring(sub, sub[j]) > 1) {
                found = true;
                break;
            }
        }

        if (!found) {
            return i + length;
        }
    }

    return -1;
}

string Day06Solver::executePuzzle1() {
    return to_string(firstDuplicate(4));
}

string Day06Solver::executePuzzle2() {
    return to_string(firstDuplicate(14));
}
