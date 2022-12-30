#ifndef ADVENTOFCODE2022_DAY16SOLVER_H
#define ADVENTOFCODE2022_DAY16SOLVER_H

#include "Solver.h"


class Day16Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day16Solver() : Solver(16) {};

};


#endif //ADVENTOFCODE2022_DAY16SOLVER_H
