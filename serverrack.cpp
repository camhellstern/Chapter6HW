#include "serverrack.h"

ServerRack::ServerRack(QObject *parent, int dramSize, bool ssd) : QObject(parent)
{
    cost = 0;
    //EthernetSwitch *m_switch = new EthernetSwitch(this);
    //components.push_back(m_switch);
    for(int i=0;i<46;i++)
    {
        Server *s = new Server(this, dramSize, ssd, (i*320)+1, (i*320)+321);
        s->setNumber(i+1);
        servers.push_back(s);
        cost += s->serverCost();
        connect(this, &ServerRack::sendRequest, s, &Server::processRequest);
        connect(s, &Server::sendResponse, this, &ServerRack::processResponse);
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

void ServerRack::processRequest(RequestPacket request)
{
    emit sendRequest(request);
    //return 0;
}

void ServerRack::processResponse(ResponseType *response)
{
    response->responseTime += ESWITCHDELAY;
    emit sendResponse(response);
}
