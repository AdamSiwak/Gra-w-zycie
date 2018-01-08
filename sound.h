#ifndef SOUND_H
#define SOUND_H

#include <QMediaPlayer>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

enum mySound{PRAY_SOUND, PREDATOR_SOUND, BACKGROUND};
class Sound : public QMediaPlayer
{
public:
    Sound(mySound sound);
};

typedef boost::shared_ptr<Sound> Sound_sharedPtr;

#endif // SOUND_H
