//
// Created by ElwinZhang on 2024/9/17.
//

#ifndef STATE_H
#define STATE_H
#include <QTimer>
#include <QWidget>


class State{

public:
    State(): indexPic(0), indexSound(0), picNum(1) {};
    virtual ~State() = default;

    virtual void playSound(int indexSound) = 0;
    virtual void showAction(QPainter &painter, int indexPic) = 0;
    // 显示图片，统一接口
    void showPic(QPainter &painter);
    // 设置图片数量
    void setPicNum(int num);
    // 展示一轮图片后终止
    bool showPicOneRound(QPainter &painter);

protected:
    int indexPic;
    int indexSound;
private:
    int picNum;
};

/**
 * 带返回参数，判断是否绘制完一轮
 * @param painter 设备绘制
 * @return 是否
 */
inline bool State::showPicOneRound(QPainter &painter){
    if (indexPic >= picNum) {
        return true;
    }
    showAction(painter, indexPic);
    indexPic++;
    return indexPic == picNum-1;
}


/**
 * 统一展示图片
 * @param painter 画笔
 */
inline void State::showPic(QPainter &painter) {
    indexPic = indexPic % picNum;
    showAction(painter, indexPic);
    indexPic++;
    if (indexPic >= picNum) {
        indexPic = 0;
    }
}

/**
 * 设置图片数量
 * @param num 图片数量
 */
inline void State::setPicNum(int num) {
    picNum = num;
}


#endif //STATE_H
