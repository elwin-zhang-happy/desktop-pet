//
// Created by ElwinZhang on 2024/9/16.
//

#include "IdleState.h"

IdleState::IdleState() {
    setPicNum(10);
}
/**
 * 播放声音，暂无
 */
void IdleState::playSound(int indexSound) {
}

/**
 * 绘制图片
 * @param painter 图片绘制
 */
void IdleState::showAction(QPainter &painter, int indexPic) {

    const QString path = QString(":/images/resources/idle/idle_%1.png").arg(indexPic);
    QPixmap pixmap(path);

    painter.drawPixmap(0, 0, pixmap);
}
