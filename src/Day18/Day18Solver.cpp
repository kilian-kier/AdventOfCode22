#include "../../include/Day18Solver.h"

class Cube {
public:
    int x;
    int y;
    int z;

    Cube() {
        x = y = z = 0;
    }

    Cube(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    bool operator==(Cube c) const {
        return this->x == c.x && this->y == c.y && this->z == c.z;
    }
};

vector<Cube> adjacent{
        {-1, 0,  0},
        {1,  0,  0},
        {0,  -1, 0},
        {0,  1,  0},
        {0,  0,  -1},
        {0,  0,  1}
};

vector<Cube> cubes;
int max_value = 0;

string Day18Solver::executePuzzle1() {
    cubes.resize(input.size());

    int pairs = 0;

    for (int i = 0; i < input.size(); i++) {
        vector<string> split = Utils::splitToString(input[i], ",");
        // +1 to prevent zeros
        cubes[i].x = Converter::StringToInt(split[0]) + 1;
        cubes[i].y = Converter::StringToInt(split[1]) + 1;
        cubes[i].z = Converter::StringToInt(split[2]) + 1;

        max_value = max(max_value, cubes[i].x);
        max_value = max(max_value, cubes[i].y);
        max_value = max(max_value, cubes[i].z);

        for (int j = 0; j < 6; j++) {
            Cube adj{};
            adj.x = cubes[i].x + adjacent[j].x;
            adj.y = cubes[i].y + adjacent[j].y;
            adj.z = cubes[i].z + adjacent[j].z;

            if (find(cubes.begin(), cubes.end(), adj) != cubes.end()) {
                pairs++;
            }
        }
    }

    int surface = (int) (6 * cubes.size()) - (2 * pairs);
    return to_string(surface);
}

string Day18Solver::executePuzzle2() {
    max_value++;
    vector<vector<vector<int>>> grid(max_value + 1, vector<vector<int>>(max_value + 1, vector<int>(max_value + 1, 0)));
    list<Cube> q;
    q.emplace_back();
    grid[0][0][0] = 1;

    while (!q.empty()) {
        Cube c = q.front();
        q.pop_front();

        for (int i = 0; i < 6; i++) {
            Cube adj{};
            adj.x = c.x + adjacent[i].x;
            adj.y = c.y + adjacent[i].y;
            adj.z = c.z + adjacent[i].z;

            if (adj.x < 0 || adj.x > max_value)
                continue;
            if (adj.y < 0 || adj.y > max_value)
                continue;
            if (adj.z < 0 || adj.z > max_value)
                continue;
            if (grid[adj.x][adj.y][adj.z] != 0)
                continue;

            if (find(cubes.begin(), cubes.end(), adj) == cubes.end()) {
                grid[adj.x][adj.y][adj.z] = 1;
                q.push_back(adj);
            }
        }
    }

    int surface = 0;

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < 6; j++) {
            Cube adj{};
            adj.x = cubes[i].x + adjacent[j].x;
            adj.y = cubes[i].y + adjacent[j].y;
            adj.z = cubes[i].z + adjacent[j].z;

            if (adj.x < 0 || adj.x > max_value)
                continue;
            if (adj.y < 0 || adj.y > max_value)
                continue;
            if (adj.z < 0 || adj.z > max_value)
                continue;

            if (grid[adj.x][adj.y][adj.z] == 1) {
                surface++;
            }
        }
    }

    return to_string(surface);
}