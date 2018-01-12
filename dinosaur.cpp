#include "dinosaur.h"
#include "map.h"

#include <QDebug>
#include <QTimer>


Dinosaur::Dinosaur() : age_(0), maxHunger_(minMaxHunger + rand()%(maxMaxHunger-minMaxHunger)), hunger_(rand()%maxHunger()), thirst_(rand()%maxThirst) {
    // TODO: zmienic kolejnosc w liscie inicjalizacyjnej
    // TODO: ograniczenia jednych parametrów względem innych

    speed_=rand() % (maxSpeed - minSpeed) + minSpeed;
    currentDestination_ = new Coordinates();
    currentDestination_->setRandomCoordiantes();
}


//Dinosaur::Dinosaur() {

//}

void Dinosaur::stepRight(){
    if(!gui_->isSelected()){
        gui_->stepRight();
        energyBurning();
    }
}
void Dinosaur::stepLeft(){
    if(!gui_->isSelected()){
        gui_->stepLeft();
        energyBurning();
    }
}
void Dinosaur::stepUp(){
    if(!gui_->isSelected()){
        gui_->stepUp();
        energyBurning();
    }
}
void Dinosaur::stepDown(){
    if(!gui_->isSelected()){
        gui_->stepDown();
        energyBurning();
    }
}

void Dinosaur::move2position(int x, int y)
{
    for(int i=0; i<speed(); ++i){
        if (x<gui_->position_->getXcoordinate()){
            stepLeft();
        }
        else if (x>gui_->position_->getXcoordinate()){
            stepRight();
        }
        if(y<gui_->position_->getYcoordinate()){
            stepUp();
        }
        else if(y>gui_->position_->getYcoordinate()){
            stepDown();
        }
    }
}

void Dinosaur::showMyStatistics()
{

    if (gui_->isSelected()){
        //qDebug()<<toString();
        gui_->cloud_->writeText(toString());
        gui_->cloud_->setX(gui_->x());
        gui_->cloud_->setY(gui_->y());
        gui_->cloud_->setVisible(true);
    }
    else{
        gui_->cloud_->setVisible(false);
    }
}

int Dinosaur::getReproductiveAge()
{
    return reproductiveAge;
}

bool Dinosaur::cased() const
{
    return cased_;
}

void Dinosaur::setCased(bool cased)
{
    cased_ = cased;
}

Dinosaur::behaviourStates Dinosaur::behaviourState() const
{
    return behaviourState_;
}

void Dinosaur::setBehaviourState(const behaviourStates &behaviourState)
{
    behaviourState_ = behaviourState;
}

void Dinosaur::drawLotsPosition()
{
    currentDestination_->setRandomCoordiantes();
}

void Dinosaur::energyBurning(){
    hunger_--;
    thirst_--;
}

Dinosaur::behaviourStates Dinosaur::eating()
{
    if(hunger()<maxHunger()){
        hunger_++;
        return EATING;
    }
    else{
        return FULL;
    }
}

Dinosaur::behaviourStates Dinosaur::drinking()
{
    gui_->beginDrinking();
    if(thirst()<0.8*maxThirst){
        thirst_+=10;

        return DRINKING;
    }
    else{
        return DRUNK;
    }
}

void Dinosaur::behaviour()
{

    age_++;
    showMyStatistics();

    switch (needs_) {
    case WANT2DRINK:
        switch (behaviourState_) {
        case SERCH4LAKE:
            target_ = Map::getInstance()->getNearestLake(*this);
            behaviourState_ = GO2LAKE;
            break;
        case GO2LAKE:
            move2position(target_->position_->getXcoordinate(),target_->position_->getYcoordinate());
            if(*target_->position_==*position_){
                behaviourState_ = DRINKING;
            }
            break;
        case DRINKING:
            behaviourState_ = drinking();
            break;
        case DRUNK:
            //do nothing
            break;
        default:
            behaviourState_ = SERCH4LAKE;
            break;
        }
        break;
    case WANT2EAT:
        switch (behaviourState_){
            case SERCH4EATING:
                behaviourState_ = findTheNearestEating();
            break;
            case GO2EATING:
                behaviourState_ = go2eating();
                break;
            case EATING:
                behaviourState_ = eating();
                break;
            case FULL:
                //do nothing
                break;
            default:
                behaviourState_ = SERCH4EATING;
                break;
        }
        break;
    case WANT2REPRODUCE:
        switch (behaviourState_) {
            case SERCH4PARTNER:
                behaviourState_ = findPartner();
                break;
            case GO2PARTNER:
                move2position(target_dino_->gui_->position_->getXcoordinate(),target_dino_->gui_->position_->getYcoordinate());
                if(*target_dino_->position_ == *position_){
                    behaviourState_ = REPRODUCING;
                }
                break;
            case REPRODUCING:
                reproducing();
                break;
            default:
                behaviourState_ = SERCH4PARTNER;
                break;
        }

    case DONT_HAVE_ANY_NEEDS:
        if(*currentDestination_== *gui_->position_){
            drawLotsPosition();
        }
        else{
            move2position(currentDestination_->getXcoordinate(),currentDestination_->getYcoordinate());
        }
        break;
    default:
        break;
    }

//    age_++;
//    showMyStatistics();

//    if(thirst()<criticalThirst || behaviourState_ == DRINKING){
//        go2nearestLake();
//        if(*target_->position_ == *gui_->position_ ){
//            behaviourState_=drinking();
//        }
//    }
//    else if(hunger()<criticalHunger){
//        go2nearestEating();
//    }
//    else if(age()>reproductiveAge){
//        go2Partner();
//    }
//    else {
//        if(*currentDestination_== *gui_->position_){
//            drawLotsPosition();

//        }
//        else{
//            move2position(currentDestination_->getXcoordinate(),currentDestination_->getYcoordinate());

//        }
//    }

}

QString Dinosaur::toString()
{
    QString str;

    str = " Age = " + QString::number(age()) +
          " Thirst = " + QString::number(thirst()) + "," +
          " Hunger = " + QString::number(hunger()) + "," +
          " Speed = " + QString::number(speed()) + ",";

    return str;
}

void Dinosaur::toDie()
{
   // ~Dinosaur();
}

void Dinosaur::makeADecision()
{
    if(age()>maxAge){
        needs_ = IS2OLD;
    }
//    else if(cased()){ // TODO: impementacja w predator eating
//        needs_ = IS_DANGERED;
//    }
    else if(thirst()<criticalThirst || behaviourState_ == DRINKING){
        needs_ = WANT2DRINK;
    }
    else if(hunger()<criticalHunger || behaviourState_ == EATING){
        needs_ = WANT2EAT;
    }
    else if(age()>reproductiveAge || behaviourState_ == REPRODUCING){
        needs_ = WANT2REPRODUCE;
    }
    else {
        needs_ = DONT_HAVE_ANY_NEEDS;
    }
}
