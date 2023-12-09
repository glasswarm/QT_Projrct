#include "chart.h"
#include "ui_chart.h"

//------------------------------------------------------------------
//数据定义
#define Show_Count 5 //x轴要循环的次数的坐标
char Label_y[Show_Count+1];
int my_x=0;

Chart::Chart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Chart)
{
    ui->setupUi(this);

    Chart::Chart_setup();
    connect(ui->Button, SIGNAL(clicked()), this, SLOT(Button() ));
}

Chart::~Chart()
{
    delete ui;
}


void Chart::Chart_setup()
{
    series=new QLineSeries();
    series->setPen(QPen(Qt::blue,1,Qt::SolidLine));
    series->setColor(QColor(0,0,255));
    QChart *chart=new QChart();
    chart->addSeries(series);
    //chart->setTitle("湿度");
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, Show_Count);
    chart->axisY()->setRange(0, 40);

    chart->setTheme(QChart::ChartThemeDark);//设置背景为黑色
    //ui->Data_Chart->setStyleSheet("background-color: black;");//将chart背景外的背景变为黑色
    ui->Data_Chart->setChart(chart);


    int Count = 0;
    while(1)//模拟来数据的处理
    {
        Label_y[Count] = 12;
        if(Count == Show_Count)break;
        Count++;
    }
}

void Chart::Button()
{
    int Count = 0;
    if (my_x == Show_Count+1)//当my_x大于x轴数字时，开始挤掉第一位数
    {
        while(Count < Show_Count)
        {
              series -> replace(Count,Label_y[Count],Count,Label_y[Count+1]); //将旧xy替换为新xy，旧xy的数据一定要对应，否则，该函数没用
              Label_y[Count] = Label_y[Count+1]; //为了使旧xy对应
              Count++;
        }
        Label_y[Show_Count] = 5;//模拟来数据时候的处理
        series -> replace(Show_Count, Show_Count,Label_y[Show_Count]);//增加新数据
    }
    else//当表格内没有数据时，用折线填补表格
    {
        QPointF dataPoint(my_x++, Label_y[my_x]);
        series->append(dataPoint);
    }
}
