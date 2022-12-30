#ifndef ADVENTOFCODE2022_DAY17SOLVER_H
#define ADVENTOFCODE2022_DAY17SOLVER_H

#include "Solver.h"


class Day17Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day17Solver() : Solver(17) {};

};


#endif //ADVENTOFCODE2022_DAY17SOLVER_H
