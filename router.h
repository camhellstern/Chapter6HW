#ifndef ROUTER_H
#define ROUTER_H

#include <datacentercomponent.h>
#include <loadbalancer.h>

class Router : public DataCenterComponent
{
public:
    explicit Router(QObject *parent = 0, int dramSize = 1, int storageParam = 1);
    ~Router();
    int routerCost();

public slots:
    int processRequest();

private:
    LoadBalancer *lb1;
    LoadBalancer *lb2;
    int cost;
};

#endif // ROUTER_H
