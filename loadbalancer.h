#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <QObject>
#include <globalvalues.h>
#include <ethernetswitch.h>
#include <QList>


class LoadBalancer : public QObject
{
    Q_OBJECT
public:
    explicit LoadBalancer(QObject *parent = 0, int dramSize = 4, bool ssd = false);
    ~LoadBalancer();
    int lbCost();

signals:
    void sendSwitch1(RequestPacket request);
    void sendSwitch2(RequestPacket request);
    void sendResponse(ResponseType *response);

public slots:
    void processRequest(RequestPacket request);
    void processResponse(ResponseType *response);

private:
    EthernetSwitch *switch1;
    EthernetSwitch *switch2;
    int switch1Requests;
    int switch2Requests;
    int cost;
};

#endif // LOADBALANCER_H
