#include "TCP_Client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TCP_Client w;
    w.show();
    return a.exec();
}
