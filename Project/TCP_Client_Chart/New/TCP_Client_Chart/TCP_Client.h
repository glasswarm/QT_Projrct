#ifndef TCP_Client_H
#define TCP_Client_H

#include "combine/combine.h"

#include <QtCharts>

//----------------------------
//TCP
#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class TCP_Client; }
QT_END_NAMESPACE

class TCP_Client : public QMainWindow
{
    Q_OBJECT

public:
    TCP_Client(QWidget *parent = nullptr);
    ~TCP_Client();

    Ui::TCP_Client *ui;
private:
    QTcpSocket *tcpClient;

public:

private slots:
//------------------------
//TCP_Client槽函数
    void setup();
    void Button0_Connect();
    void Button1_DisConnect();

    void ReadError(QAbstractSocket::SocketError);
    void ReadData();
};

#endif // TCP_H
