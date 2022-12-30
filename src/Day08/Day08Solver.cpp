#include "../../include/Day08Solver.h"

string Day08Solver::executePuzzle1() {
    int height = (int) input.size();
    int width = (int) input[0].length();

    vector<vector<bool>> visible(input.size(), vector<bool>(input[0].length(), false));

    for (int c = 0; c < width; c++) {
        visible[0][c] = true;
        visible[height - 1][c] = true;
    }

    for (int r = 0; r < height; r++) {
        visible[r][0] = true;
        visible[r][width - 1] = true;
    }

    for (int row = 0; row < input.size(); row++) {
        int max_yet_right = input[row][0] - '0';
        int max_yet_left = input[row][width - 1] - '0';
        for (int col = 0; col < input[0].size() - 1; col++) {
            if (max_yet_right < input[row][col + 1] - '0') {
                visible[row][col + 1] = true;
                max_yet_right = input[row][col + 1] - '0';
            }
            if (max_yet_left < input[row][width - col - 2] - '0') {
                visible[row][width - col - 2] = true;
                max_yet_left = input[row][width - col - 2] - '0';
            }
        }
    }

    for (int col = 0; col < input[0].size(); col++) {
        int max_yet_down = input[0][col] - '0';
        int max_yet_up = input[height - 1][col] - '0';
        for (int row = 0; row < input.size() - 1; row++) {
            if (max_yet_down < input[row + 1][col] - '0') {
                visible[row + 1][col] = true;
                max_yet_down = input[row + 1][col] - '0';
            }
            if (max_yet_up < input[height - row - 2][col] - '0') {
                visible[height - row - 2][col] = true;
                max_yet_up = input[height - row - 2][col] - '0';
            }
        }
    }

    int total_sum = 0;

    for (int row = 0; row < input.size(); row++) {
        for (int col = 0; col < input[0].length(); col++) {
            if (visible[row][col])
                total_sum++;
        }
    }

    return to_string(total_sum);
}

int countTrees(vector<string> input, int r, int c) {
    int top, bottom, left, right;
    top = bottom = left = right = 0;
    int cell = input[r][c] - '0';

    for (int i = r - 1; i >= 0; i--) {
        if (input[i][c] - '0' >= cell) {
            top++;
            break;
        }
        top++;
    }

    for (int i = r + 1; i < input.size(); i++) {
        if (input[i][c] - '0' >= cell) {
            bottom++;
            break;
        }
        bottom++;
    }

    for (int i = c - 1; i >= 0; i--) {
        if (input[r][i] - '0' >= cell) {
            left++;
            break;
        }
        left++;
    }

    for (int i = c + 1; i < input[0].length(); i++) {
        if (input[r][i] - '0' >= cell) {
            right++;
            break;
        }
        right++;
    }

    return top * bottom * left * right;
}

string Day08Solver::executePuzzle2() {
    int max_score = 0;
    for (int r = 0; r < input.size(); r++) {
        for (int c = 0; c < input[0].length(); c++) {
            int score = countTrees(input, r, c);
            max_score = max(max_score, score);
        }
    }

    return to_string(max_score);
}
