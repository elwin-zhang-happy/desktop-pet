//
// Created by ElwinZhang on 2024/10/1.
//

#ifndef DRAGSTATE_H
#define DRAGSTATE_H
#include "State.h"

/**
 * 拖拽状态
 */
class DragState: public  State{

public:
    DragState();
    ~DragState() override = default;

    // 播放声音
    void playSound(int indexSound) override;
    // 播放图片
    void showAction(QPainter &painter, int indexPic) override;
};



#endif //DRAGSTATE_H
