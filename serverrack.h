#ifndef SERVERRACK_H
#define SERVERRACK_H

#include <datacentercomponent.h>
#include <server.h>
#include <QList>

class ServerRack : public DataCenterComponent
{
public:
    explicit ServerRack(QObject *parent = 0, int dramSize = 4, bool ssd = false);
    ~ServerRack();
    int rackCost();


private:
    QList<Server *> servers;
    int serverCount;
    int cost;
};

#endif // SERVERRACK_H
