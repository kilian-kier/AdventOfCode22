#include "../../include/Day14Solver.h"

int SGM(int x) {
    if (x < 0) {
        return -1;
    } else if (x > 0) {
        return 1;
    } else {
        return 0;
    }
}

pair<int, int> nextMoves(pair<int, int> sand, const set<pair<int, int>> &rocks, bool is_floor = false, int floor = 0) {
    if (is_floor && sand.second + 1 >= floor) {
        return {INT_MIN, INT_MAX};
    } else if (rocks.find({sand.first, sand.second + 1}) == rocks.end()) {
        return {sand.first, sand.second + 1};
    } else if (rocks.find({sand.first - 1, sand.second + 1}) == rocks.end()) {
        return {sand.first - 1, sand.second + 1};
    } else if (rocks.find({sand.first + 1, sand.second + 1}) == rocks.end()) {
        return {sand.first + 1, sand.second + 1};
    }

    return {INT_MIN, INT_MAX};
}

set<pair<int, int>> rocks;
int bottom;

string Day14Solver::executePuzzle1() {
    rocks = set<pair<int, int>>();
    regex re(R"((\d+),(\d+))");
    smatch m;
    for (string &line: input) {
        regex_search(line, m, re);

        int x = Converter::StringToInt(m.str(1));
        int y = Converter::StringToInt(m.str(2));
        rocks.insert(pair(x, y));

        line = m.suffix().str();
        while (regex_search(line, m, re)) {
            int next_x = Converter::StringToInt(m.str(1));
            int next_y = Converter::StringToInt(m.str(2));

            int dx = SGM(next_x - x);
            int dy = SGM(next_y - y);

            while (x != next_x || y != next_y) {
                x += dx;
                y += dy;

                rocks.insert(pair(x, y));
            }
            line = m.suffix().str();
        }
    }

    auto temp_rocks = rocks;

    bottom = 0;
    for (auto rock : temp_rocks) {
        bottom = max(bottom, rock.second);
    }

    int num_sand = 0;
    while (true) {
        pair<int, int> sand(500, 0);

        pair<int, int> next = nextMoves(sand, temp_rocks);

        while (next.first != INT_MIN && next.first != INT_MAX) {
            sand = next;
            next = nextMoves(sand, temp_rocks);
            if (sand.second >= bottom) {
                return to_string(num_sand);
            }
        }

        temp_rocks.insert(sand);
        num_sand++;
    }
}

string Day14Solver::executePuzzle2() {
    int num_sand = 0;
    while (true) {
        pair<int, int> sand(500, 0);

        pair<int, int> next = nextMoves(sand, rocks, true, bottom + 1);
        num_sand++;

        while (next.first != INT_MIN && next.first != INT_MAX) {
            sand = next;
            next = nextMoves(sand, rocks, true, bottom + 2);
        }

        rocks.insert(sand);
        if (sand.first == 500 && sand.second == 0) {
            return to_string(num_sand);
        }
    }
}