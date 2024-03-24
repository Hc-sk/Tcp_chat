#include "chat.h"
#include "ui_chat.h"

chat::chat(QTcpSocket *s,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chat)
{
    socket = s;
    ui->setupUi(this);
}

chat::~chat()
{
    delete ui;
}

void chat::on_clearButton_clicked()
{
    ui->lineEdit->clear();
}


void chat::on_sendButton_clicked()
{
    QByteArray ba;
    ba.append(ui->lineEdit->text().toUtf8());
    socket->write(ba);
}

void chat::KeyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Return){
     chat::on_sendButton_clicked();
}
}
