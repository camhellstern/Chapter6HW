#ifndef SERVERRACK_H
#define SERVERRACK_H

#include <globalvalues.h>
#include <QObject>
#include <server.h>
#include <QList>

class ServerRack : public QObject
{
    Q_OBJECT
public:
    explicit ServerRack(QObject *parent = 0, int dramSize = 4, bool ssd = false);
    ~ServerRack();
    int rackCost();

signals:
    void sendRequest(RequestPacket request);
    void sendResponse(ResponseType response);

public slots:
    void processRequest(RequestPacket request);
    void processResponse(ResponseType response);


private:
    QList<Server *> servers;
    int serverCount;
    int cost;
};

#endif // SERVERRACK_H
