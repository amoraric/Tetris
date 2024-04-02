#include "Controller.h"
#include "view.h"
#include "Observer.h"

void Controller::start()
{
    View::welcome();
    std::pair<std::string, int> configuration {View::configure()};
    facade_ = std::make_unique<Facade>(configuration.first,configuration.second);
    // this->facade_->addObserver(std::make_shared<Controller>(this));
    facade_->addObserver(shared_from_this());
    update();
    while(!this->facade_->isGameOver()){
        View::showStats(configuration.first, configuration.second, facade_->getScore(), facade_->getLinesCompleted());

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
