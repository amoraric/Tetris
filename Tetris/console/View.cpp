#include "View.h"
#include <iostream>

using namespace std;


void View::welcome()
{
   cout<<"Welcome to Tetris"<<endl;
}

void View::display(Board board, Position p, BrickModel b)
{
    vector<Position> v {};
    v.push_back(p);
    for (int var = 1; var < b.model.size(); ++var) {
        v.push_back({b.model[var].get_x()+p.get_x(),b.model[var].get_y()+p.get_y()});

    }
    for (int i = 0; i < board.getSize(); ++i) {
        for (int j = 0; j < board.getBoard()[0].size(); ++j) {
            if(p.get_x() == i && p.get_y() == j){
                cout<<"x";
            }
            else{
                std::cout<<board.getBoard()[i][j];
            }
        }
        std::cout<<std::endl;
    }
}

std::pair<std::string,int> View::configure()
{
    cout<<"Enter your nickname"<<endl;
    std::string nickname;
    cin>>nickname;
    int level;
    cin >> level;
    cout<<"Choose your level"<<endl;
    return std::make_pair(nickname,level);
}

void View::gameOver()
{
    cout<<"Game Over"<<endl;
    //print player data
}
