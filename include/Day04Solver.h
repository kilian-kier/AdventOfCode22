#ifndef ADVENTOFCODE2022_DAY04SOLVER_H
#define ADVENTOFCODE2022_DAY04SOLVER_H

#include "Solver.h"


class Day04Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day04Solver() : Solver(4) {};
};


#endif //ADVENTOFCODE2022_DAY04SOLVER_H
