#include "ui_TCP_Client.h"
#include "timer_set.h"


Timer_set::Timer_set(TCP_Client *Client,Chart_init *Chart_set):Client(Client),
                                                               Chart(Chart_set)
{
    Timer_set::timer_setup();
}

Timer_set::~Timer_set()
{
    if (m_nTimerID != 0 )
    {
        killTimer(m_nTimerID);
    }
}
//----------------------------------------------
//定时器相关函数
#define TIMER_TIMEOUT	1000
void Timer_set::timer_setup()
{
     m_nTimerID = startTimer(TIMER_TIMEOUT);
}

void Timer_set::timerEvent(QTimerEvent *event)
{

    if(event->timerId() == m_nTimerID){
        handleTimeout();
    }
}

void Timer_set::handleTimeout()
{
//    qDebug()<<"Enter timeout processing function\n";
//    killTimer(m_nTimerID);

    ui0->label_2->setNum(500);
    Chart->Circulation();
    buffer_Count = 0;
}

