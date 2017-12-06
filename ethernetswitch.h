#ifndef ETHERNETSWITCH_H
#define ETHERNETSWITCH_H

#include <globalvalues.h>
#include <QObject>
#include <QList>
#include <serverrack.h>


class EthernetSwitch : public QObject
{
    Q_OBJECT
public:
    explicit EthernetSwitch(QObject *parent = 0, int dramSize = 4, bool ssd = false);
    ~EthernetSwitch();
    int switchCost();

signals:
    void sendResponse(ResponseType *response);

public slots:
    void processRequest(RequestPacket request);
    void processResponse(ResponseType *response);

private:
    int cost;
    int nextRack;
    QList<ServerRack *> racks;


};

#endif // ETHERNETSWITCH_H
