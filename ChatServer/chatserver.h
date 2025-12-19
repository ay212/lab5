#ifndef CHATSERVER_H
#define CHATSERVER_H

#include "serverworker.h"
#include <QObject>
#include <QTcpServer>

class ChatServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit ChatServer(QObject *parent =nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;
    QVector<ServerWorker *>m_client;

signals:
    void logMessage(const QString &msg);


public slots:
    void  stopServer();

};

#endif // CHATSERVER_H
