#include "../../include/Day20Solver.h"

void mix(vector<pair<long long, int>> &vec) {
    int n = (int) vec.size();
    for (int i = 0; i < n; ++i) {
        int idx = 0;
        auto it = vec.begin();
        for (; it != vec.end(); it++) {
            if (it->second == i) {
                break;
            }

            idx++;
        }

        long long value = it->first;
        int new_pos = (int) ((idx + value) % (n - 1));
        if (new_pos == 0) {
            new_pos = n - 1;
        } else if (new_pos < 0) {
            new_pos += n - 1;
        }

        if (new_pos > idx) {
            rotate(it, it + 1, vec.begin() + new_pos + 1);
        } else {
            rotate(vec.begin() + new_pos, it, it + 1);
        }
    }
}

long long findGrove(vector<pair<long long, int>> &vec) {
    int zero_idx = 0;

    for (auto pair : vec) {
        if (pair.first == 0) {
            break;
        }

        zero_idx++;
    }

    long long result = 0;
    for (int i = 1000; i <= 3000; i += 1000) {
        result += vec[(zero_idx + i) % vec.size()].first;
    }

    return result;
}

string Day20Solver::executePuzzle1() {
    int n = (int) input.size();
    vector<pair<long long, int>> vec;
    for (int i = 0; i < n; i++) {
        vec.emplace_back((long long) Converter::StringToInt(input[i]), i);
    }

    mix(vec);


    return to_string(findGrove(vec));
}

string Day20Solver::executePuzzle2() {
    int n = (int) input.size();
    int key = 811589153;
    vector<pair<long long, int>> vec;
    for (int i = 0; i < n; i++) {
        vec.emplace_back((long long) Converter::StringToInt(input[i]) * key, i);
    }

    for (int i = 0; i < 10; i++) {
        mix(vec);
    }

    return to_string(findGrove(vec));
}