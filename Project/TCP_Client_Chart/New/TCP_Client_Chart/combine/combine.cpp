#include "combine.h"


Combine::Combine()
{
    Client     = new TCP_Client();
    Chart_set  = new Chart_init();
    Timer0     = new Timer_set(Client,Chart_set);//初始化Timer
    image      = new image_init();

    Client -> show();
}

Combine::~Combine()
{
    delete Client;
    delete Timer0;
}
