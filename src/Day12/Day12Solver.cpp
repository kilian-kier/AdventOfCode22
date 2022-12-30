#include "../../include/Day12Solver.h"

class PointDay12 {
public:
    char c{};
    list<int> neighbors;
};

class Graph{
public:
    vector<PointDay12> points;
    vector<int> distance;
    vector<int> a_idx;
    int s_idx, e_idx;

    Graph(const vector<string>& input) {
        points.resize(input.size() * input[0].length());
        for (int r = 0; r < input.size(); r++) {
            for (int c = 0; c < input[r].length(); c++) {
                int idx = (int)(r * input[r].length() + c);
                char ch = input[r][c];
                if (ch == 'S') {
                    points[idx].c = 'a';
                    s_idx = idx;
                    a_idx.push_back(idx);
                } else if (ch == 'E') {
                    points[idx].c = 'z';
                    e_idx = idx;
                } else if (ch == 'a') {
                    points[idx].c = ch;
                    a_idx.push_back(idx);
                } else {
                    points[idx].c = ch;
                }
            }
        }

        for (int r = 0; r < input.size(); r++) {
            for (int c = 0; c < input[r].length(); c++) {
                int idx = (int)(r * input[r].length() + c);
                int idx_u = (int)((r - 1) * input[r].length() + c);
                int idx_d = (int)((r + 1) * input[r].length() + c);
                int idx_l = (int)(r * input[r].length() + c - 1);
                int idx_r = (int)(r * input[r].length() + c + 1);

                char point = points[idx].c;

                if (r != 0 && points[idx_u].c - 1 <= point) {
                    addEdge(idx_u, idx);
                }

                if (r != input.size() - 1 && points[idx_d].c - 1 <= point) {
                    addEdge(idx_d, idx);
                }

                if (c != 0 && points[idx_l].c - 1 <= point) {
                    addEdge(idx_l, idx);
                }

                if (c != input[r].length() - 1 && points[idx_r].c - 1 <= point) {
                    addEdge(idx_r, idx);
                }
            }
        }
    }

    void addEdge(int src, int dest) {
        points[src].neighbors.push_back(dest);
    }

    void BFSDay12() {
        distance.resize(points.size(), INT_MAX);
        vector<bool> visited(points.size(), false);
        list<int> q;


        int u = e_idx;
        distance[u] = 0;
        visited[u] = true;
        q.push_back(u);

        while (!q.empty()) {
            u = q.front();
            q.pop_front();

            for (int i : points[u].neighbors)  {
                if (visited[i])
                    continue;
                distance[i] = distance[u] + 1;
                visited[i] = true;
                q.push_back(i);
            }
        }
    }
};

Graph *graph;

string Day12Solver::executePuzzle1() {
    graph = new Graph(input);
    graph->BFSDay12();
    return to_string(graph->distance[graph->s_idx]);
}

string Day12Solver::executePuzzle2() {
    int mi = INT_MAX;
    for (int i : graph->a_idx) {
        mi = min(mi, graph->distance[i]);
    }
    return to_string(mi);
}