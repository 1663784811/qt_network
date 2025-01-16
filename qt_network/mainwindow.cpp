#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QTableView>


MainWindow::MainWindow(QWidget *parent) : QMainWindow{parent}
{
    initView();




}

void MainWindow::initView()
{
    QWidget *window = new QWidget();
    setCentralWidget(window);
    resize(1920,1080);
    // 获取屏幕尺寸
    QScreen* screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    // 设置窗口位置，使其居中
    setGeometry((screenGeometry.width() - width()) / 2, (screenGeometry.height() - height()) / 2, width(), height());


    QScrollArea* scrollLeft = new QScrollArea();
    scrollLeft->setWidgetResizable(true);
    scrollLeft->setFixedWidth(240);
    scrollLeft->setContentsMargins(0,0,0,0);

    QWidget *scrollContent = new QWidget();
    QVBoxLayout* menuLayout = new QVBoxLayout(scrollContent);

    for (int i = 0; i < 80; ++i) {
        QPushButton* btn =  new QPushButton("aaa"+ QString::number(i));
        menuLayout->addWidget(btn);
    }
    scrollContent->setLayout(menuLayout);
    scrollLeft->setWidget(scrollContent);







    //==================================================================
    QScrollArea *mainContainer = new QScrollArea();
    mainContainer->setWidgetResizable(true);
    mainContainer->setContentsMargins(0,0,0,0);
    QWidget *mainContent = new QWidget();
    mainContainer->setWidget(mainContent);
    QTableView* aa = new QTableView();


    //mainContent->setLayout();


    //==================================================================
    // 创建水平布局对象
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    // 将子窗口添加到布局中
    layout->addWidget(scrollLeft);
    layout->addWidget(mainContainer);

    // 将水平布局设置给父窗口对象
    window->setLayout(layout);





}
