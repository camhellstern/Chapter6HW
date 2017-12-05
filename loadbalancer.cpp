#include "loadbalancer.h"

LoadBalancer::LoadBalancer(QObject *parent, int dramSize, bool ssd) : DataCenterComponent(parent)
{
    EthernetSwitch *s1 = new EthernetSwitch(this, dramSize, ssd);
    switch1 = s1;
    EthernetSwitch *s2 = new EthernetSwitch(this, dramSize, ssd);
    switch2 = s2;
    cost = switch1->switchCost() + switch2->switchCost();
}

LoadBalancer::~LoadBalancer()
{

}

int LoadBalancer::processRequest()
{
    int x = 7;
    return x;
}

int LoadBalancer::lbCost()
{
    return cost;
}
