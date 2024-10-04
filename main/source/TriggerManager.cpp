//
// Created by ElwinZhang on 2024/9/16.
//

#include "TriggerManager.h"
#include <Majorwindow.h>


TriggerManager::TriggerManager(QWidget *parent): parent(parent),
        idleState(std::make_unique<IdleState>()),
        dragState(std::make_unique<DragState>()),
        exitState(std::make_unique<ExitState>()),
        drinkTea(std::make_unique<DrinkTea>())
        {
     // do nothing
}


/**
 * 绘制图片
 * @param painter 图片绘制
 */
void TriggerManager::showAction(StateType stateType,QPainter &painter, PetState pre, PetState major) {
    if (StateType::PRE == stateType) {
        preShowAction(painter, pre, major);
    } else if (StateType::LOOP == stateType) {
        showLoopDisplay(painter, major);
    }
}

/**
 * 播放声音
 */
void TriggerManager::playSound() {}

/**
 * 前置插入绘图状态
 * @param painter 绘制设备
 * @param pre 前置插入状态
 * @param major 主体状态
 */
void TriggerManager::preShowAction(QPainter &painter, PetState pre, PetState major) {
    if (PetState::DRINK_TEA == pre) {
        bool firstRound = drinkTea->showPicOneRound(painter);
        if (firstRound) {
            showLoopDisplay(painter, major);
        }
    }
}

/**
 * 循环展示图片
 * @param painter 绘制设备
 * @param state 状态
 */
void TriggerManager::showLoopDisplay(QPainter &painter, PetState state) {
    if (state == PetState::IDLE) {
        idleState->showPic(painter);
    } else if (state == PetState::DRAG) {
        dragState->showPic(painter);
    } else if (state == PetState::EXIT) {
        exitState->showPic(painter);
    }
}

/**
 * 恢复状态索引
 * @param state 状态
 */
void TriggerManager::resetPetState(PetState state){
    if (PetState::DRINK_TEA == state) {
        drinkTea->resetIndex();
    }

}



