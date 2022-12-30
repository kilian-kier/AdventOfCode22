#include "../../include/Day17Solver.h"

// used "ull" instead of "unsigned long long" to save some space
typedef unsigned long long ull;

class PointDay17 {
public:
    ull row;
    int col;

    PointDay17(ull row, int col) {
        this->row = row;
        this->col = col;
    }
};

class Rock {
public:
    vector<PointDay17> points;

    void moveToStart(ull highest) {
        for (PointDay17 &p: points) {
            p.row += highest + 3;
        }
    }

    void simulate() {
        for (PointDay17 &p: points) {
            p.row--;
        }
    }
};

class Chamber {
public:
    vector<vector<char>> chamber;

    bool intersection(Rock &rock) {
        for (PointDay17 &p: rock.points) {
            if (p.row < chamber.size() && chamber[p.row][p.col] == '#') {
                return true;
            }
        }

        return false;
    }

    void addRock(Rock &rock) {
        for (PointDay17 &p: rock.points) {
            while (chamber.size() <= p.row) {
                chamber.emplace_back(7, '.');
            }
        }

        for (PointDay17 &p: rock.points) {
            chamber[p.row][p.col] = '#';
        }
    }

    void jetPush(char jet, Rock &rock) {
        const auto previous = rock;
        if (jet == '<') {
            for (PointDay17 &p: rock.points) {
                p.col--;
                if (p.col < 0) {
                    rock = previous;
                    return;
                }
            }
        } else {
            for (PointDay17 &p: rock.points) {
                p.col++;
                if (p.col > 6) {
                    rock = previous;
                    return;
                }
            }
        }
        if (intersection(rock)) {
            rock = previous;
        }
    }

    // helpful for debugging
    void print() {
        cout << chamber.size() << '\n';
        for (ull i = chamber.size() - 1; i > 0; i--) {
            cout << "|";
            for (const auto &ele: chamber[i]) {
                cout << ele;
            }
            cout << "|" << '\n';
        }
        cout << "+";
        for (int i = 0; i < chamber[0].size() + 2; i++) {
            cout << '-';
        }
        cout << "+" << '\n';
    }
};

class HashClass {
public:
    vector<vector<char>> top_five;
    int input_idx;
    int rock_type;
    ull highest;

    HashClass(const vector<vector<char>> &top_five, const int i_input, const int rock_type,
              const ull highest) {
        this->top_five = top_five;
        this->input_idx = i_input;
        this->rock_type = rock_type;
        this->highest = highest;
    }

    bool operator==(const HashClass &hc) const {
        return hc.input_idx == input_idx && hc.rock_type == rock_type && hc.top_five == top_five;
    }
};

// used some random hash function
namespace std {
    template<>
    struct hash<HashClass> {
        ull operator()(const HashClass &hc) const {
            ull ans = 1;
            for (const vector<char> &row: hc.top_five) {
                for (char c: row) {
                    ans ^= c + 0x9e3779b9 + (ans << 6) + (ans >> 2);
                }
            }
            ans ^= hc.input_idx + 0x9e3779b9 + (ans << 6) + (ans >> 2);
            ans ^= hc.rock_type + 0x9e3779b9 + (ans << 6) + (ans >> 2);
            return ans;
        }
    };
}

string Day17Solver::executePuzzle1() {
    vector<Rock> rocks(5);
    rocks[0].points = {PointDay17(0, 0), PointDay17(0, 1), PointDay17(0, 2), PointDay17(0, 3)};
    rocks[1].points = {PointDay17(0, 1), PointDay17(1, 0), PointDay17(1, 1), PointDay17(1, 2), PointDay17(2, 1)};
    rocks[2].points = {PointDay17(2, 2), PointDay17(1, 2), PointDay17(0, 0), PointDay17(0, 1), PointDay17(0, 2)};
    rocks[3].points = {PointDay17(0, 0), PointDay17(1, 0), PointDay17(2, 0), PointDay17(3, 0)};
    rocks[4].points = {PointDay17(0, 0), PointDay17(0, 1), PointDay17(1, 0), PointDay17(1, 1)};

    for (Rock &rock: rocks) {
        for (PointDay17 &p: rock.points) {
            p.col += 2;
        }
    }

    ull highest = 1;
    Chamber chamber;
    chamber.chamber.emplace_back(7, '#');

    ull i = 0;
    int i_input = 0;
    while (i < 2022) {
        auto rock = rocks[i % 5];
        i++;
        rock.moveToStart(highest);
        Rock previous = rock;

        while (!chamber.intersection(rock)) {
            chamber.jetPush(input[0][i_input], rock);
            i_input++;
            if (i_input == input[0].length()) {
                i_input = 0;
            }
            previous = rock;
            rock.simulate();
        }
        chamber.addRock(previous);
        highest = (int) chamber.chamber.size();
    }
    return to_string(highest - 1);
}

tuple<bool, ull, ull> alreadySeen(unordered_map<HashClass, ull> &history, HashClass &hc, ull iteration) {
    auto it = history.find(hc);
    if (it != history.end()) {
        return {true, it->second, it->first.highest};
    }
    history[hc] = iteration;
    return {false, 0, 0};
}

string Day17Solver::executePuzzle2() {
    vector<Rock> rocks(5);
    rocks[0].points = {PointDay17(0, 0), PointDay17(0, 1), PointDay17(0, 2), PointDay17(0, 3)};
    rocks[1].points = {PointDay17(0, 1), PointDay17(1, 0), PointDay17(1, 1), PointDay17(1, 2), PointDay17(2, 1)};
    rocks[2].points = {PointDay17(2, 2), PointDay17(1, 2), PointDay17(0, 0), PointDay17(0, 1), PointDay17(0, 2)};
    rocks[3].points = {PointDay17(0, 0), PointDay17(1, 0), PointDay17(2, 0), PointDay17(3, 0)};
    rocks[4].points = {PointDay17(0, 0), PointDay17(0, 1), PointDay17(1, 0), PointDay17(1, 1)};

    for (Rock &rock: rocks) {
        for (PointDay17 &p: rock.points) {
            p.col += 2;
        }
    }

    ull highest = 1;

    // key -> hashed HashClass, value -> iteration
    unordered_map<HashClass, ull> history;
    Chamber chamber;
    chamber.chamber.emplace_back(7, '#');

    ull i = 0;
    int i_input = 0;
    const ull TRILLION = 1'000'000'000'000;
    while (i < TRILLION) {
        auto rock = rocks[i % 5];
        i++;
        rock.moveToStart(highest);
        Rock previous = rock;

        while (!chamber.intersection(rock)) {
            chamber.jetPush(input[0][i_input], rock);
            i_input++;
            if (i_input == input[0].length()) {
                i_input = 0;
            }
            previous = rock;
            rock.simulate();
        }
        chamber.addRock(previous);
        highest = (int) chamber.chamber.size();

        vector<vector<char>> top_five(5);
        for (int i_old = max((int) chamber.chamber.size() - 5, 0), i_new = 0; i_old < chamber.chamber.size(); i_old++, i_new++) {
            top_five[i_new] = chamber.chamber[i_old];
        }

        HashClass hashable = HashClass(top_five, i_input, (int) i % 5, highest);
        tuple<bool, ull, ull> result = alreadySeen(history, hashable, i);
        bool seen = get<0>(result);

        if (seen) {
            ull previous_iteration = get<1>(result);
            ull previous_highest = get<2>(result);

            ull delta_iter = i - previous_iteration;
            ull delta_height = highest - previous_highest;
            ull until_trillion = (TRILLION - previous_iteration);
            ull n_rep = until_trillion / delta_iter;
            ull remaining = until_trillion % delta_iter;

            ull extra_height = 0;
            for (auto& key_value: history) {
                if (ull(key_value.second) - previous_iteration == remaining) {
                    extra_height = key_value.first.highest - previous_highest;
                    break;
                }
            }
            ull total_height = previous_highest + (delta_height * n_rep) + extra_height;
            return to_string(total_height - 1);
        }
    }
    return to_string(highest - 1);
}