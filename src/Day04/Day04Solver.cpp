#include "../../include/Day04Solver.h"

string Day04Solver::executePuzzle1() {
    int sum = 0;
    for (const auto& line : input) {
        auto v = Utils::splitToInt(line, "-,");

        if ((v[0] <= v[2] && v[1] >= v[3]) || (v[2] <= v[0] && v[3] >= v[1]))
            sum++;
    }

    return to_string(sum);
}

string Day04Solver::executePuzzle2() {
    int sum = 0;
    for (const auto& line : input) {
        auto v = Utils::splitToInt(line, "-,");

        if (v[1] < v[2] || v[3] < v[0])
            continue;
        sum++;
    }

    return to_string(sum);
}
