#include "../../include/InputHelper.h"

vector<string> InputHelper::GetInput(int day) {
    vector<string> ret;

    ifstream inputFile;
    string inputFilePath = GetInputFilePath(day);
    inputFile.open(inputFilePath);

    if (!inputFile) {
        cerr << inputFilePath << "does not exist" << endl;
        exit(EXIT_FAILURE);
    }

    string tmp;
    while (getline(inputFile, tmp)) {
        ret.push_back(tmp);
    }

    return ret;
}

vector<string> InputHelper::GetExampleInput(int day) {
    vector<string> ret;

    ifstream exampleFile;
    string exampleFilePath = GetExampleInputFilePath(day);
    exampleFile.open(exampleFilePath);

    if (!exampleFile) {
        cerr << exampleFilePath << "does not exist" << endl;
        exit(EXIT_FAILURE);
    }

    string tmp;
    while (getline(exampleFile, tmp)) {
        ret.push_back(tmp);
    }

    return ret;
}

void InputHelper::WriteOutput(int day, const string& example1, const string& example2, const string& part1, const string& part2) {
    ofstream outputFile;
    string outputFilePath = GetOutputFilePath(day);
    outputFile.open(outputFilePath);

    if (!outputFile) {
        cerr << "Could not create " << outputFilePath << endl;
        exit(EXIT_FAILURE);
    }

    outputFile << "Example 1:" << endl << example1 << endl << endl;
    outputFile << "Example 2:" << endl << example2 << endl << endl;
    outputFile << "Part 1:" << endl << part1 << endl << endl;
    outputFile << "Part 2:" << endl << part2 << endl << endl;
}

string InputHelper::GetInputFilePath(int day) {
    return GetDayDirPath(day) + PATH_SEPARATOR + "input.txt";
}

string InputHelper::GetExampleInputFilePath(int day) {
    return GetDayDirPath(day) + PATH_SEPARATOR + "example.txt";
}

string InputHelper::GetOutputFilePath(int day) {
    return GetDayDirPath(day) + PATH_SEPARATOR + "output.txt";
}

string InputHelper::GetDayDirPath(int day) {
    stringstream dayStr;
    dayStr << ".." << PATH_SEPARATOR << "src" << PATH_SEPARATOR <<"Day" << Converter::ZeroPadString(to_string(day), 2);
    filesystem::path filePath = dayStr.str();
    return filesystem::canonical(filePath);
}