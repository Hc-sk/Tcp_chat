#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class mythread : public QObject
{
    Q_OBJECT
public:
    explicit mythread(QTcpSocket *s);
    void run();
    void clientIntoSlot();

signals:
    void sendToWidget(QByteArray b);
private:
    QTcpSocket *socket;
};

#endif // MYTHREAD_H
