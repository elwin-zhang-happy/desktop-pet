//
// Created by ElwinZhang on 2024/10/10.
//

#ifndef CRYSTATE_H
#define CRYSTATE_H

#include "State.h"

class CryState: public State {

public:
    CryState();
    ~CryState() override = default;

    void playSound(int indexSound) override;
    void showAction(QPainter &painter, int indexPic) override;
};



#endif //CRYSTATE_H
