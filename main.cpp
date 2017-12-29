#include <QApplication>

#include "map.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    QApplication a(argc, argv);

    Map::getInstance();

    return a.exec();
}



