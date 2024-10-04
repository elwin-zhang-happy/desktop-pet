//
// Created by ElwinZhang on 2024/10/1.
//

#include "DragState.h"
#include <QPainter>

DragState::DragState() {
    // 设置总图片数量
    setPicNum(3);
}
/**
 * 播放声音
 */
void DragState::playSound(int indexSound) {}

/**
 * 播放图片
 * @param painter 图片绘制
 * @param indexPic 图片索引
 */
void DragState::showAction(QPainter &painter, int indexPic){
    // 初始化图片
    const QString path = QString(":/images/resources/drag/drag_%1.png").arg(indexPic);
    QPixmap pixmap(path);

    painter.drawPixmap(0, 0, pixmap);
}

