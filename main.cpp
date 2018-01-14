#include <QApplication>

#include "map.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Map::getInstance()->startAnimation();

    return a.exec();
}



