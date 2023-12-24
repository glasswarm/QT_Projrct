#include "TCP_Client.h"
#include "ui_TCP_Client.h"
//----------------------------
//图表
#include <QHostAddress>
#include <QMessageBox>
//----------------------------
//定时器
#include <QDebug>
#include <QTimerEvent>

TCP_Client::TCP_Client(QWidget *parent) :
            QMainWindow(parent)         ,
            ui(new Ui::TCP_Client)
{
     ui->setupUi(this);
//----------------------------------------------
//初始化TCP客户端
     TCP_Client::setup();

//----------------------------------------------
//初始化图表
     TCP_Client::Chart_setup();

//----------------------------------------------
//初始化Timer
     TCP_Client::timer_setup();
}


TCP_Client::~TCP_Client()
{
     delete ui;
}


//-----------------------------------------------------------------------------------
//TCP客户端相关函数
void TCP_Client::setup()
{
     tcpClient =  new QTcpSocket();//实例化tcpClient
     tcpClient -> abort();             //取消原有连接

//-----------------------------------------------
//连接TCP_Client槽函数
     connect(tcpClient, SIGNAL(readyRead()                        ), this, SLOT(ReadData()                              ));
     connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(ReadError(QAbstractSocket::SocketError) ));

//-----------------------------------------------
//连接Button槽函数
     connect(ui->Button0, SIGNAL(clicked()), this, SLOT(Button0_Connect   () ));//按钮0
     connect(ui->Button1, SIGNAL(clicked()), this, SLOT(Button1_DisConnect() ));//按钮1
}

void TCP_Client::Button0_Connect()
{
//-----------------------------------------------
//连接函数,开启魔法的时候，可能会连不上，建议关掉
     tcpClient->connectToHost(ui->Input_IP->text(), ui->Input_Port->text().toInt());
     ui->Point0->setText("连接中");
     if (tcpClient->waitForConnected(1000))//连接成功则进入if{}
     {
         ui->Point0->setText("已连接");
     }
}

void TCP_Client::Button1_DisConnect()
{
//-----------------------------------------------
//断开连接函数
     tcpClient->disconnectFromHost();
     if (tcpClient->state() == QAbstractSocket::UnconnectedState || tcpClient->waitForDisconnected(1000))//连接后断开则进入if{}
     {
         ui->Point0->setText("未连接");
     }
}

int buffer_Count;

void TCP_Client::ReadData()
{
     QByteArray buffer = tcpClient->readAll();//读取字节
     buffer_Count += buffer.length();
     if(!buffer.isEmpty())//当buffer不为空时，右方大框显示buffer内容
     {
         //ui->Read_Text->append(buffer);
     }
}

void TCP_Client::ReadError(QAbstractSocket::SocketError)
{
     tcpClient->disconnectFromHost();
     ui->Point0->setText( "读取出错" );
}


//----------------------------------------------
//定时器相关函数
#define TIMER_TIMEOUT	1000
void TCP_Client::timer_setup()
{
     m_nTimerID = this -> startTimer(TIMER_TIMEOUT);
}


void TCP_Client::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_nTimerID){
        handleTimeout();
    }
}

void TCP_Client::handleTimeout()
{
    //qDebug()<<"Enter timeout processing function\n";
    //killTimer(m_nTimerID);
    TCP_Client::Circulation();
    buffer_Count = 0;
}



//------------------------------------------------------------------
//图表相关函数
#define X_Show_Count 50 //x轴要循环的次数的坐标
#define Y_Show_Count 60000 //y轴数据上限

unsigned int Label_y[X_Show_Count+2];
int my_x=0;
void TCP_Client::Chart_setup()
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
    //ui->Data_Chart->setStyleSheet("background-color: black;");//将chart背景外的背景变为黑色
    ui->Data_Chart->setChart(chart);

    //connect(tcpClient, SIGNAL(readyRead()), this, SLOT(Circulation() ));
}


void TCP_Client::Circulation()
{
     //QByteArray buffer = tcpClient->readAll();//读取字节
     //buffer_Count = buffer.length();
     ui->label->setNum(buffer_Count);
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





