//
// Created by ElwinZhang on 2024/10/3.
//

#ifndef DRINKTEA_H
#define DRINKTEA_H

#include "State.h"

class DrinkTea : public State{

public:
    DrinkTea();
    ~DrinkTea() override = default;

    void playSound(int indexSound) override;
    void showAction(QPainter &painter, int indexPic) override;
    // 重置索引
    void resetIndex();
};



#endif //DRINKTEA_H
