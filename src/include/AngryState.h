//
// Created by ElwinZhang on 2024/10/10.
//

#ifndef ANGRYSTATE_H
#define ANGRYSTATE_H

#include "State.h"

class AngryState: public State{

public:
    AngryState();
    ~AngryState() override = default;

    void playSound(int indexSound) override;
    void showAction(QPainter &painter, int indexPic) override;
};



#endif //ANGRYSTATE_H
