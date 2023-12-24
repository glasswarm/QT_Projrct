#include "combine/combine.h"
#include "TCP_Client.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Combine *Com;
    Com = new Combine();

    return a.exec();
}
