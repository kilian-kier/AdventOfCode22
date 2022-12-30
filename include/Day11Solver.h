#ifndef ADVENTOFCODE2022_DAY11SOLVER_H
#define ADVENTOFCODE2022_DAY11SOLVER_H

#include "Solver.h"


class Day11Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day11Solver() : Solver(11) {};

};


#endif //ADVENTOFCODE2022_DAY11SOLVER_H
