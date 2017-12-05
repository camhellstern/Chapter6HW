#include "server.h"

Server::Server(QObject *parent, int dramSize, bool ssd, int start, int end) : DataCenterComponent(parent), movieRangeStart(start), movieRangeEnd(end)
{
    if(dramSize == 4)
    {
        if(ssd == false)
            cost = 58+34;
        else
            cost = 58+286;
        maxDRAMEntries = 2000;
    }
    else if(dramSize == 16)
    {
        if(ssd == false)
            cost = 34 + 231;
        else
            cost = 286 + 231;
        maxDRAMEntries = 8000;
    }
    else if(dramSize == 32)
    {
        if(ssd == false)
            cost = 34 + 462;
        else
            cost = 286 + 462;
        maxDRAMEntries = 16000;
    }
}

Server::~Server()
{

}

int Server::processRequest()
{
    return 0;
}

int Server::serverCost()
{
    return cost;
}
