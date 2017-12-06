#include "loadbalancer.h"

LoadBalancer::LoadBalancer(QObject *parent, int dramSize, bool ssd) : QObject(parent)
{
    cost = 0;
    EthernetSwitch *s1 = new EthernetSwitch(this, dramSize, ssd);
    switch1 = s1;
    EthernetSwitch *s2 = new EthernetSwitch(this, dramSize, ssd);
    switch2 = s2;
    cost = switch1->switchCost() + switch2->switchCost() + LOADBALANCERCOST;
    connect(this, &LoadBalancer::sendSwitch1, switch1, &EthernetSwitch::processRequest);
    connect(this, &LoadBalancer::sendSwitch2, switch2, &EthernetSwitch::processRequest);
    connect(switch1, &EthernetSwitch::sendResponse, this, &LoadBalancer::processResponse);
    connect(switch2, &EthernetSwitch::sendResponse, this, &LoadBalancer::processResponse);
    switch1Requests = 0;
    switch2Requests = 0;
}

LoadBalancer::~LoadBalancer()
{

}

void LoadBalancer::processRequest(RequestPacket request)
{
    if(switch1Requests <= switch2Requests)
    {
        emit sendSwitch1(request);
        switch1Requests++;
    }
    else
    {
        emit sendSwitch2(request);
        switch2Requests++;
    }
}

int LoadBalancer::lbCost()
{
    return cost;
}

void LoadBalancer::processResponse(ResponseType *response)
{
    response->responseTime += LBDELAY;
    emit sendResponse(response);
}
