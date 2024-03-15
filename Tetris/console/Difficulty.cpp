#include "Difficulty.h"
#include <fstream>
#include <sstream>
#include <iostream>

Difficulty::Difficulty(int level)
{
    std::string filename = "./difficulties/" + std::to_string(level) + ".txt";
    std::ifstream file(filename);
    std::string fileLine;
    if (file.is_open()) {
        std::getline(file, fileLine);
        this->maxScore_ = std::stoi(fileLine);

        std::getline(file, fileLine);
        this->maxLines_ = std::stoi(fileLine);

        std::getline(file, fileLine);
        this->timeLimit_ = std::stoi(fileLine);

        file.close();
    } else {
        std::cerr << "Failed to open the file." << std::endl;
    }
}

int Difficulty::getMaxScore()
{
    return maxScore_;
}

int Difficulty::getMaxLines()
{
    return maxLines_;
}

int Difficulty::getTimeLimit()
{
    return timeLimit_;
}
