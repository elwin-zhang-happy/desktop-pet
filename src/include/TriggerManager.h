//
// Created by ElwinZhang on 2024/9/16.
//

#ifndef TRIGGERMANAGER_H
#define TRIGGERMANAGER_H

#include "Constants.h"
#include "DragState.h"
#include "DrinkTea.h"
#include "ExitState.h"
#include "IdleState.h"

class MajorWindow;

class TriggerManager {

public:
    explicit TriggerManager(QWidget *parent = nullptr);
    virtual ~TriggerManager() = default;

private:
    QWidget *parent;

public:
    // 展示图片
    void showAction(StateType stateType,QPainter &painter, PetState pre, PetState major);
    // 展示声音
    void playSound();
    // 正常执行前插入执行
    void preShowAction(QPainter &painter, PetState pre, PetState major);
    // 循环展示
    void showLoopDisplay(QPainter &painter, PetState state);
    // 重置状态，恢复到初始索引
    void resetPetState(PetState state);

private:
    // 空闲状态
    std::unique_ptr<IdleState> idleState;
    // 拖拽状态
    std::unique_ptr<DragState> dragState;
    // 退出状态
    std::unique_ptr<ExitState> exitState;
    // 喝茶状态
    std::unique_ptr<DrinkTea> drinkTea;
};


#endif // TRIGGERMANAGER_H
