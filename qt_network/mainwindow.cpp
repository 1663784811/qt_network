#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QWidget>
#include <QMouseEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint); // 无边框
    setAttribute(Qt::WA_TranslucentBackground); // 透明背景
    setStyleSheet("background: transparent;"); // 确保样式也是透明的

    // 创建阴影效果
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setColor(Qt::black); // 阴影颜色
    shadowEffect->setOffset(0, 0);    // 阴影偏移
    shadowEffect->setBlurRadius(20);  // 模糊半径
    setGraphicsEffect(shadowEffect);




    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //鼠标刚点击的时候，求出相对位置
    m_mouse_pos = event->globalPosition();
    m_window_pos = this->pos();
    m_diff_pos = m_mouse_pos - m_window_pos;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //鼠标移动后
    //获取鼠标移动后的全局位置
    QPointF pos = event->globalPosition();
    this->move(pos.x() - m_diff_pos.x(), pos.y()- m_diff_pos.y());//鼠标位置减去相对距离
}

