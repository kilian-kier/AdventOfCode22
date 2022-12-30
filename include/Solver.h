#ifndef ADVENTOFCODE2022_SOLVER_H
#define ADVENTOFCODE2022_SOLVER_H

#include <bits/stdc++.h>
#include <chrono>
#include "InputHelper.h"
#include "Converter.h"
#include "Utils.h"

using namespace std;

class Solver {
protected:
    int day;
    vector<string> input;

    virtual string executePuzzle1();
    virtual string executePuzzle2();
public:
    explicit Solver(int day);
    void execute();
};


#endif //ADVENTOFCODE2022_SOLVER_H
