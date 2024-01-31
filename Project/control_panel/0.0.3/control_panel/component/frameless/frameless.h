#ifndef FRAMELESS_H
#define FRAMELESS_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QNetworkAccessManager>

#ifdef Q_OS_WIN
    #include <qt_windows.h>
    #include <Windowsx.h>
#endif

#include <QDebug>
#include <QScreen>
#include <QDesktopWidget>

class control_panel;
class frameless : public QMainWindow
{
    Q_OBJECT

public:
    explicit frameless(QWidget *parent = nullptr);
    ~frameless();

public:
    void frameless_init(control_panel *control);

protected:
    void mousePressEvent(QMouseEvent*event)override;
    void mouseMoveEvent(QMouseEvent*event)override;
    void mouseReleaseEvent(QMouseEvent*event)override;
    void mouseDoubleClickEvent(QMouseEvent*event)override;
    bool nativeEvent(const QByteArray &eventType, void *message, long *result)override;

private:
    void constructor();

    void initWindow();  //初始化窗口控件
    void size_init();
    void loadQssFile(); //加载qss
    void set_Connect();

public slots:
    void windowMin();
    void windowMax();
    void windowClose();

private:
    control_panel *main_pointer;

private:
    bool isPressed;
    bool isMaxWin;
    QPoint curPos;
};
#endif // FRAMELESS_H
