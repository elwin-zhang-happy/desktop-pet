//
// Created by ElwinZhang on 2024/10/10.
//

#ifndef SINGSTATE_H
#define SINGSTATE_H

#include "State.h"

class SingState: public State{

public:
    SingState();
    ~SingState() override = default;

    void playSound(int indexSound) override;
    void showAction(QPainter &painter, int indexPic) override;
};



#endif //SINGSTATE_H
