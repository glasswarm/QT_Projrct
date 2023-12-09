#ifndef CHART_H
#define CHART_H

#include <QMainWindow>
#include <QByteArray>
#include <QValueAxis>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class Chart; }
QT_END_NAMESPACE

class Chart : public QMainWindow
{
    Q_OBJECT

public:
    Chart(QWidget *parent = nullptr);
    ~Chart();

private:
    Ui::Chart *ui;


    QLineSeries *series;
    QList <QPointF> qPoint;
    QChart *chart = new QChart();

private slots:
    void Chart_setup();
    void Button();
};
#endif // CHART_H
