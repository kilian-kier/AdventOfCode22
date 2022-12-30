#include "../../include/Day09Solver.h"

string Day09Solver::executePuzzle1() {
    return to_string(ropeFunc(2));
}

string Day09Solver::executePuzzle2() {
    return to_string(ropeFunc(10));
}

bool inVisited(const vector<pair<int, int>> &visited, pair<int, int> field) {
    return any_of(visited.begin(), visited.end(), [&](pair<int, int> item) {
        return item.first == field.first && item.second == field.second;
    });
}

int Day09Solver::ropeFunc(int rope_length) {
    vector<pair<int, int>> pos(rope_length, pair(0, 0));
    vector<pair<int, int>> visited;

    for (const string &line: input) {
        vector<string> split = Utils::splitToString(line);
        char direction = split[0][0];
        int steps = Converter::StringToInt(split[1]);

        for (int j = 0; j < steps; j++) {
            switch (direction) {
                case 'U':
                    pos[0].first--;
                    break;
                case 'R':
                    pos[0].second++;
                    break;
                case 'D':
                    pos[0].first++;
                    break;
                case 'L':
                    pos[0].second--;
                    break;
                default:
                    break;
            }

            for (int k = 1; k < rope_length; k++) {
                int dr = pos[k - 1].first - pos[k].first;
                int dc = pos[k - 1].second - pos[k].second;
                if (max(abs(dr), abs(dc)) > 1) {
                    if (dr > 0) {
                        pos[k].first++;
                    } else if (dr < 0) {
                        pos[k].first--;
                    }

                    if (dc > 0) {
                        pos[k].second++;
                    } else if (dc < 0) {
                        pos[k].second--;
                    }
                }
            }

            if (!inVisited(visited, pos[rope_length - 1])) {
                visited.push_back(pos[rope_length - 1]);
            }
        }
    }

    return (int) visited.size();
}
