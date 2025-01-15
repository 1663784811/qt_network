#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow{parent}
{
    initView();




}

void MainWindow::initView()
{
    QWidget *window = new QWidget;
    setCentralWidget(window);
    resize(1920,1080);
    // 获取屏幕尺寸
    QScreen* screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    // 设置窗口位置，使其居中
    setGeometry((screenGeometry.width() - width()) / 2, (screenGeometry.height() - height()) / 2, width(), height());


    // 创建若干个子窗口对象
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");



    // 创建水平布局对象
    QHBoxLayout *layout = new QHBoxLayout;
    // 将子窗口添加到布局中
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);

    // 将水平布局设置给父窗口对象
    window->setLayout(layout);





}
