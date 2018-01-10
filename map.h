#ifndef MAP_H
#define MAP_H

#include <QGraphicsScene>
#include <QTimer>
#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>

#include "vector"
#include "predator.h"
#include "timer.h"
#include "prey.h"
#include "tree.h"
#include "cave.h"
#include "lake.h"
#include "statictics_visitor.h"

typedef boost::shared_ptr<QGraphicsScene> QGraphicsScene_sharedPtr;
typedef boost::shared_ptr<QGraphicsView> QGraphicsView_sharedPtr;

class Map : public QObject
{ // singleton
    //Q_OBJECT
private:
    Map();
    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;
    ~Map(){}

    void showStatistics() {
        QMessageBox msgBox;
        msgBox.setText("Statistics");
        QString text = predatorsStatistics_.toString();
        text.append(preysStatistics_.toString());
        msgBox.setInformativeText(text);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
    }

    void keyPressEvent(QKeyEvent *event){
        if (event->key() == Qt::Key_Tab){
                showStatistics();
        }
    }

    static Map* instance_;
    std::vector<Dinosaur_sharedPtr> predators_;
    std::vector<Dinosaur_sharedPtr> preys_;
    std::vector<ObjectGUI_sharedPtr> caves_;
    std::vector<ObjectGUI_sharedPtr> lakes_;
    std::vector<ObjectGUI_sharedPtr> trees_;

    QGraphicsScene_sharedPtr scene_;
    QGraphicsView_sharedPtr view_;
    Sound_sharedPtr backgroundSound_;

    Timer_sharedPtr timer_;

    StatisticsVisitor predatorsStatistics_;
    StatisticsVisitor preysStatistics_;

    ObjectGUI_sharedPtr getNearestObject(Dinosaur& dino, std::vector<ObjectGUI_sharedPtr> object);
    Dinosaur_sharedPtr getNearestObject(Dinosaur& dino, std::vector<Dinosaur_sharedPtr> dinosurs);

public:
    static Map* getInstance(){
        if(!instance_) {
            instance_ = new Map();
        }
        return instance_;
    }

    void startAnimation();
    void stopAnimation();

    void addNewLake(ObjectGUI_sharedPtr object);
    void addNewTree(ObjectGUI_sharedPtr object);
    void addNewCave(ObjectGUI_sharedPtr object);
    void addNewPredator(Dinosaur_sharedPtr dinosaur);
    void addNewPrey(Dinosaur_sharedPtr dinosaur);

    void createPreysPopulation(int size);
    void createPredatorsPopulation(int size);
    void createCaves(int amount);
    void createLakes(int amount);
    void createTrees(int amount);

    void deleteAllObjects();

    int get_n_preys() { return preys_.size(); }
    int get_n_predators() { return predators_.size(); }
    int get_n_lakes() { return lakes_.size(); }
    int get_n_caves() { return caves_.size(); }
    int get_n_trees() { return trees_.size(); }

    Lake_weakPtr getNearestLake(Dinosaur& dino);
    Tree_weakPtr getNearestTree(Dinosaur& dino);
    Cave_weakPtr getNearestCave(Dinosaur& dino);
    Predator_weakPtr getNearestPredator(Dinosaur& dino);
    Prey_weakPtr getNearestPrey(Dinosaur& dino);

    std::vector<ObjectGUI_sharedPtr>& getLakes(){return lakes_;}
    std::vector<ObjectGUI_sharedPtr>& getTrees(){return trees_;}
    std::vector<ObjectGUI_sharedPtr>& getCaves(){return caves_;}
    std::vector<Dinosaur_sharedPtr>& getPredators(){return predators_;}
    std::vector<Dinosaur_sharedPtr>& getPreys(){return preys_;}

    void timerCallBack();

};

#endif // MAP_H
