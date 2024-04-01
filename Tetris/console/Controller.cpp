#include "Controller.h"
#include "view.h"
#include "Observer.h"

void Controller::start()
{
    View::welcome();
    std::pair<std::string, int> configuration {View::configure()};
    std::cout << "bnb" << std::endl;
    facade_ = std::make_unique<Facade>(configuration.first,configuration.second);
    std::cout << "aa" << std::endl;
    // this->facade_->addObserver(std::make_shared<Controller>(this));
    facade_->addObserver(shared_from_this());
    std::cout << "xx" << std::endl;
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
