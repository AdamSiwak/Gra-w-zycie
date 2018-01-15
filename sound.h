#ifndef SOUND_H
#define SOUND_H

//author: Andrzej Dzwinski

#include <QMediaPlayer>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>


/**
 * @brief The mySound enum
 */

enum mySound{PRAY_SOUND, PREDATOR_SOUND, BACKGROUND};

/**
 * @brief The Sound class
 */
class Sound : public QMediaPlayer
{
public:
    /**
     * @brief Sound constructor
     * @param sound
     */
    Sound(mySound sound);
};

typedef boost::shared_ptr<Sound> Sound_sharedPtr;

#endif // SOUND_H
