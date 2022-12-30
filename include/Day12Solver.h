#ifndef ADVENTOFCODE2022_DAY12SOLVER_H
#define ADVENTOFCODE2022_DAY12SOLVER_H

#include "Solver.h"


class Day12Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day12Solver() : Solver(12) {};

};


#endif //ADVENTOFCODE2022_DAY12SOLVER_H
