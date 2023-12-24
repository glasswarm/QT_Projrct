#ifndef COMBINE_H
#define COMBINE_H

#include "TCP_Client.h"
#include "ui_TCP_Client.h"
#include "component/timer_set/timer_set.h"
#include "component/chart_init/chart_init.h"
#include "component/image/image.h"
#include "component/PPP_Protocol_Decode/PPP_Protocol_Decode.h"

//--------------------
//声明类
class Client;
class Chart_init;
class Timer_set;
class image_init;

class Combine
{
public:
    Combine();
    ~Combine();

public:
    TCP_Client *Client;
public:
    Chart_init *Chart_set;
public:
    Timer_set  *Timer0;
public:
    image_init *image;

};

//--------------------
//声明变量
extern Ui::TCP_Client *ui0;
extern int buffer_Count;
#endif // COMBINE_H
