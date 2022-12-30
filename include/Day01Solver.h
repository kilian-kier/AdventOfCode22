#ifndef ADVENTOFCODE2022_DAY01SOLVER_H
#define ADVENTOFCODE2022_DAY01SOLVER_H

#include "Solver.h"


class Day01Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day01Solver() : Solver(1) {};
};


#endif //ADVENTOFCODE2022_DAY01SOLVER_H
