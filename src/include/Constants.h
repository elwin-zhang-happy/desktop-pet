//
// Created by ElwinZhang on 2024/9/16.
//

#ifndef CONSTANTS_H
#define CONSTANTS_H

// 桌宠可操作状态枚举
enum class PetState {
    IDLE, // 闲时
    DRAG, // 拖拽中
    EXIT, // 退出
    DRINK_TEA, // 喝茶
};

enum class ClickType {
    DOUBLE, // 双击
    SINGLE, // 单击
    CLOSE, // 退出
    NONE,  // 无
};

enum class StateType {
    LOOP, // 循环展示
    PRE, // 前置动作
};

namespace Constants {
    // 定时器间隔,刷新频率
    constexpr int timerInterval = 500;
    constexpr int width = 180;
    constexpr int height = 180;
    constexpr int mousePressInterval = 200;
}


#endif //CONSTANTS_H
