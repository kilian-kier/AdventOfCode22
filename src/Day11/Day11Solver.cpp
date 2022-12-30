#include "../../include/Day11Solver.h"

class Monkey {
public:
    // unsigned long long because of the overflow in Part 2
    list<unsigned long long> items;

    unsigned long long (*operation)(unsigned long long, unsigned long long){};

    int operand{};
    int divisible_by{};
    int throw_to_if_ture{};
    int throw_to_if_false{};
    int inspections = 0;
};

unsigned long long addition(unsigned long long old, unsigned long long value) {
    return old + value;
}

unsigned long long multiplication(unsigned long long old, unsigned long long value) {
    return old * value;
}

string Day11Solver::executePuzzle1() {
    int n_monkeys = (int) (input.size() + 1) / 7;
    vector<Monkey> monkeys(n_monkeys);
    for (int i = 0; i < n_monkeys; i++) {
        int line_idx = i * 7;
        vector<int> split = Utils::splitToInt(input[line_idx + 1].substr(18), ", ");
        monkeys[i].items = list<unsigned long long>(split.begin(), split.end());

        char op = input[line_idx + 2].substr(23)[0];
        if (op == '+') {
            monkeys[i].operation = addition;
        } else {
            monkeys[i].operation = multiplication;
        }

        if (input[line_idx + 2].substr(25) == "old") {
            monkeys[i].operand = -1;
        } else {
            monkeys[i].operand = Converter::StringToInt(input[line_idx + 2].substr(25));
        }

        monkeys[i].divisible_by = Converter::StringToInt(input[line_idx + 3].substr(21));
        monkeys[i].throw_to_if_ture = Converter::StringToInt(input[line_idx + 4].substr(29));
        monkeys[i].throw_to_if_false = Converter::StringToInt(input[line_idx + 5].substr(30));
    }

    for (int i_round = 0; i_round < 20; i_round++) {
        for (int i_monkey = 0; i_monkey < n_monkeys; i_monkey++) {
            for (int i_item = 0;
                 i_item < monkeys[i_monkey].items.size(); /*I pop the first element, so no increment*/) {
                monkeys[i_monkey].inspections++;

                unsigned long long item = monkeys[i_monkey].items.front();
                unsigned long long operand = monkeys[i_monkey].operand;
                if (operand == -1)
                    operand = item;

                item = monkeys[i_monkey].operation(item, operand) / 3;

                if (item % monkeys[i_monkey].divisible_by == 0) {
                    monkeys[monkeys[i_monkey].throw_to_if_ture].items.push_back(item);
                } else {
                    monkeys[monkeys[i_monkey].throw_to_if_false].items.push_back(item);
                }
                monkeys[i_monkey].items.pop_front();
            }
        }
    }

    set<int, greater<>> inspections;
    for (const Monkey &monkey: monkeys) {
        inspections.insert(monkey.inspections);
    }
    auto it = inspections.begin();
    return to_string(*it * *(++it));
}

string Day11Solver::executePuzzle2() {
    int n_monkeys = (int) (input.size() + 1) / 7;
    vector<Monkey> monkeys(n_monkeys);

    int worry_divider = 1;

    for (int i = 0; i < n_monkeys; i++) {
        int line_idx = i * 7;
        vector<int> split = Utils::splitToInt(input[line_idx + 1].substr(18), ", ");
        monkeys[i].items = list<unsigned long long>(split.begin(), split.end());

        char op = input[line_idx + 2].substr(23)[0];
        if (op == '+') {
            monkeys[i].operation = addition;
        } else {
            monkeys[i].operation = multiplication;
        }

        if (input[line_idx + 2].substr(25) == "old") {
            monkeys[i].operand = -1;
        } else {
            monkeys[i].operand = Converter::StringToInt(input[line_idx + 2].substr(25));
        }

        monkeys[i].divisible_by = Converter::StringToInt(input[line_idx + 3].substr(21));
        monkeys[i].throw_to_if_ture = Converter::StringToInt(input[line_idx + 4].substr(29));
        monkeys[i].throw_to_if_false = Converter::StringToInt(input[line_idx + 5].substr(30));
        worry_divider *= monkeys[i].divisible_by;
    }

    for (int i_round = 0; i_round < 10'000; i_round++) {
        for (int i_monkey = 0; i_monkey < n_monkeys; i_monkey++) {
            for (int i_item = 0; i_item < monkeys[i_monkey].items.size();) {
                monkeys[i_monkey].inspections++;

                unsigned long long item = monkeys[i_monkey].items.front();
                unsigned long long operand = monkeys[i_monkey].operand;
                if (operand == -1)
                    operand = item;

                item = monkeys[i_monkey].operation(item, operand) % worry_divider;

                if (item % monkeys[i_monkey].divisible_by == 0) {
                    monkeys[monkeys[i_monkey].throw_to_if_ture].items.push_back(item);
                } else {
                    monkeys[monkeys[i_monkey].throw_to_if_false].items.push_back(item);
                }
                monkeys[i_monkey].items.pop_front();
            }
        }
    }

    set<int, greater<>> inspections;
    for (const Monkey &monkey: monkeys) {
        inspections.insert(monkey.inspections);
    }
    auto it = inspections.begin();
    unsigned long long first = *it;
    ++it;
    unsigned long long second = *it;
    return to_string(first * second);
}