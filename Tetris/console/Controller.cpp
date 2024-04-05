#include "Controller.h"
#include "View.h"
#include "iostream"

void Controller::start()
{
    View::welcome();
    std::tuple<std::string, int,bool, int, int> configuration_ {View::configure()};
    std::string nickname_ = std::get<0>(configuration_);
    int level_ = std::get<1>(configuration_);
    facade_ = std::make_unique<Facade>(std::get<0>(configuration_),std::get<1>(configuration_), std::get<3>(configuration_), std::get<4>(configuration_));
    if(std::get<2>(configuration_)){
        facade_->game()->board()->randomize();
    }
    facade_->addObserver(shared_from_this());
    update();
    while(!this->facade_->isGameOver()){
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
           std::cout<<"Input not recognized"<<std::endl;
        }
    }
}

void Controller::update()
{
    auto board {facade_->game()->board()};
    auto brickDetails {facade_->game()->getBrickDetails()};
    View::display(*board,brickDetails.first,brickDetails.second);
    if(!this->facade_->isGameOver()){
        View::showStats(nickname_, level_, facade_->getScore(), facade_->getLinesCompleted());
    }
    else{
        View::gameOver();
    }
}
