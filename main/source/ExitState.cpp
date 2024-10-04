//
// Created by ElwinZhang on 2024/10/2.
//

#include "ExitState.h"
#include "QPainter"


ExitState::ExitState(): exiting(false) {
    setPicNum(1);
}

/**
 * 播放声音
 * @param indexSound 声音索引
 */
void ExitState::playSound(int indexSound){
}

/**
 * 展示图片
 */
void ExitState::showAction(QPainter &painter, int indexPic) {
    const QString path = QString(":/images/resources/exit/exit_%1.png").arg(indexPic);
    QPixmap pixmap(path);

    painter.drawPixmap(0, 0, pixmap);
}


