#ifndef CLOUD_H
#define CLOUD_H
#include "objectgui.h"


class Cloud : public ObjectGUI
{
public:
    Cloud(QString picture, const qreal scale);
    void writeText(QString s);
private:
    QPixmap_sharedPtr pixmap_;
};

typedef boost::shared_ptr<Cloud> Cloud_sharedPtr;
typedef boost::weak_ptr<Cloud> Cloud_weakPtr;

#endif // CLOUD_H
