#ifndef ADVENTOFCODE2022_DAY14SOLVER_H
#define ADVENTOFCODE2022_DAY14SOLVER_H

#include "Solver.h"


class Day14Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day14Solver() : Solver(14) {};

};


#endif //ADVENTOFCODE2022_DAY14SOLVER_H
