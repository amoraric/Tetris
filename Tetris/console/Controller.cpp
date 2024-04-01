#include "Controller.h"
#include "view.h"

void Controller::start()
{
    View::welcome();
    auto configuration {View::configure()};
    facade_ = std::make_unique<Facade>(configuration.first,configuration.second);
    this->facade_->addObserver(std::make_shared<Observer>(this));
    while(!this->facade_->isGameOver()){
       auto userAction {View::askAction()};
       if(userAction == "r"){
           facade_->translation(StaticDirections::RIGHT);
       }
       if(userAction == "l"){
           facade_->translation(StaticDirections::LEFT);
       }
       if(userAction == "d"){
           facade_->translation(StaticDirections::DOWN);

       }
       if(userAction == "drop"){
           facade_->drop();

       }
       if(userAction == "exit"){
           facade_->end();

       }
       if(userAction == "rl"){
           facade_->rotation(false);

       }
       if(userAction == "rr"){
           facade_->rotation(true);
       }
       else{
           std::cout<<"input not recognized"<<std::endl;
       }
}
}

void Controller::update()
{
    auto board {facade_->game()->board()};
    auto brickDetails {facade_->game()->getBrickDetails()};
    View::display(*board,brickDetails.first,brickDetails.second);
}
