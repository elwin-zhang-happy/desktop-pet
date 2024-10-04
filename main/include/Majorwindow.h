//
// Created by ElwinZhang on 2024/9/16.
//

#ifndef MAJORWINDOW_H
#define MAJORWINDOW_H

#include <Constants.h>
#include "TriggerManager.h"
#include <qmenu.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MajorWindow; }
QT_END_NAMESPACE

class MajorWindow : public QWidget {
Q_OBJECT

public:
    explicit MajorWindow(QWidget *parent = nullptr);
    ~MajorWindow() override;

private:
    void initial();// 初始化窗口

protected:
    void paintEvent(QPaintEvent *event) override; // 绘制事件
    void mousePressEvent(QMouseEvent *event) override; // 鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *event) override; // 鼠标释放
    void mouseMoveEvent(QMouseEvent *event) override; // 鼠标移动事件
    void mouseDoubleClickEvent(QMouseEvent *event) override; // 鼠标双击事件
    void contextMenuEvent(QContextMenuEvent *event) override; // 鼠标右键点击菜单

public:
    void switchPetState(PetState state); // 切换绘图器
    void restorePetState(); // 恢复上一次状态

    PetState currentPetState; // 当前状态
    PetState lastPetState; // 上一次状态
    PetState prePetState; // 前置状态
    StateType currentStateType; // 当前状态类型

private:
    std::unique_ptr<TriggerManager> triggerManager; // 触发器总成
    QPoint mousePos; // 鼠标位置
    Ui::MajorWindow *ui; // 主ui页面
    QTimer timer; // 刷新频率
    QMenu *contextMenu; // 右键菜单
    bool initialized; // 初始化标志
    ClickType clickType;
};


#endif //MAJORWINDOW_H
