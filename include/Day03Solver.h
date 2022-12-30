#ifndef ADVENTOFCODE2022_DAY03SOLVER_H
#define ADVENTOFCODE2022_DAY03SOLVER_H

#include "Solver.h"


class Day03Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day03Solver() : Solver(3) {};
};


#endif //ADVENTOFCODE2022_DAY03SOLVER_H
