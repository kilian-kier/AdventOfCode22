#ifndef ADVENTOFCODE2022_DAY07SOLVER_H
#define ADVENTOFCODE2022_DAY07SOLVER_H

#include "Solver.h"


class Day07Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day07Solver() : Solver(7) {};

};


#endif //ADVENTOFCODE2022_DAY07SOLVER_H
