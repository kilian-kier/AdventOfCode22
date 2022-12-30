#ifndef ADVENTOFCODE2022_DAY20SOLVER_H
#define ADVENTOFCODE2022_DAY20SOLVER_H

#include "Solver.h"


class Day20Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day20Solver() : Solver(20) {};
};


#endif //ADVENTOFCODE2022_DAY20SOLVER_H
