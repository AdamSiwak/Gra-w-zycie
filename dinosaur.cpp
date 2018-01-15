#include "dinosaur.h"
#include "map.h"

#include <QDebug>
#include <QTimer>


Dinosaur::Dinosaur() : age_(0), thirst_(rand()%maxThirst) {
    isDevoured_ = false;
    chased_ = false;
    behaviourState_ = OTHER;
    prevBehaviourState_ = OTHER;
    prevNeeds_ = DONT_HAVE_ANY_NEEDS;
    needs_ = DONT_HAVE_ANY_NEEDS;
    speed_=rand() % (maxSpeed - minSpeed) + minSpeed; // speed in range
    maxHunger_ = static_cast<int>((multiplier*7)/speed_);
    hunger_ = rand()%maxHunger_;
    criticalHunger_ = 0.5* maxHunger_;
    currentDestination_ = Coordinates_sharedPtr(new Coordinates());
    currentDestination_->setRandomCoordiantes();
    iAmHiddenByTime_ = 0;
}


Dinosaur::Dinosaur(Dinosaur &parent1, Dinosaur &parent2) {
    isDevoured_ = false;
    chased_ = false;
    behaviourState_ = OTHER;
    age_ = 0;
    speed_ = static_cast<int>((parent1.speed_ + parent2.speed_)/2);
    maxHunger_ = static_cast<int>((multiplier*7)/speed_);
    hunger_ = rand()%maxHunger_;
    criticalHunger_ = 0.5* maxHunger_;
    thirst_ = rand()%maxThirst;
    currentDestination_ = Coordinates_sharedPtr(new Coordinates());
    currentDestination_->setRandomCoordiantes();
    iAmHiddenByTime_ = 0;
}

void Dinosaur::stepRight(){
    if(!gui_->isSelected()){
        gui_->stepRight();
    }
}
void Dinosaur::stepLeft(){
    if(!gui_->isSelected()){
        gui_->stepLeft();
    }
}
void Dinosaur::stepUp(){
    if(!gui_->isSelected()){
        gui_->stepUp();
    }
}
void Dinosaur::stepDown(){
    if(!gui_->isSelected()){
        gui_->stepDown();
    }
}

void Dinosaur::move2position(int x, int y)
{
    setIsHiden(false);
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
           gui_->cloud_->writeText("behaviourStates: " + QString::number(behaviourState_) + ",dinosaurNeeds: " + QString::number(needs_)
                                   + ", hiden: "+ QString::number(getIsHiden()) + ", eat: " + QString::number(hunger_));
           gui_->cloud_->setX(gui_->x());
           gui_->cloud_->setY(gui_->y());
           gui_->cloud_->setVisible(true);
//    if (gui_->isSelected()){
//        gui_->cloud_->writeText(toString());
//        gui_->cloud_->setX(gui_->x());
//        gui_->cloud_->setY(gui_->y());
//        gui_->cloud_->setVisible(true);
//    }
//    else{
//        gui_->cloud_->setVisible(false);
//    }
}

int Dinosaur::getIAmHiddenByTime() const
{
    return iAmHiddenByTime_;
}

void Dinosaur::setIAmHiddenByTime(int iAmHiddenByTime)
{
    iAmHiddenByTime_ = iAmHiddenByTime;
}

bool Dinosaur::getIsHiden() const
{
    return isHiden_;
}

void Dinosaur::setIsHiden(bool isHiden)
{
    if(isHiden){
        gui_->setOpacity(0.5);
    }
    else{
        gui_->setOpacity(1);
    }
    isHiden_ = isHiden;
}

bool Dinosaur::getIsDevoured() const
{
    return isDevoured_;
}

void Dinosaur::setIsDevoured(bool value)
{
    isDevoured_ = value;
}

void Dinosaur::findCave()
{
    target_ = Map::getInstance()->getNearestCave(*this);
}

void Dinosaur::isDevoured()
{
    gui_->setRotation(180);
    gui_->setTransformOriginPoint(20,50);
}

int Dinosaur::getReproductiveAge()
{
    return reproductiveAge;
}

bool Dinosaur::chased() const
{
    return chased_;
}

void Dinosaur::setChased(bool chased)
{
    chased_ = chased;
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
    if(thirst()<maxThirst){
        thirst_+=100;
        return DRINKING;
    }
    else{
        return DRUNK;
    }
}

void Dinosaur::behaviour()
{

    ++age_;
    energyBurning();
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
            behaviourState_ = OTHER;
            needs_ = DONT_HAVE_ANY_NEEDS;
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
                behaviourState_ = OTHER;
                needs_ = DONT_HAVE_ANY_NEEDS;
                if(target_dino_!=nullptr){
                    target_dino_->setChased(false);
                    target_dino_->setIsDevoured(false);
                    target_dino_ = nullptr;
                }
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
                behaviourState_ = reproducing();
                target_dino_ = nullptr;
                break;
            default:
                behaviourState_ = SERCH4PARTNER;
                break;
        }
        break;
    case IS_DANGERED:
        switch (behaviourState_) {
            case SERCH4CAVE:
                findCave();
                behaviourState_= GO2CAVE;
                break;
            case GO2CAVE:
                move2position(target_->position_->getXcoordinate(),target_->position_->getYcoordinate());
                if(*target_->position_ == *position_){
                    behaviourState_ = HIDING;
                    setIsHiden(true);
                }
                break;
            case HIDING:
                // do nothing
                break;
            case IS_DEVOURED:
                isDevoured();
                break;
            default:
                behaviourState_=SERCH4CAVE;
                break;
            }
            break;
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

void Dinosaur::makeADecision()
{
    if(age_>maxAge_){
        needs_ = IS2OLD;
    }
    else if(chased() || getIsDevoured()){
        needs_ = IS_DANGERED;
    }
    else if(thirst_<criticalThirst || behaviourState_ == DRINKING){
        needs_ = WANT2DRINK;
    }
    else if(hunger_<criticalHunger_ || behaviourState_ == EATING){
        needs_ = WANT2EAT;
    }
    else if(age_>reproductiveAge || behaviourState_ == REPRODUCING){
        needs_ = WANT2REPRODUCE;
    }
    else {
        needs_ = DONT_HAVE_ANY_NEEDS;
    }

    if (needs_ != prevNeeds_) {
        target_dino_ = nullptr;
        target_ = nullptr;
    }

    prevNeeds_ = needs_;
}
