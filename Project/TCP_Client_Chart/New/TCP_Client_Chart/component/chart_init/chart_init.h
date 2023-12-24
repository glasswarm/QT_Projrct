#ifndef CHART_INIT_H
#define CHART_INIT_H

#include "combine/combine.h"
//----------------------------
//图表.h
#include <QByteArray>
#include <QValueAxis>
#include <QtCharts>
//----------------------------
//图表.cpp
#include <QHostAddress>
#include <QMessageBox>

class Chart_init
{
public:
    Chart_init();
    ~Chart_init();

    void Chart_setup();
    void Circulation();
private:
//-----------------------------
//图表
    QLineSeries *series;
    QList <QPointF> qPoint;
    int my_x=0,my_y=0;
    QChart *chart = new QChart();

};

#endif // CHART_INIT_H
