#ifndef ADVENTOFCODE2022_DAY09SOLVER_H
#define ADVENTOFCODE2022_DAY09SOLVER_H

#include "Solver.h"


class Day09Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
    int ropeFunc(int rope_length);
public:
    Day09Solver() : Solver(9) {};

};


#endif //ADVENTOFCODE2022_DAY09SOLVER_H
