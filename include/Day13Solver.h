#ifndef ADVENTOFCODE2022_DAY13SOLVER_H
#define ADVENTOFCODE2022_DAY13SOLVER_H

#include "Solver.h"


class Day13Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day13Solver() : Solver(13) {};

};


#endif //ADVENTOFCODE2022_DAY13SOLVER_H
