#ifndef ADVENTOFCODE2022_DAY15SOLVER_H
#define ADVENTOFCODE2022_DAY15SOLVER_H

#include "Solver.h"


class Day15Solver : public Solver {
private:
    string executePuzzle1() override;
    string executePuzzle2() override;
public:
    Day15Solver() : Solver(15) {};

};


#endif //ADVENTOFCODE2022_DAY15SOLVER_H
