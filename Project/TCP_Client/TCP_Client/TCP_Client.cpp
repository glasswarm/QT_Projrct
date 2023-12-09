#include "TCP_Client.h"
#include "ui_TCP_Client.h"

TCP_Client::TCP_Client(QWidget *parent) :
            QMainWindow(parent)         ,
            ui(new Ui::TCP_Client)
{
     ui->setupUi(this);
//----------------------------------------------
//初始化TCP客户端
     TCP_Client::setup();
}

TCP_Client::~TCP_Client()
{
     delete ui;
}

void TCP_Client::setup()
{
     tcpClient =  new QTcpSocket(this);//实例化tcpClient
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

void TCP_Client::ReadData()
{
     QByteArray buffer = tcpClient->readAll();//读取字节
//当buffer不为空时，右方大框显示buffer内容
     if(!buffer.isEmpty())
     {
         ui->Read_Text->append(buffer);
     }
}

void TCP_Client::ReadError(QAbstractSocket::SocketError)
{
     tcpClient->disconnectFromHost();
     ui->Point0->setText( "读取出错" );
}
