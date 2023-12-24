#ifndef TIMER_SET_H
#define TIMER_SET_H

#include "combine/combine.h"
//----------------------------
//定时器.h
#include <QObject>
#include <QMainWindow>

//----------------------------
//定时器.cpp
#include <QDebug>
#include <QTimerEvent>


class TCP_Client;
class Chart_init;
class Timer_set : public QObject
{
    Q_OBJECT
public:
    explicit Timer_set(TCP_Client *Client,Chart_init *Chart_set);
    ~Timer_set();
//----------------------------
//定时器
    void timer_setup();
    void handleTimeout();  //超时处理函数
    virtual void timerEvent(QTimerEvent *event);

    TCP_Client *Client;
    Chart_init *Chart;
private:
    int m_nTimerID;

private slots:

};


#endif // TIMER_H
