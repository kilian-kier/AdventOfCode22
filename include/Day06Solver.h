#ifndef ADVENTOFCODE2022_DAY06SOLVER_H
#define ADVENTOFCODE2022_DAY06SOLVER_H

#include "Solver.h"


class Day06Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
    int firstDuplicate(int length);
public:
    Day06Solver() : Solver(6) {};

};


#endif //ADVENTOFCODE2022_DAY06SOLVER_H
