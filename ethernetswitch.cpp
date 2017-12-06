#include "ethernetswitch.h"

EthernetSwitch::EthernetSwitch(QObject *parent, int dramSize, bool ssd) : QObject(parent)
{
    cost = 0;
    for(int i=0;i<62;i++)
    {
        ServerRack *rack = new ServerRack(this, dramSize, ssd);
        racks.push_back(rack);
        cost += rack->rackCost();
        connect(rack, &ServerRack::sendResponse, this, &EthernetSwitch::processResponse);
    }
    cost += SWITCHCOST;
    nextRack = 0;
}

EthernetSwitch::~EthernetSwitch()
{

}

void EthernetSwitch::processRequest(RequestPacket request)
{
    racks.at(nextRack)->processRequest(request);
    if(nextRack == 61)
        nextRack = 0;
    else
        nextRack++;
    //return 0;
}

int EthernetSwitch::switchCost()
{
    return cost;
}

void EthernetSwitch::processResponse(ResponseType *response)
{
    response->responseTime += ESWITCHDELAY;
    emit sendResponse(response);
}
