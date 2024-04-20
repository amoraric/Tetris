#include "View.h"
#include <iostream>
#include <limits>
#include <cstdlib>

// ANSI escape codes for text colorization
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void View::welcome()
{
    // system("clear");
    std::cout<<"Welcome to Tetris"<<std::endl;
}

void View::display(Board board, Position p, BrickModel b)
{
    system("clear");
    std::vector<Position> v {};
    for (int var = 0; var < b.model.size(); ++var) {
        v.push_back({b.model[var].get_x()+p.get_x(),b.model[var].get_y()+p.get_y()});

    }
    for (int i = 0; i < board.getSize(); ++i) {
        for (int j = 0; j < board.getBoard()[0].size(); ++j) {
            bool written = false;
            for (int var = 0; var < v.size(); ++var) {
                if(i == v[var].get_x() && j == v[var].get_y()){
                    std::cout<<"x";
                    v.erase(v.begin()+var);
                    written = true;
                    break;
                }
            }
            if(board.getBoard()[i][j] && !written){
                std::cout<<"o";
            }
            else if (!board.getBoard()[i][j] && !written){
                std::cout<<"_";
            }

        }
        std::cout<<std::endl;
    }
}

std::tuple<std::string, int, bool, int, int> View::configure()
{
    std::cout << "Enter your nickname: ";
    std::string nickname;
    std::cin >> nickname;

    std::cout << "Enter your level (an integer lower than or equal to 3): ";
    int level;
    while (!(std::cin >> level) || level > 3) { // Input validation loop
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer for the level: ";
    }
    std::cout<< "Enter any number to randomize the board and 0 to not randomize: ";
    int randomize;
    while (!(std::cin >> randomize)) {
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer: ";
    }

    std::cout << "Enter the number of rows of the board (min. 8): ";
    int rows;
    while (!(std::cin >> rows) || rows < 8) {
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer greater than or equal to 8: ";
    }

    std::cout << "Enter the number of columns of the board (min. 8): ";
    int columns;
    while (!(std::cin >> columns) || columns < 8) {
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer greater than or equal to 8: ";
    }

    return std::make_tuple(nickname, level, randomize, rows, columns);
}

void View::gameOver()
{
    std::cout<<"Game Over"<<std::endl;
}
std::string View::askAction()
{
    std::cout << "Enter an action: ";
    std::string action;
    std::cin>>action;
    std::cout << std::endl;
    return action;
}

void View::showStats(std::string nickname, int level, int score, int linesCompleted) {
    std::cout << "Player " << nickname << " has :" << std::endl;
    std::cout << "Level : " << level << std::endl;
    std::cout << "Score : " << score << std::endl;
    std::cout << "Lines Completed : " << linesCompleted << std::endl;
}
