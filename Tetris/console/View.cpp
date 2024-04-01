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
            for (int var = 0; var < v.size(); ++var) {
                if(i == v[var].get_x() && j == v[var].get_y()){
                    cout<<"x";
                    v.erase(v.begin()+var);
                    break;
                }
            }
            if(board.getBoard()[i][j]){
                cout<<"o";
            }
            else{
                 cout<<"_";
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
std::string View::askAction()
{
    std::string action;
    cin>>action;
    return action;
}
