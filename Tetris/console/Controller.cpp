#include "Controller.h"
#include "View.h"
#include "iostream"

void Controller::start()
{
    View::welcome();
    std::tuple<std::string, int,bool> configuration {View::configure()};
    facade_ = std::make_unique<Facade>(std::get<0>(configuration),std::get<1>(configuration));
    if(std::get<2>(configuration)){
        facade_->game()->board()->randomize();
    }
    facade_->addObserver(shared_from_this());
    update();
    while(!this->facade_->isGameOver()){
        View::showStats(std::get<0>(configuration), std::get<1>(configuration), facade_->getScore(), facade_->getLinesCompleted());
        auto userAction {View::askAction()};
        if(userAction == "r"){
           facade_->translation(StaticDirections::RIGHT);
        }
        else if(userAction == "l"){
           facade_->translation(StaticDirections::LEFT);
        }
        else if(userAction == "d"){
           facade_->translation(StaticDirections::DOWN);

        }
        else if(userAction == "drop"){
           facade_->drop();

        }
        else if(userAction == "exit"){
           facade_->end();

        }
        else if(userAction == "rl"){
           facade_->rotation(false);

        }
        else if(userAction == "rr"){
           facade_->rotation(true);
        }
        else{
           std::cout<<"input not recognized"<<std::endl;
        }
    }
}

void Controller::update()
{
    if(!this->facade_->isGameOver()){
        auto board {facade_->game()->board()};
        auto brickDetails {facade_->game()->getBrickDetails()};
        View::display(*board,brickDetails.first,brickDetails.second);
    }
    else{
        View::gameOver();
    }
}
