#include "../../include/Day02Solver.h"

/*
 * Rock/lose 0: A, X
 * Paper/draw 1: B, Y
 * Scissors/win 2: C, Z
 */
int getChoice(char choice) {
    if (choice == 'A' || choice == 'X') {
        return 0;
    } else if (choice == 'B' || choice == 'Y') {
        return 1;
    } else if (choice == 'C' || choice == 'Z') {
        return 2;
    }
    return -1;
}

void changeResult(int *result) {
    if (*result == 0) {
        *result = 1;
    } else if (*result == 1) {
        *result = 0;
    } else if (*result == 2) {
        *result = 2;
    }
}

string Day02Solver::executePuzzle1() {
    int opponent_choice, my_choice, result, total_sum = 0;
    for (auto & i : input) {
        opponent_choice = getChoice(i[0]);
        my_choice = getChoice(i[2]);

        // 0 = draw, 1 = win, 2 = lose
        // using modular arithmetic to prevent the quick and dirty if-else stuff
        result = (my_choice - opponent_choice + 3) % 3;

        total_sum += my_choice + 1;
        if (result == 1)
            total_sum += 6;
        else if (result == 0)
            total_sum += 3;
    }

    return to_string(total_sum);
}

string Day02Solver::executePuzzle2() {
    int opponent_choice, my_choice, result, total_sum = 0;
    for (auto & i : input) {
        opponent_choice = getChoice(i[0]);

        // 0 = lose, 1 = draw, 2 = win
        result = getChoice(i[2]);

        // after change: 0 = draw, 1 = lose, 2 = win
        changeResult(&result);
        my_choice = (opponent_choice - result + 3) % 3;

        total_sum += my_choice + 1;

        if (result == 2)
            total_sum += 6;
        else if (result == 0)
            total_sum += 3;
    }

    return to_string(total_sum);
}