#include "backgroundgui.h"

#include <QListView>
#include <QPalette>


BackgroundGUI::BackgroundGUI()
{
    QPixmap pixmap;
    pixmap.load(":/pictures/grass_256");
    setTexture(pixmap);
}
