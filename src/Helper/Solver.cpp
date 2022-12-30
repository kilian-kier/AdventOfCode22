#include "../../include/Solver.h"

Solver::Solver(int day) {
    this->day = day;
}

void Solver::execute() {
    string example1;
    string example2;
    string part1;
    string part2;

    input = InputHelper::GetExampleInput(day);

    chrono::time_point start = chrono::high_resolution_clock::now();
    example1 = executePuzzle1();
    chrono::time_point stop = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> example1_time = stop - start;

    start = chrono::high_resolution_clock::now();
    example2 = executePuzzle2();
    stop = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> example2_time = stop - start;

    input = InputHelper::GetInput(day);

    start = chrono::high_resolution_clock::now();
    part1 = executePuzzle1();
    stop = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> part1_time = stop - start;

    start = chrono::high_resolution_clock::now();
    part2 = executePuzzle2();
    stop = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> part2_time = stop - start;

    InputHelper::WriteOutput(day, example1, example2, part1, part2);

    if (day == 1) {
        cout << "Day " << day << ": " << part1_time.count() + part2_time.count() << "ms (without Examples)" << endl;
    } else {
        cout << "Day " << day << ": " << part1_time.count() + part2_time.count() << "ms" << endl;
    }

    cout << "\tExample 1 (" << example1_time.count() << "ms): " << example1 << endl;
    cout << "\tExample 2 (" << example2_time.count() << "ms): " << example2 << endl;
    cout << "\tPart 1 (" << part1_time.count() << "ms): " << part1 << endl;
    cout << "\tPart 2 (" << part2_time.count() << "ms): " << part2 << endl << endl;
}

string Solver::executePuzzle1() {
    return "";
}

string Solver::executePuzzle2() {
    return "";
}
