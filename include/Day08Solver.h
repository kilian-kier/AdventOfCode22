#ifndef ADVENTOFCODE2022_DAY08SOLVER_H
#define ADVENTOFCODE2022_DAY08SOLVER_H

#include "Solver.h"


class Day08Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day08Solver() : Solver(8) {};

};


#endif //ADVENTOFCODE2022_DAY08SOLVER_H
