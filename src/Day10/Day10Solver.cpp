#include "../../include/Day10Solver.h"

void addToTotalStrength(int *total_strength, int x_register, int cycle) {
    if ((cycle-20) % 40 != 0)
        return;
    *total_strength = *total_strength + (x_register * cycle);
}

string Day10Solver::executePuzzle1() {
    int x_reg = 1;
    int cycle = 1;
    int total_strength = 0;

    for (const auto & i : input) {
        vector<string> split = Utils::splitToString(i, " ");
        cycle++;
        addToTotalStrength(&total_strength, x_reg, cycle);
        if (split[0] == "noop")
            continue;
        cycle++;
        x_reg += Converter::StringToInt(split[1]);
        addToTotalStrength(&total_strength, x_reg, cycle);
    }

    return to_string(total_strength);
}

string Day10Solver::executePuzzle2() {
    // I used ' ' and '#' for a better readability
    char screen[6][41];
    memset(screen, ' ', 6 * 41);
    int x_reg = 1;
    int cycle = 0;
    int x = 0, y = 0;
    bool is_noop;

    for (const auto & i : input) {
        vector<string> split = Utils::splitToString(i, " ");
        is_noop = false;
        if (split[0] == "noop") {
            is_noop = true;
        }

        int iterations = is_noop ? 1 : 2;

        for (int j = 0; j < iterations; j++) {
            x = cycle % 40;
            if (x >= x_reg - 1 && x <= x_reg + 1) {
                screen[y][x] = '#';
            }
            if (x + 1 == 40) {
                screen[y][40] = '\0';
                y++;
            }
            cycle++;
        }

        if (!is_noop) {
            x_reg += Converter::StringToInt(split[1]);
        }
    }

    stringstream ss;
    for (auto &row : screen) {
        ss << endl << "\t" << row;
    }

    return ss.str();
}