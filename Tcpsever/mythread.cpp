#include "mythread.h"

mythread::mythread(QTcpSocket *s)
{
    socket = s;
}
void mythread::run(){
    connect(socket,&QTcpSocket::readyRead,this,&mythread::clientIntoSlot);
}
void mythread::clientIntoSlot(){
    emit sendToWidget(socket->readAll());
}
