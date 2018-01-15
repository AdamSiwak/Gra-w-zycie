#ifndef CLOUD_H
#define CLOUD_H

//author: Andrzej Dzwinski

#include "objectgui.h"

/**
 * @brief The Cloud class
 */
class Cloud : public ObjectGUI
{
public:
    /**
     * @brief Cloud constructor
     * @param picture
     * @param scale
     */
    Cloud(QString picture, const qreal scale);
    /**
     * @brief writeText is mathod for writing text na the cloud. When you write "," (comma) it means new line
     * @param s - input string
     */
    void writeText(QString s);
private:
    QPixmap_sharedPtr pixmap_;
};

typedef boost::shared_ptr<Cloud> Cloud_sharedPtr;
typedef boost::weak_ptr<Cloud> Cloud_weakPtr;

#endif // CLOUD_H
