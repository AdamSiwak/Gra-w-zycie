#include <QtTest>
#include <QCoreApplication>
#include <cstdlib>
#include <ctime>

#include "../../predator.h"
#include "../../map.h"
#include "../../coordinates.h"

// add necessary includes here

class Gra_w_zycie_test : public QObject
{
    Q_OBJECT

public:
    Gra_w_zycie_test();
    ~Gra_w_zycie_test();

private slots:
    void initTestCase();
    void cleanupTestCase();

    /////// MAP TESTS //////
    void map_getInstance_should_create_new_instance();
    void map_getInstance_shouldnt_create_new_instance_if_already_created();
    void map_addNewLake_should_add_lake_with_random_coordinates_to_collection();
    void map_addNewTree_should_add_tree_with_random_coordinates_to_collection();
    void map_addNewCave_should_add_cave_with_random_coordinates_to_collection();
    void map_addNewPredator_should_add_predator_with_random_coordinates_and_attributes_to_collection();
    void map_addNewPrey_should_add_prey_with_random_coordinates_and_attributes_to_collection();
    void map_deleteAllObjects_should_delete_all_objects();
    void map_createPreysPopulation_should_add_n_preys_with_random_coordinates_and_attributes_to_collection();
    void map_createPredatorsPopulation_should_add_n_predators_with_random_coordinates_and_attributes_to_collection();
    void map_createCaves_should_add_n_caves_with_random_coordinates_to_collection();
    void map_createLakes_should_add_n_lakes_with_random_coordinates_to_collection();
    void map_createTrees_should_add_n_trees_with_random_coordinates_to_collection();
    void map_getNearestLake_should_return_pointer_to_nearest_lake();
    void map_getNearestTree_should_return_pointer_to_nearest_tree();
    void map_getNearestCave_should_return_pointer_to_nearest_cave();
    void map_getNearestPredator_should_return_pointer_to_nearest_predator();
    void map_getNearestPrey_should_return_pointer_to_nearest_prey();
    void map_timerCallBack_should_update_position_of_dinosaurs();
    void map_timerCallBack_should_kill_too_old_dinosaurs();
    void map_timerCallBack_should_update_statistics_of_population(); // ewentualnie dodac kolejne testy przy zmianie funkcjonalnosci timerCallBack
    ////////////////////////

    //// DINOSAUR TESTS ////
//    void dinosaur_move2position_should_move_only_one_step_in_destination_direction();
    void dinosaur_test_reproduce();
    ////////////////////////

    //// COORDINATES TEST ////
    void call_isEqual_oprator_for_Coorginates_should_return_true_if_both_coordinates_are_same_and_false_otherwise();
    //////////////////////////
};


Gra_w_zycie_test::Gra_w_zycie_test()
{

}

Gra_w_zycie_test::~Gra_w_zycie_test()
{

}

void Gra_w_zycie_test::initTestCase()
{

}

void Gra_w_zycie_test::cleanupTestCase()
{

}


//////////////////// MAP TESTS ////////////////////

void Gra_w_zycie_test::map_getInstance_should_create_new_instance()
{
    Map* map = nullptr;

    map = Map::getInstance();

    QVERIFY(map != nullptr);
}

void Gra_w_zycie_test::map_getInstance_shouldnt_create_new_instance_if_already_created()
{
    Map* map = Map::getInstance();

    QCOMPARE(Map::getInstance(),map);
}

void Gra_w_zycie_test::map_addNewLake_should_add_lake_with_random_coordinates_to_collection()
{
    int size = Map::getInstance()->get_n_lakes();
    QCOMPARE(size,0);

    ObjectGUI_sharedPtr lake(new Lake("lake.png",0.5));
    Map::getInstance()->addNewLake(lake);

    QCOMPARE(size+1,Map::getInstance()->get_n_lakes());

    Map::getInstance()->deleteAllObjects();
}

void Gra_w_zycie_test::map_addNewTree_should_add_tree_with_random_coordinates_to_collection()
{
    int size = Map::getInstance()->get_n_trees();

    ObjectGUI_sharedPtr tree(new Tree("tree.png",0.5));
    Map::getInstance()->addNewTree(tree);

    QCOMPARE(size+1,Map::getInstance()->get_n_trees());

    Map::getInstance()->deleteAllObjects();
}

void Gra_w_zycie_test::map_addNewCave_should_add_cave_with_random_coordinates_to_collection()
{
    int size = Map::getInstance()->get_n_caves();

    ObjectGUI_sharedPtr cave(new Cave("cave.png",0.5));
    Map::getInstance()->addNewCave(cave);

    QCOMPARE(size+1,Map::getInstance()->get_n_caves());

    Map::getInstance()->deleteAllObjects();
}

void Gra_w_zycie_test::map_addNewPredator_should_add_predator_with_random_coordinates_and_attributes_to_collection()
{
    int size = Map::getInstance()->get_n_predators();

    Dinosaur_sharedPtr predator(new Predator());
    Map::getInstance()->addNewPredator(predator);

    QCOMPARE(size+1,Map::getInstance()->get_n_predators());

    Map::getInstance()->deleteAllObjects();
}

void Gra_w_zycie_test::map_addNewPrey_should_add_prey_with_random_coordinates_and_attributes_to_collection()
{
    int size = Map::getInstance()->get_n_preys();

    Dinosaur_sharedPtr prey(new Prey());
    Map::getInstance()->addNewPrey(prey);

    QCOMPARE(size+1,Map::getInstance()->get_n_preys());

    Map::getInstance()->deleteAllObjects();
}

void Gra_w_zycie_test::map_deleteAllObjects_should_delete_all_objects()
{
    ObjectGUI_sharedPtr lake(new Lake("lake.png",0.5));
    Map::getInstance()->addNewLake(lake);

    ObjectGUI_sharedPtr tree(new Tree("tree.png",0.5));
    Map::getInstance()->addNewTree(tree);

    ObjectGUI_sharedPtr cave(new Cave("cave.png",0.5));
    Map::getInstance()->addNewCave(cave);

    Dinosaur_sharedPtr predator(new Predator());
    Map::getInstance()->addNewPredator(predator);

    Dinosaur_sharedPtr prey(new Prey());
    Map::getInstance()->addNewPrey(prey);

    Map::getInstance()->deleteAllObjects();

    QCOMPARE(Map::getInstance()->get_n_lakes(),0);
    QCOMPARE(Map::getInstance()->get_n_trees(),0);
    QCOMPARE(Map::getInstance()->get_n_caves(),0);
    QCOMPARE(Map::getInstance()->get_n_predators(),0);
    QCOMPARE(Map::getInstance()->get_n_preys(),0);
}

void Gra_w_zycie_test::map_createPreysPopulation_should_add_n_preys_with_random_coordinates_and_attributes_to_collection()
{
    Map::getInstance()->createPreysPopulation(20);

    QCOMPARE(Map::getInstance()->get_n_preys(),20);

    Map::getInstance()->deleteAllObjects();
}

void Gra_w_zycie_test::map_createPredatorsPopulation_should_add_n_predators_with_random_coordinates_and_attributes_to_collection()
{
    Map::getInstance()->createPredatorsPopulation(30);

    QCOMPARE(Map::getInstance()->get_n_predators(),30);

    Map::getInstance()->deleteAllObjects();
}

void Gra_w_zycie_test::map_createCaves_should_add_n_caves_with_random_coordinates_to_collection()
{
    Map::getInstance()->createCaves(10);

    QCOMPARE(Map::getInstance()->get_n_caves(),10);

    Map::getInstance()->getCaves()[0]->position_->setXcoordinate(15);

    QCOMPARE( Map::getInstance()->getCaves()[0]->position_->getXcoordinate(),15);

    Map::getInstance()->deleteAllObjects();
}

void Gra_w_zycie_test::map_createLakes_should_add_n_lakes_with_random_coordinates_to_collection()
{
    Map::getInstance()->createLakes(50);

    QCOMPARE(Map::getInstance()->get_n_lakes(),50);

    Map::getInstance()->deleteAllObjects();
}

void Gra_w_zycie_test::map_createTrees_should_add_n_trees_with_random_coordinates_to_collection()
{
    Map::getInstance()->createTrees(10);

    QCOMPARE(Map::getInstance()->get_n_trees(),10);

    Map::getInstance()->deleteAllObjects();
}


void Gra_w_zycie_test::map_getNearestLake_should_return_pointer_to_nearest_lake()
{
    //Arrange

    Predator dino;
    dino.gui_->position_->setXcoordinate(0);
    dino.gui_->position_->setYcoordinate(0);
    Map::getInstance()->createLakes(2);
    Map::getInstance()->getLakes()[0]->position_->setXcoordinate(15);
    Map::getInstance()->getLakes()[0]->position_->setYcoordinate(15);
    Map::getInstance()->getLakes()[1]->position_->setXcoordinate(150);
    Map::getInstance()->getLakes()[1]->position_->setYcoordinate(150);
    //Act
    Lake_weakPtr lake = Map::getInstance()->getNearestLake(dino);
    //Assert
    QCOMPARE(lake.lock()->position_->getXcoordinate(),15);
    QCOMPARE(lake.lock()->position_->getYcoordinate(),15);

    Map::getInstance()->deleteAllObjects();
}

void Gra_w_zycie_test::map_getNearestTree_should_return_pointer_to_nearest_tree()
{

}

void Gra_w_zycie_test::map_getNearestCave_should_return_pointer_to_nearest_cave()
{

}

void Gra_w_zycie_test::map_getNearestPredator_should_return_pointer_to_nearest_predator()
{

}

void Gra_w_zycie_test::map_getNearestPrey_should_return_pointer_to_nearest_prey()
{

}

void Gra_w_zycie_test::map_timerCallBack_should_update_position_of_dinosaurs()
{

}

void Gra_w_zycie_test::map_timerCallBack_should_kill_too_old_dinosaurs()
{

}

void Gra_w_zycie_test::map_timerCallBack_should_update_statistics_of_population()
{

}

///////////////////////////////////////////////////


////////////////// DINOSAUR TESTS /////////////////

//void Gra_w_zycie_test::dinosaur_move2position_should_move_only_one_step_in_destination_direction()
//{
//    // Arrange
//    Predator p;
//    p.gui_->position_->setXcoordinate(100);
//    p.gui_->position_->setYcoordinate(100);
//    int x = 50;
//    int y = 50;
//    // Act
//    p.move2position(x, y);
//    // Assert
//    QCOMPARE(p.gui_->position_->getXcoordinate(), 99);
//    QCOMPARE(p.gui_->position_->getYcoordinate(), 99);
//}

void Gra_w_zycie_test::dinosaur_test_reproduce()
{
    Predator parent1, parent2;
    Predator_sharedPtr child = parent1.reproduce(parent2);

    QVERIFY(child != nullptr);
    QCOMPARE(child->age(),0);
    QVERIFY(child->speed() != parent1.speed());
    QCOMPARE(child->hunger(),0);
    QVERIFY(child->maxHunger() != parent1.maxHunger());
    QCOMPARE(child->thirst(),0);
}

///////////////////////////////////////////////////


//////////////// COORDINATES TESTS ////////////////

void Gra_w_zycie_test::call_isEqual_oprator_for_Coorginates_should_return_true_if_both_coordinates_are_same_and_false_otherwise()
{
    //Arrange
    Coordinates coords1;
    Coordinates coords2;
    Coordinates coords3;
    coords1.setXcoordinate(10);
    coords1.setYcoordinate(10);
    coords2.setXcoordinate(10);
    coords2.setYcoordinate(10);
    coords3.setXcoordinate(20);
    coords3.setYcoordinate(20);

    QVERIFY(coords1 == coords2);

    QVERIFY(coords1 != coords3);
}

///////////////////////////////////////////////////

QTEST_MAIN(Gra_w_zycie_test)

#include "tst_gra_w_zycie_test.moc"
