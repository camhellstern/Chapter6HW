#include "server.h"

Server::Server(QObject *parent, int dramSize, bool ssd, int start, int end) : QObject(parent), movieRangeStart(start), movieRangeEnd(end)
{
    cost = 0;
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
    isSSD = ssd;
}

Server::~Server()
{

}

void Server::processRequest(RequestPacket request)
{
    if(request.movieNumber >= movieRangeStart && request.movieNumber <= movieRangeEnd)
    {
        ResponseType response;
        if(dram.size() == 0)
        {
            dram.push_back(request);
            if(isSSD)
            {
                response.responseTime = SSDDELAY;
                emit sendResponse(response);
            }
            else
            {
                response.responseTime = HDDDELAY;
                emit sendResponse(response);
            }
        }
        else
        {
            for(int i=0;i<dram.size();i++)
            {
                if(dram.at(i).movieNumber == request.movieNumber && dram.at(i).packetNumber == request.packetNumber)
                {
                    dram.removeAt(i);
                    dram.push_back(request);
                    response.responseTime = DRAMDELAY;
                    emit sendResponse(response);
                }
            }
            if(dram.size() < maxDRAMEntries)
            {
                dram.push_back(request);
                if(isSSD)
                {
                    response.responseTime = SSDDELAY;
                }
                else
                {
                    response.responseTime = HDDDELAY;
                }
            }
            else
            {
                dram.pop_front();
                dram.push_back(request);
                if(isSSD)
                {
                    response.responseTime = SSDDELAY;
                    emit sendResponse(response);
                }
                else
                {
                    response.responseTime = HDDDELAY;
                    emit sendResponse(response);
                }
            }
        }
    }
}

int Server::serverCost()
{
    return cost;
}
