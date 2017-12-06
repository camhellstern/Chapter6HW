#ifndef ROUTER_H
#define ROUTER_H

#include <QObject>
#include <globalvalues.h>
#include <loadbalancer.h>

class Router : public QObject
{
    Q_OBJECT
public:
    explicit Router(QObject *parent = 0, int dramSize = 1, int storageParam = 1);
    ~Router();
    int routerCost();
    void setIPRange(int startIP, int endIP);

signals:
    void sendLB1(RequestPacket request);
    void sendLB2(RequestPacket request);
    void sendResponse(ResponseType *response);

public slots:
    void processRequest(RequestPacket request);
    void processResponse(ResponseType *response);

private:
    LoadBalancer *lb1;
    LoadBalancer *lb2;
    int cost;
    int ipStart;
    int ipEnd;
};

#endif // ROUTER_H
