#include "ui_TCP_Client.h"
#include "TCP_Client.h"


Ui::TCP_Client *ui0;//Ui::xxx是个类

TCP_Client::TCP_Client(QWidget *parent) :
            QMainWindow(parent)         ,
            ui(new Ui::TCP_Client)
{
     ui0  = ui;
     ui0 -> setupUi(this);
//----------------------------------------------
//初始化TCP客户端
     setup();
}


TCP_Client::~TCP_Client()
{
     delete ui;
     delete ui0;
}


//-----------------------------------------------------------------------------------
//TCP客户端相关函数
void TCP_Client::setup()
{
     tcpClient =  new QTcpSocket();//实例化tcpClient
     tcpClient -> abort();             //取消原有连接
     ui0->label->setNum(5000);
//-----------------------------------------------
//连接TCP_Client槽函数
     connect(tcpClient, SIGNAL(readyRead()                        ), this, SLOT(ReadData()                              ));
     connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(ReadError(QAbstractSocket::SocketError) ));

//-----------------------------------------------
//连接Button槽函数
     connect(ui0->Button0, SIGNAL(clicked()), this, SLOT(Button0_Connect   () ));//按钮0
     connect(ui0->Button1, SIGNAL(clicked()), this, SLOT(Button1_DisConnect() ));//按钮1
}

void TCP_Client::Button0_Connect()
{
//-----------------------------------------------
//连接函数,开启魔法的时候，可能会连不上，建议关掉
     tcpClient->connectToHost(ui0->Input_IP->text(), ui0->Input_Port->text().toInt());
     ui0->Point0->setText("连接中");
     if (tcpClient->waitForConnected(1000))//连接成功则进入if{}
     {
         ui0->Point0->setText("已连接");
     }
}

void TCP_Client::Button1_DisConnect()
{
//-----------------------------------------------
//断开连接函数
     tcpClient->disconnectFromHost();
     if (tcpClient->state() == QAbstractSocket::UnconnectedState || tcpClient->waitForDisconnected(1000))//连接后断开则进入if{}
     {
         ui0->Point0->setText("未连接");
     }
}

void TCP_Client::ReadError(QAbstractSocket::SocketError)
{
     tcpClient->disconnectFromHost();
     ui0->Point0->setText( "读取出错" );
}

int buffer_Count;
//unsigned char buffer_temp[2 * PPP_Decode_digit];
void TCP_Client::ReadData()
{
     QByteArray buffer = tcpClient->readAll();//读取字节
     buffer_Count += buffer.length();
     unsigned char *buffer_temp = reinterpret_cast<unsigned char*> (buffer.data());
//     New_Buffer(buffer_temp);
     if (separate_flag == 0)
     {
         PPP_Protocol_Decode(receive_separate(buffer_temp));
     }
     else;

     if(!buffer.isEmpty())//当buffer不为空时，右方大框显示buffer内容
     {
         //ui->Read_Text->append(buffer);
     }
}




