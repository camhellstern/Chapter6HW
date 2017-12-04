#include "ethernetswitch.h"

EthernetSwitch::EthernetSwitch(QObject *parent, int dramSize, bool ssd) : DataCenterComponent(parent)
{
    cost = 0;
    for(int i=0;i<62;i++)
    {
        ServerRack *rack = new ServerRack(this, dramSize, ssd);
        racks.push_back(rack);
        cost += rack->rackCost();
    }
}

EthernetSwitch::~EthernetSwitch()
{

}

int EthernetSwitch::processRequest()
{

}

int EthernetSwitch::switchCost()
{
    return cost;
}
