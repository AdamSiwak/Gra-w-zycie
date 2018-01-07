#include <QtTest>
#include <QCoreApplication>
#include <cstdlib>
#include <ctime>

#include "../../predator.h"
#include "../../map.h"
#include "../../coordinates.h"
#include "../../map.h"

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
//    void move2position_should_move_only_one_step_in_destination_direction();
    void test_reproduce();
    void getNearestLake_should_return_coordinates_of_nearest_lake();
    void call_isEqual_oprator_for_Coorginates_should_return_true_if_both_coordinates_are_same_and_false_otherwise();
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

//void Gra_w_zycie_test::move2position_should_move_only_one_step_in_destination_direction()
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

void Gra_w_zycie_test::test_reproduce()
{
    Predator parent1, parent2;
    Predator* child = parent1.reproduce(parent2);

    QTRY_VERIFY(child != nullptr);
    QCOMPARE(child->age(),0);
    QTRY_VERIFY(child->speed() !=parent1.speed());
    QCOMPARE(child->hunger(),0);
    QTRY_VERIFY(child->maxHunger() != parent1.maxHunger());
    QCOMPARE(child->thirst(),0);

    delete child;
}

void Gra_w_zycie_test::getNearestLake_should_return_coordinates_of_nearest_lake()
{
    //Arrange
    Lake* lake;
    Predator* dino = new Predator();
    dino->gui_->position_->setXcoordinate(0);
    dino->gui_->position_->setYcoordinate(0);
    Map::getInstance()->createLakes(2);
    Map::getInstance()->getLakes()[0]->position_->setXcoordinate(15);
    Map::getInstance()->getLakes()[0]->position_->setYcoordinate(15);
    Map::getInstance()->getLakes()[1]->position_->setXcoordinate(150);
    Map::getInstance()->getLakes()[1]->position_->setYcoordinate(150);
    //Act
    lake = Map::getInstance()->getNearestLake(dino);
    //Assert
    QCOMPARE(lake->position_->getXcoordinate(),15);
    QCOMPARE(lake->position_->getYcoordinate(),15);
}

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

    QVERIFY(coords1 == coords2);

}

QTEST_MAIN(Gra_w_zycie_test)

#include "tst_gra_w_zycie_test.moc"
