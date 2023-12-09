#ifndef TCP_Client_H
#define TCP_Client_H

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

private:
    Ui::TCP_Client *ui;
    QTcpSocket *tcpClient;

private slots:
//------------------------
//TCP_Client槽函数
    void setup();
    void Button0_Connect();
    void Button1_DisConnect();

    void ReadData();
    void ReadError(QAbstractSocket::SocketError);
};
#endif // TCP_H
