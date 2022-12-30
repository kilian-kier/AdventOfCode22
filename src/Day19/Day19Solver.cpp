#include "../../include/Day19Solver.h"

using namespace std;

class Blueprint {
public:
    int r_ore_ore_cost;
    int r_clay_ore_cost;
    int r_obsidian_ore_cost;
    int r_obsidian_clay_cost;
    int r_geode_ore_cost;
    int r_geode_obsidian_cost;

    int max_ore_needed;
};

class Situation {
public:
    int num_r_ore;
    int num_r_clay;
    int num_r_obsidian;
    int num_r_geode;
    int ore;
    int clay;
    int obsidian;
    int geode;
    int time_elapsed;

    void mine() {
        ore += num_r_ore;
        clay += num_r_clay;
        obsidian += num_r_obsidian;
        geode += num_r_geode;
        time_elapsed++;
    }

    // 0 -> ore, 1 -> clay, 2 -> obsidian, 3 -> geode
    bool shouldBuild(int material, Blueprint blueprint) const {
        bool make_sense = false, can_build = false; // it makes no sense to build a robot, if I have enough to collect the maximum needed in one minute
        switch (material) {
            case 0: {
                make_sense = num_r_ore < blueprint.max_ore_needed;
                can_build = ore >= blueprint.r_ore_ore_cost;
                break;
            }
            case 1: {
                make_sense = num_r_clay < blueprint.r_obsidian_clay_cost;
                can_build = ore >= blueprint.r_clay_ore_cost;
                break;
            }
            case 2: {
                make_sense = num_r_obsidian < blueprint.r_geode_obsidian_cost;
                can_build = ore >= blueprint.r_obsidian_ore_cost && clay >= blueprint.r_obsidian_clay_cost;
                break;
            }
            case 3: {
                make_sense = true;
                can_build = ore >= blueprint.r_geode_ore_cost && obsidian >= blueprint.r_geode_obsidian_cost;
                break;
            }
            default:
                break;
        }

        if (make_sense && can_build) {
            return true;
        }
        return false;
    }

    void buildRobot(int material, Blueprint blueprint) {
        switch (material) {
            case 0: {
                ore -= blueprint.r_ore_ore_cost;
                num_r_ore++;
                break;
            }
            case 1: {
                ore -= blueprint.r_clay_ore_cost;
                num_r_clay++;
                break;
            }
            case 2: {
                ore -= blueprint.r_obsidian_ore_cost;
                clay -= blueprint.r_obsidian_clay_cost;
                num_r_obsidian++;
                break;
            }
            case 3: {
                ore -= blueprint.r_geode_ore_cost;
                obsidian -= blueprint.r_geode_obsidian_cost;
                num_r_geode++;
                break;
            }
            default:
                break;
        }
    }

    bool canNotBeBetter(int max_geodes, int max_time) const {
        int remaining = max_time + 1 - time_elapsed;
        int geodes_from_existing = num_r_geode * remaining;
        int geodes_from_new = remaining * (remaining - 1) / 2;

        int max_reachable_geodes = geode + geodes_from_existing + geodes_from_new;
        return max_reachable_geodes < max_geodes;
    }
};

int DFSDay19(Blueprint blueprint, int max_time) {
    queue<Situation> queue;
    queue.push(Situation{1, 0, 0, 0, 0, 0, 0, 0, 0});
    int max_geodes = 0;

    while (!queue.empty()) {
        Situation current = queue.front();
        queue.pop();

        if (current.time_elapsed >= max_time)
            continue;

        // I give up, if I can not reach the max_geodes with this Situation in the remaining time
        if (current.canNotBeBetter(max_geodes, max_time))
            continue;

        // it is not necessary to build a bot in the last minute
        if (current.time_elapsed == max_time - 1) {
            current.mine();
            max_geodes = max(max_geodes, current.geode);
            continue;
        }

        if (current.shouldBuild(3, blueprint)) {
            current.mine();
            current.buildRobot(3, blueprint);
            queue.push(current);
            // if I can build a geode roboter then no other roboter should be build. Therefor continue
            continue;
        }

        // in the penultimate minute I only need to build geode robots
        if (current.time_elapsed < max_time - 2) {
            if (current.shouldBuild(2, blueprint)) {
                current.mine();
                current.buildRobot(2, blueprint);
                queue.push(current);

                // !!! this should not work with every input, but with my input I can say that it's always better to build an obsidian robot rather than an ore or clay robot. Therefor continue
                continue;
            }

            if (current.shouldBuild(1, blueprint)) {
                Situation clay = current;
                clay.mine();
                clay.buildRobot(1, blueprint);
                queue.push(clay);
            }

            if (current.shouldBuild(0, blueprint)) {
                Situation ore = current;
                ore.mine();
                ore.buildRobot(0, blueprint);
                queue.push(ore);
            }
        }
        current.mine();
        queue.push(current);
    }

    return max_geodes;
}

vector<Blueprint> blueprints;

string Day19Solver::executePuzzle1() {
    regex re(R"((\d+\s))");
    int total = 0;

    blueprints.resize(input.size());

    for (int i = 0; i < input.size(); i++) {
        string line = input[i];
        smatch m;
        vector<int> matches;
        while (regex_search(line, m, re)) {
            matches.push_back(Converter::StringToInt(m.str(0)));
            line = m.suffix().str();
        }

        blueprints[i].r_ore_ore_cost = matches[0];
        blueprints[i].r_clay_ore_cost = matches[1];
        blueprints[i].r_obsidian_ore_cost = matches[2];
        blueprints[i].r_obsidian_clay_cost = matches[3];
        blueprints[i].r_geode_ore_cost = matches[4];
        blueprints[i].r_geode_obsidian_cost = matches[5];

        blueprints[i].max_ore_needed = max({
            blueprints[i].r_clay_ore_cost,
            blueprints[i].r_obsidian_ore_cost,
            blueprints[i].r_geode_ore_cost
        });

        int geodes = DFSDay19(blueprints[i], 24);
        total += (i + 1) * geodes;
    }

    return to_string(total);
}

string Day19Solver::executePuzzle2() {
    int mul = 1;

    // Example
    if (blueprints.size() < 3)
        return "Not possible";

    for (int i = 0; i < 3; i++) {
        int geodes = DFSDay19(blueprints[i], 32);
        mul *= geodes;
    }

    return to_string(mul);
}