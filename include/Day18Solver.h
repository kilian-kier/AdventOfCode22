#ifndef ADVENTOFCODE2022_DAY18SOLVER_H
#define ADVENTOFCODE2022_DAY18SOLVER_H

#include "Solver.h"


class Day18Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day18Solver() : Solver(18) {};

};


#endif //ADVENTOFCODE2022_DAY18SOLVER_H
