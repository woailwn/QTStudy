#include "getalbuming.h"

GetAlbuming::GetAlbuming(QObject *parent)
    : QObject{parent}
{
    player=new QMediaPlayer(this);
    connect(player,&QMediaPlayer::mediaStatusChanged,this,&GetAlbuming::onMediaStatusChanged);
}
