#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent* event) override;//重写鼠标按键事件
    void mouseMoveEvent(QMouseEvent* event) override;//重写鼠标移动事件



private:
    Ui::MainWindow *ui;

    QPointF m_diff_pos;//鼠标和窗口的相对位移
    QPointF m_window_pos;//窗口左上角点的位置
    QPointF m_mouse_pos;//鼠标绝对位置


};
#endif // MAINWINDOW_H
