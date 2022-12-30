#ifndef ADVENTOFCODE2022_DAY02SOLVER_H
#define ADVENTOFCODE2022_DAY02SOLVER_H

#include "Solver.h"


class Day02Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day02Solver() : Solver(2) {};
};


#endif //ADVENTOFCODE2022_DAY02SOLVER_H
