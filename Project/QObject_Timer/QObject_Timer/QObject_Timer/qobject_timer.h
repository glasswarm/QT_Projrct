#ifndef QOBJECT_TIMER_H
#define QOBJECT_TIMER_H

#include <QMainWindow>

//----------------------------
//定时器
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class QObject_Timer; }
QT_END_NAMESPACE

class QObject_Timer : public QMainWindow
{
    Q_OBJECT

public:
    QObject_Timer(QWidget *parent = nullptr);
    ~QObject_Timer();
//----------------------------
//定时器
    void  handleTimeout();  //超时处理函数
    virtual void timerEvent( QTimerEvent *event);

private:
    Ui::QObject_Timer *ui;
//-----------------------------
//定时器
        int m_nTimerID;

private slots:
//------------------------
//定时器
    void timer_setup();
};
#endif // QOBJECT_TIMER_H
