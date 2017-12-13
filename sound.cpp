#include "sound.h"

#include <QMediaPlaylist>

Sound::Sound(mySound sound)
{
    switch(sound){
    case PRAY_SOUND:
        setMedia(QUrl("qrc:/sounds/prey.wav"));
        break;

    case PREDATOR_SOUND:
        setMedia(QUrl("qrc:/sounds/predator.wav"));
        break;

    case BACKGROUND:
        QMediaPlaylist *playlist = new QMediaPlaylist();
        playlist->addMedia(QUrl("qrc:/sounds/music.wav"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        setPlaylist(playlist);

        break;
    }
}






