#include "serverrack.h"

ServerRack::ServerRack(QObject *parent, int dramSize, bool ssd) : DataCenterComponent(parent)
{
    //EthernetSwitch *m_switch = new EthernetSwitch(this);
    //components.push_back(m_switch);
    for(int i=0;i<47;i++)
    {
        Server *s = new Server(this, ssd);
        servers.push_back(s);
    }
}

ServerRack::~ServerRack()
{

}

int ServerRack::rackCost()
{
    return cost;
}
