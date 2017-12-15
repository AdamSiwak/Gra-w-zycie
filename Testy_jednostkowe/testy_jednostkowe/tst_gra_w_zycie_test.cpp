#include <QtTest>
#include <QCoreApplication>
#include <cstdlib>
#include <ctime>

#include "../../predator.h"
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
    void test_move();
    void test_reproduce();

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

void Gra_w_zycie_test::test_move()
{
    Predator p;
    int x = p.x();
    int y = p.y();

    p.move();

    QTRY_VERIFY(x != p.x());
    QTRY_VERIFY(y != p.y());
}

void Gra_w_zycie_test::test_reproduce()
{
    Predator parent1, parent2;
    Predator* child = parent1.reproduce(parent2);

    QTRY_VERIFY(child != nullptr);
    QTRY_VERIFY(child->age() == 0);
    QTRY_VERIFY(child->maxEnergy() != parent1.maxEnergy());
    QTRY_VERIFY(child->energy() == 100);
    QTRY_VERIFY(child->speed() != parent1.speed());
    QTRY_VERIFY(child->sightRange() != parent1.sightRange());
    QTRY_VERIFY(child->sightAngle() != parent1.sightAngle());
    QTRY_VERIFY(child->hunger() == 0);
    QTRY_VERIFY(child->maxHunger() != parent1.maxHunger());
    QTRY_VERIFY(child->thirst() == 0);

    delete child;
}

QTEST_MAIN(Gra_w_zycie_test)

#include "tst_gra_w_zycie_test.moc"
