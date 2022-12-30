#include "../../include/Day03Solver.h"

int getPriority(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 27;
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    return -1;
}

string Day03Solver::executePuzzle1() {
    int half, total_sum = 0;
    for (auto &s : input) {
        unordered_map<int, int> m; // Hash Map
        half = (int)s.size() / 2;

        // inserts elements into the hash map for the first half and checks them for the second half
        for (int i = 0; i < half; i++) {
            int priority = getPriority(s[i]);
            m[priority] = 1;
        }
        for (int i = half; i < s.size(); i++) {
            int priority = getPriority(s[i]);
            if (m.find(priority) != m.end()) {
                total_sum += priority;
                break;
            }
        }
    }

    return to_string(total_sum);
}

string Day03Solver::executePuzzle2() {
    int total_sum = 0;
    for (int t = 0; t < input.size(); t += 3) {
        unordered_map<int, int> m;

        /* inserts <element, 1> into the hash map for the first rucksack,
        checks them for the second rucksack and changes value to 2 and
        checks the map for the value 2 for the third rucksack */
        for (char &i : input[t]) {
            int priority = getPriority(i);
            m[priority] = 1;
        }
        for (char &i : input[t + 1]) {
            int priority = getPriority(i);
            if (m.find(priority) != m.end()) {
                m[priority] = 2;
            }
        }
        for (char &i : input[t + 2]) {
            int priority = getPriority(i);
            if (m.find(priority) != m.end()) {
                if (m[priority] != 2)
                    continue;
                total_sum += priority;
                break;
            }
        }
    }

    return to_string(total_sum);
}
