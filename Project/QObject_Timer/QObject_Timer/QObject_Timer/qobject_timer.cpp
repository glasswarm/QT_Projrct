#include "qobject_timer.h"
#include "ui_qobject_timer.h"

QObject_Timer::QObject_Timer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QObject_Timer)
{
    ui->setupUi(this);

    QObject_Timer::timer_setup();
}

QObject_Timer::~QObject_Timer()
{
    delete ui;
}

//----------------------------------------------
//定时器相关函数
#define TIMER_TIMEOUT	1000
int G = 1;
void QObject_Timer::timer_setup()
{
     m_nTimerID = this -> startTimer(TIMER_TIMEOUT);
}


void QObject_Timer::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_nTimerID){
        handleTimeout();
    }
}

void QObject_Timer::handleTimeout()
{
    //qDebug()<<"Enter timeout processing function\n";
    //killTimer(m_nTimerID);
    ui->label->setNum(G++);
}
