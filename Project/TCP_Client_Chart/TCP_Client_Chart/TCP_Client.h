#ifndef TCP_Client_H
#define TCP_Client_H
//----------------------------
//TCP
#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
//----------------------------
//图表
#include <QByteArray>
#include <QValueAxis>
#include <QtCharts>
//----------------------------
//定时器
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class TCP_Client; }
QT_END_NAMESPACE

class TCP_Client : public QMainWindow
{
    Q_OBJECT

public:
    TCP_Client(QWidget *parent = nullptr);
    ~TCP_Client();
//----------------------------
//定时器
    void  handleTimeout();  //超时处理函数
    virtual void timerEvent( QTimerEvent *event);

private:
    Ui::TCP_Client *ui;
    QTcpSocket *tcpClient;

//-----------------------------
//图表
    QLineSeries *series;
    QList <QPointF> qPoint;
    int my_x=0,my_y=0;
    QChart *chart = new QChart();

//-----------------------------
//定时器
    int m_nTimerID;

private slots:
//------------------------
//TCP_Client槽函数
    void setup();
    void Button0_Connect();
    void Button1_DisConnect();

    void ReadData();
    void ReadError(QAbstractSocket::SocketError);

//------------------------
//图表槽函数
    void Chart_setup();
    void Circulation();

//------------------------
//定时器
    void timer_setup();
};
#endif // TCP_H
