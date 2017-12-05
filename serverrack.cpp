#include "serverrack.h"

ServerRack::ServerRack(QObject *parent, int dramSize, bool ssd) : DataCenterComponent(parent)
{
    //EthernetSwitch *m_switch = new EthernetSwitch(this);
    //components.push_back(m_switch);
    for(int i=0;i<46;i++)
    {
        Server *s = new Server(this, dramSize, ssd, (i*320)+1, (i*320)+321);
        servers.push_back(s);
        cost += s->serverCost();
    }
    Server *last = new Server(this, dramSize, ssd, 14721, 15000);
    servers.push_back(last);
    cost += last->serverCost();
}

ServerRack::~ServerRack()
{

}

int ServerRack::rackCost()
{
    return cost;
}

int ServerRack::processRequest()
{
    return 0;
}
