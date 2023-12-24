#include "ui_TCP_Client.h"
#include "chart_init.h"


Chart_init::Chart_init()
{
    Chart_setup();
}

Chart_init::~Chart_init()
{

}

//------------------------------------------------------------------
//图表相关函数
#define X_Show_Count 10 //x轴要循环的次数的坐标
#define Y_Show_Count 1000000 //y轴数据上限

unsigned int Label_y[X_Show_Count+2];
int my_x=0;
void Chart_init::Chart_setup()
{
    series=new QLineSeries();
    series->setPen(QPen(Qt::blue,1,Qt::SolidLine));
    series->setColor(QColor(0,0,255));
    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("数据量");
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, X_Show_Count);
    chart->axisY()->setRange(0, Y_Show_Count);

    chart->setTheme(QChart::ChartThemeDark);//设置背景为黑色
    //ui0->Data_Chart->setStyleSheet("background-color: black;");//将chart背景外的背景变为黑色
    ui0->Data_Chart->setChart(chart);

    //connect(tcpClient, SIGNAL(readyRead()), this, SLOT(Circulation() ));
}


void Chart_init::Circulation()
{
     //QByteArray buffer = tcpClient->readAll();//读取字节
     //buffer_Count = buffer.length();
     ui0->label->setNum(buffer_Count);
     int Count = 0;
     if (my_x == X_Show_Count+1)//当my_x大于x轴数字时，开始挤掉第一位数
     {
         while(Count < X_Show_Count)
         {
               series -> replace(Count,Label_y[Count],Count,Label_y[Count+1]); //将旧xy替换为新xy，旧xy的数据一定要对应，否则，该函数没用
               Label_y[Count] = Label_y[Count+1]; //为了使旧xy对应
               Count++;
         }
         Label_y[X_Show_Count+1] = buffer_Count;//模拟来数据时候的处理
         series -> replace(X_Show_Count,Label_y[X_Show_Count], X_Show_Count,Label_y[X_Show_Count+1]);//增加新数据
         Label_y[X_Show_Count] = Label_y[X_Show_Count+1]; //为了使旧xy对应
     }
     else//当表格内没有数据时，用折线填补表格
     {
         Label_y[my_x] = buffer_Count;
         QPointF dataPoint(my_x++, Label_y[my_x]);
         series->append(dataPoint);
     }
}
