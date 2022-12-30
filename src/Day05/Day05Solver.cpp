#include "../../include/Day05Solver.h"

string Day05Solver::executePuzzle1() {
    vector<list<char>> crates;
    int idx = 0;

    for (auto &i: input) {
        if (i[1] == '1') {
            break;
        }
        idx++;
        for (int j = 0; j < i.size(); j += 4) {
            if (crates.size() <= j / 4) {
                crates.emplace_back();
            }
            if (i[j] == ' ') {
                continue;
            }
            crates[int(j / 4)].push_back(i[j + 1]);
        }
    }

    for (int i = idx + 2; i < input.size(); i++) {
        vector<string> v = Utils::splitToString(input[i]);
        int amount = Converter::StringToInt(v[1]);
        int src = Converter::StringToInt(v[3]) - 1;
        int dest = Converter::StringToInt(v[5]) - 1;

        for (int j = 0; j < amount; j++) {
            crates[dest].push_front(crates[src].front());
            crates[src].pop_front();
        }
    }

    string ret;
    for (auto &crate: crates) {
        ret += crate.front();
    }

    return ret;
}

string Day05Solver::executePuzzle2() {
    vector<list<char>> crates;
    int idx = 0;

    for (auto &i: input) {
        if (i[1] == '1') {
            break;
        }
        idx++;
        for (int j = 0; j < i.size(); j += 4) {
            if (crates.size() <= j / 4) {
                crates.emplace_back();
            }
            if (i[j] == ' ') {
                continue;
            }
            crates[int(j / 4)].push_back(i[j + 1]);
        }
    }

    for (int i = idx + 2; i < input.size(); i++) {
        vector<string> v = Utils::splitToString(input[i]);
        int amount = Converter::StringToInt(v[1]);
        int src = Converter::StringToInt(v[3]) - 1;
        int dest = Converter::StringToInt(v[5]) - 1;

        stack<char> temp;

        for (int j = amount - 1; j >= 0; j--) {
            temp.push(crates[src].front());
            crates[src].pop_front();
        }

        while (!temp.empty()) {
            crates[dest].push_front(temp.top());
            temp.pop();
        }
    }

    string ret;
    for (auto &crate: crates) {
        ret += crate.front();
    }

    return ret;
}
