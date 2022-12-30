#include "../../include/Day13Solver.h"

class Object {
public:
    vector<Object *> list{};
    int value{};
    bool is_value{};
};

int parse(Object *obj, const string &line, int i = 1) {
    while (i < line.length()) {
        if (line[i] == '[') {
            auto new_obj = new Object();
            new_obj->is_value = false;
            obj->list.push_back(new_obj);
            i = parse(new_obj, line, i + 1);
        } else if (line[i] >= '0' && line[i] <= '9') {
            int start_idx = i;
            while (line[i] >= '0' && line[i] <= '9') {
                i++;
            }

            auto new_obj = new Object();
            new_obj->is_value = true;
            new_obj->value = Converter::StringToInt(line.substr(start_idx, i - start_idx));
            obj->list.push_back(new_obj);
        } else if (line[i] == ',') {
            i++;
        } else if (line[i] == ']') {
            return i + 1;
        }
    }

    return i;
}

int compare(Object *obj1, Object *obj2) {
    int i = 0;
    while (i < obj1->list.size() && i < obj2->list.size()) {
        Object *o1 = obj1->list[i];
        Object *o2 = obj2->list[i];
        if (o1->is_value && o2->is_value) {
            if (o1->value < o2->value) {
                return 1;
            } else if (o1->value > o2->value) {
                return -1;
            }
        } else if (!o1->is_value && !o2->is_value) {
            int result = compare(o1, o2);
            if (result) {
                return result;
            }
        } else if (o1->is_value && !o2->is_value) {
            auto temp = new Object();
            temp->is_value = false;
            auto temp2 = new Object();
            temp2->is_value = true;
            temp2->value = o1->value;
            temp->list.push_back(temp2);

            int result = compare(temp, o2);
            if (result) {
                return result;
            }
        } else if (!o1->is_value && o2->is_value) {
            auto temp = new Object();
            temp->is_value = false;
            auto temp2 = new Object();
            temp2->is_value = true;
            temp2->value = o2->value;
            temp->list.push_back(temp2);

            int result = compare(o1, temp);
            if (result) {
                return result;
            }
        }
        i++;
    }


    if (obj1->list.size() < obj2->list.size()) {
        return 1;
    } else if (obj1->list.size() > obj2->list.size()) {
        return -1;
    }

    return 0;
}

vector<Object *> objects;

string Day13Solver::executePuzzle1() {
    objects = vector<Object *>(0);
    for (string &line: input) {
        if (line.empty())
            continue;

        auto obj = new Object();
        parse(obj, line);
        objects.push_back(obj);
    }

    int ret = 0;

    for (int i = 0; i < objects.size(); i += 2) {
        int result = compare(objects[i], objects[i + 1]);
        if (result > 0) {
            ret += (i / 2) + 1;
        }
    }

    return to_string(ret);
}

string Day13Solver::executePuzzle2() {
    input.emplace_back("[[2]]");
    input.emplace_back("[[6]]");
    auto end = remove_if(input.begin(), input.end(), [](string& s) {
        return s.empty();
    });

    sort(input.begin(), end, [](string& s1, string& s2) {
        Object obj1, obj2;
        parse(&obj1, s1);
        parse(&obj2, s2);

        int result = compare(&obj1, &obj2);
        return result > 0;
    });

    int ret = 1;

    for (auto it = input.begin(); it != end; it++) {
        if (*it == "[[2]]" || *it == "[[6]]") {
            ret *= (int)(it - input.begin() + 1);
        }
    }

    return to_string(ret);
}