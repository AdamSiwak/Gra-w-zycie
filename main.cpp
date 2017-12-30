#include <QApplication>

#include "map.h"
#include "timer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Map::getInstance();

    return a.exec();
}



