#ifndef SOUND_H
#define SOUND_H
#include <QMediaPlayer>

enum mySound{PRAY_SOUND, PREDATOR_SOUND, BACKGROUND};
class Sound : public QMediaPlayer
{
public:
    Sound(mySound sound);
};

#endif // SOUND_H
