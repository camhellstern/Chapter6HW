#include "router.h"

Router::Router(QObject *parent, int dramSize, int storageParam) : QObject(parent)
{
    cost = 0;
    if(dramSize == 1)
    {
        if(storageParam == 1)
        {
            LoadBalancer *loadb1 = new LoadBalancer(this, 4, false);
            lb1 = loadb1;
            LoadBalancer *loadb2 = new LoadBalancer(this, 4, false);
            lb2 = loadb2;
        }
        else if(storageParam == 2)
        {
            LoadBalancer *loadb1 = new LoadBalancer(this, 4, true);
            lb1 = loadb1;
            LoadBalancer *loadb2 = new LoadBalancer(this, 4, false);
            lb2 = loadb2;
        }
        else if(storageParam == 3)
        {
            LoadBalancer *loadb1 = new LoadBalancer(this, 4, true);
            lb1 = loadb1;
            LoadBalancer *loadb2 = new LoadBalancer(this, 4, true);
            lb2 = loadb2;
        }
    }
    else if(dramSize == 2)
    {
        if(storageParam == 1)
        {
            LoadBalancer *loadb1 = new LoadBalancer(this, 16, false);
            lb1 = loadb1;
            LoadBalancer *loadb2 = new LoadBalancer(this, 16, false);
            lb2 = loadb2;
        }
        else if(storageParam == 2)
        {
            LoadBalancer *loadb1 = new LoadBalancer(this, 16, true);
            lb1 = loadb1;
            LoadBalancer *loadb2 = new LoadBalancer(this, 16, false);
            lb2 = loadb2;
        }
        else if(storageParam == 3)
        {
            LoadBalancer *loadb1 = new LoadBalancer(this, 16, true);
            lb1 = loadb1;
            LoadBalancer *loadb2 = new LoadBalancer(this, 16, true);
            lb2 = loadb2;
        }
    }
    else if(dramSize == 3)
    {
        if(storageParam == 1)
        {
            LoadBalancer *loadb1 = new LoadBalancer(this, 32, false);
            lb1 = loadb1;
            LoadBalancer *loadb2 = new LoadBalancer(this, 32, false);
            lb2 = loadb2;
        }
        else if(storageParam == 2)
        {
            LoadBalancer *loadb1 = new LoadBalancer(this, 32, true);
            lb1 = loadb1;
            LoadBalancer *loadb2 = new LoadBalancer(this, 32, false);
            lb2 = loadb2;
        }
        else if(storageParam == 3)
        {
            LoadBalancer *loadb1 = new LoadBalancer(this, 32, true);
            lb1 = loadb1;
            LoadBalancer *loadb2 = new LoadBalancer(this, 32, true);
            lb2 = loadb2;
        }
    }
    cost = lb1->lbCost() + lb2->lbCost();
    connect(this, &Router::sendLB1, lb1, &LoadBalancer::processRequest);
    connect(this, &Router::sendLB2, lb2, &LoadBalancer::processRequest);
    connect(lb1, &LoadBalancer::sendResponse, this, &Router::processResponse);
    connect(lb2, &LoadBalancer::sendResponse, this, &Router::processResponse);
}

Router::~Router()
{

}

int Router::routerCost()
{
    return cost;
}

void Router::processRequest(RequestPacket request)
{
    if(request.ipAddress >= ipStart && request.ipAddress <= ipEnd)
    {
        if(request.ipAddress <= (ipStart+ipEnd)/2)
            emit sendLB1(request);
        else
            emit sendLB2(request);
    }
}

void Router::setIPRange(int startIP, int endIP)
{
    ipStart = startIP;
    ipEnd = endIP;
}

void Router::processResponse(ResponseType response)
{
    emit sendResponse(response);
}
