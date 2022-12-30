#include "../../include/Day15Solver.h"

class Signal {
public:
    pair<int, int> sensor;
    int distance;
    int min_on_row;
    int max_on_row;

    Signal(int sx, int sy, int bx, int by, int row) {
        sensor = pair(sx, sy);
        distance = abs(sx - bx) + abs(sy - by);

        int distance_to_row = abs(row - sy);
        if (distance_to_row <= distance) {
            min_on_row = sx - (distance - distance_to_row);
            max_on_row = sx + (distance - distance_to_row);
        }
    }
};

bool valid(int x, int y, const list<Signal> &signals) {
    for (Signal s: signals) {
        int dxy = abs(x - s.sensor.first) + abs(y - s.sensor.second);
        if (dxy <= s.distance) {
            return false;
        }
    }
    return true;
}

list<Signal> signals;

string Day15Solver::executePuzzle1() {
    // for examples
    static int row = 0;
    if (row == 0) {
        row = 10;
    } else {
        row = 2'000'000;
    }


    signals = list<Signal>();
    int min_c = INT_MAX, max_c = INT_MIN;
    set<pair<int, int>> beacons_on_row;
    for (string &line: input) {
        vector<string> split = Utils::splitToString(line, " ");
        int sx = Converter::StringToInt(split[2].substr(2));
        int sy = Converter::StringToInt(split[3].substr(2));
        int bx = Converter::StringToInt(split[8].substr(2));
        int by = Converter::StringToInt(split[9].substr(2));
        auto s = Signal(sx, sy, bx, by, row);
        signals.push_back(s);
        min_c = min(min_c, s.min_on_row);
        max_c = max(max_c, s.max_on_row);
        if (by == row) {
            if (beacons_on_row.find({bx, by}) == beacons_on_row.end())
                beacons_on_row.insert({bx, by});
        }
    }


    int positions = 0;
    for (int x = min_c; x <= max_c; x++) {
        if (!valid(x, row, signals)) {
            positions++;
        }
    }
    return to_string(positions - beacons_on_row.size());
}

pair<int, int> range(Signal &signal, int row) {
    int dy = abs(signal.sensor.second - row);

    if (dy > signal.distance) {
        return {0, 0};
    } else {
        return {signal.sensor.first - signal.distance + dy, signal.sensor.first + signal.distance - dy + 1};
    }
}

string Day15Solver::executePuzzle2() {
    static int search_range = 0;
    if (search_range == 0) {
        search_range = 20;
    } else {
        search_range = 4'000'000;
    }


    for (int r = 0; r <= search_range; r++) {
        set<pair<int, int>> ranges;
        set<int> possibles;

        for (Signal s: signals) {
            pair<int, int> row_range = range(s, r);
            ranges.insert(row_range);

            if (row_range.first > 0) {
                possibles.insert(row_range.first - 1);
            }
            if (row_range.second < search_range) {
                possibles.insert(row_range.second + 1);
            }
        }

        for (int p : possibles) {
            bool found = true;
            for (pair<int, int> range : ranges) {
                if (p >= range.first && p < range.second) {
                    found = false;
                }
            }

            if (found) {
                unsigned long long result = (unsigned long long)p * 4'000'000;
                return to_string( result + r);
            }
        }
    }

    return "There is no distress beacon...";
}