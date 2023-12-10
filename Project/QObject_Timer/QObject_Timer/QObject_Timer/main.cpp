#include "qobject_timer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QObject_Timer w;
    w.show();
    return a.exec();
}
