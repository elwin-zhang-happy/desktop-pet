//
// Created by ElwinZhang on 2024/10/3.
//

#include "DrinkTea.h"

#include <QPainter>


DrinkTea::DrinkTea() { setPicNum(6); }

/**
 * 播放声音
 * @param indexSound 声音索引
 */
void DrinkTea::playSound(int indexSound) {}

/**
 * 绘制图片
 * @param painter 绘制设备
 * @param indexPic  图片索引
 */
void DrinkTea::showAction(QPainter &painter, int indexPic) {
    const QString path = QString(":/images/resources/drink_tea/drink_%1.png").arg(indexPic);
    QPixmap pixmap(path);
    painter.drawPixmap(0, 0, pixmap);
}

/**
 * 重置索引
 */
void DrinkTea::resetIndex(){
    this->indexPic = 0;
}
