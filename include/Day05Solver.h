#ifndef ADVENTOFCODE2022_DAY05SOLVER_H
#define ADVENTOFCODE2022_DAY05SOLVER_H

#include "Solver.h"


class Day05Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day05Solver() : Solver(5) {};
};


#endif //ADVENTOFCODE2022_DAY05SOLVER_H
