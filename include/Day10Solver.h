#ifndef ADVENTOFCODE2022_DAY10SOLVER_H
#define ADVENTOFCODE2022_DAY10SOLVER_H

#include "Solver.h"


class Day10Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day10Solver() : Solver(10) {};

};


#endif //ADVENTOFCODE2022_DAY10SOLVER_H
