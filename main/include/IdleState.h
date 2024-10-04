//
// Created by ElwinZhang on 2024/9/16.
//

#ifndef IDLESTATE_H
#define IDLESTATE_H
#include <QPainter>
#include <State.h>

class IdleState : public State{

public:
    IdleState();
    ~IdleState() override = default;

    // 播放声音
    void playSound(int indexSound) override;
    // 播放动作
    void showAction(QPainter &painter, int indexPic) override;

};



#endif //IDLESTATE_H
