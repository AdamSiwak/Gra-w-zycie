#include <QtTest>
#include <QCoreApplication>
#include <cstdlib>
#include <ctime>

#include "../../predator.h"

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

QTEST_MAIN(Gra_w_zycie_test)

#include "tst_gra_w_zycie_test.moc"
