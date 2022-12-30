#include "../../include/Day01Solver.h"

vector<int> max_calories(3, 0);

void isMax(int sum) {
    if (sum > max_calories[0]) {
        max_calories[2] = max_calories[1];
        max_calories[1] = max_calories[0];
        max_calories[0] = sum;
    } else if (sum > max_calories[1]) {
        max_calories[2] = max_calories[1];
        max_calories[1] = sum;
    } else if (sum > max_calories[2]) {
        max_calories[2] = sum;
    }
}

string Day01Solver::executePuzzle1() {
    int sum = 0;
    for (auto & s : input) {
        if (s.empty()) {
            isMax(sum);
            sum = 0;
            continue;
        }
        sum += Converter::StringToInt(s);
    }

    isMax(sum);

    return to_string(max_calories[0]);
}

string Day01Solver::executePuzzle2() {
    return to_string(max_calories[0] + max_calories[1] + max_calories[2]);
}
