//
// Created by ElwinZhang on 2024/10/2.
//

#ifndef EXITSTATE_H
#define EXITSTATE_H

#include "State.h"

class ExitState : public State{

public:
    ExitState();
    ~ExitState() override = default;

    void showAction(QPainter &painter, int indexPic) override;
    void playSound(int indexSound) override;

private:
    // 是否处于退出状态
    bool exiting;
};



#endif //EXITSTATE_H
