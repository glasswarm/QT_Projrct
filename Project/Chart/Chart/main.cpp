#include "chart.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chart w;
    w.show();
    return a.exec();
}
