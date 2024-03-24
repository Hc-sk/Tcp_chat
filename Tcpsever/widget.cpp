#include "widget.h"
#include "ui_widget.h"
#include "mythread.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    server = new QTcpServer;

    server->listen(QHostAddress::AnyIPv4,8000);

    connect(server,&QTcpServer::newConnection,this,&Widget::newClientHander);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::newClientHander(){
    QTcpSocket *socket = server->nextPendingConnection();

    ui->iplineEdit->setText(socket->peerAddress().toString());
    ui->portlineEdit->setText(QString::number(socket->peerPort()));

    mythread *t = new mythread(socket);

    t->run();

    connect(t,&mythread::sendToWidget,this,&Widget::threatSlot);

}
void Widget::threatSlot(QByteArray b){
    ui->receiveEdit->setText(QString(b));
}
