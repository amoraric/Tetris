#include "Difficulty.h"
#include <fstream>
#include <iostream>

Difficulty::Difficulty(int level)
{
    this->level_ = level;
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
        std::cerr << "File can't be open" << std::endl;
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

void Difficulty::setLevel(int level)
{
   level_ = level;
}

int Difficulty::getLevel()
{
    return this->level_;
}

bool Difficulty::load()
{
    std::string filename = "./difficulties/" + std::to_string(level_) + ".txt";
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
        return false;
    }
    return true;
}

bool Difficulty::nextDifficulty()
{
    setLevel(level_+1);
    return load();
}
