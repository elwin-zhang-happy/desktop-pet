//
// Created by ElwinZhang on 2024/9/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MajorWindow.h" resolved

#include "Majorwindow.h"
#include <QMenu>
#include <QMouseEvent>
#include <QString>
#include <qdatetime.h>

#include "IdleState.h"
#include "QPainter"
#include "QThread"
#include "ui_MajorWindow.h"


MajorWindow::MajorWindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::MajorWindow), currentPetState(PetState::IDLE), lastPetState(PetState::IDLE),
    triggerManager(new TriggerManager(this)), timer(new QTimer), contextMenu(nullptr), initialized(false){
    ui->setupUi(this);

    // 初始化窗口
    initial();
}

MajorWindow::~MajorWindow() { delete ui; }

/**
 * 初始化窗口
 */
void MajorWindow::initial() {
    // 注册定时任务，刷新页面频率
    QMetaObject::Connection timerCon = connect(&timer, &QTimer::timeout, [this]() {
        if (initialized) {
            update();
        } else {
            initialized = true;
        }
    });
    // 默认开始时间
    timer.start(Constants::timerInterval);
    // 隐藏菜单栏等
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    // 设置窗口大小
    resize(Constants::width, Constants::height);
    // 设置背景透明
    setStyleSheet("background: transparent;");

    // 初始化菜单
    contextMenu = new QMenu(this);
    QAction *closeAction = contextMenu->addAction(QStringLiteral("关闭"));
    QMetaObject::Connection closeCon = connect(closeAction, &QAction::triggered, [this]() {
        this->timer.stop();
        this->update();
        this->clickType = ClickType::CLOSE;
        this->currentPetState = PetState::EXIT;
        this->timer.start(Constants::timerInterval);
        // 3秒定时退出
        QTimer::singleShot(3000, [this]() { QApplication::quit(); });
    });
    // 设置样式表
    contextMenu->setStyleSheet("QMenu {"
                               "   background-color: #F0F0F0;"
                               "   border: 1px solid #BDBDBD;"
                               "}"
                               "QMenu::item {"
                               "   padding: 2px 20px;"
                               "   color: #333333;"
                               "}"
                               "QMenu::item:selected {"
                               "   background-color: #9E9E9E;"
                               "   color: white;"
                               "}"
                               "QMenu::separator {"
                               "   height: 1px;"
                               "   background-color: #BDBDBD;"
                               "}");
}

/**
 * 绘制桌宠图片
 * @param event 图片绘制
 */
void MajorWindow::paintEvent(QPaintEvent *event) {
    if (!initialized) {
        return;
    }
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    // 清除绘制区域为透明
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    // 绘制图片
    triggerManager->showAction(currentStateType, painter, prePetState, currentPetState);
}

/**
 * 通过鼠标一系列事件实现拖动效果
 * @param event 鼠标事件
 */
void MajorWindow::mousePressEvent(QMouseEvent *event) {
    if (clickType != ClickType::NONE) {
        return;
    }
    clickType = ClickType::SINGLE;
    timer.stop();
    triggerManager->resetPetState(PetState::DRINK_TEA);
    prePetState = PetState::DRINK_TEA;
    currentStateType = StateType::PRE;
    timer.start();
}
void MajorWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (clickType == ClickType::DOUBLE) {
        restorePetState();
    } else if (clickType == ClickType::SINGLE) {

    }
    clickType = ClickType::NONE;
}
void MajorWindow::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        if (clickType == ClickType::DOUBLE) {
            // 使用 globalPosition() 并将其转换为 QPoint
            move(event->globalPosition().toPoint() - mousePos);
            event->accept();
        }
    } else {
        QWidget::mouseMoveEvent(event);
    }
}
void MajorWindow::mouseDoubleClickEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        clickType = ClickType::DOUBLE;
        switchPetState(PetState::DRAG);
        mousePos = event->globalPosition().toPoint() - this->frameGeometry().topLeft();
    }
}

/**
 * 菜单事件
 * @param event 菜单事件
 */
void MajorWindow::contextMenuEvent(QContextMenuEvent *event) {
    if (!contextMenu) {
        return;
    }
    // 弹出菜单
    contextMenu->popup(event->globalPos());
}

/**
 * 恢复原来状态
 */
void MajorWindow::restorePetState() {
    this->timer.stop();
    this->currentPetState = lastPetState;
    this->timer.start(Constants::timerInterval);
}

/**
 * 切换绘图状态
 * @param state 状态
 */
void MajorWindow::switchPetState(PetState state){
    this->timer.stop();
    this->currentStateType = StateType::LOOP;
    this->lastPetState = currentPetState;
    this->currentPetState = state;
    this->update();
    this->timer.start(Constants::timerInterval);
}

