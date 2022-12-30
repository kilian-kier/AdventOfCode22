#ifndef ADVENTOFCODE2022_DAY19SOLVER_H
#define ADVENTOFCODE2022_DAY19SOLVER_H

#include "Solver.h"


class Day19Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day19Solver() : Solver(19) {};
};


#endif //ADVENTOFCODE2022_DAY19SOLVER_H
