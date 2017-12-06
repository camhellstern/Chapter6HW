#include "datacenter.h"

DataCenter::DataCenter(QObject *parent, int dramParam, int storageParam) : QObject(parent)
{
    int cost = 0;
    while(cost < baseCost)
    {
        Router *r = new Router(this, dramParam, storageParam);
        cost += r->routerCost();
        if(cost >= baseCost)
            break;
        else{
            routers.push_back(r);
            connect(this, &DataCenter::sendRequest, r, &Router::processRequest);
            connect(r, &Router::sendResponse, this, &DataCenter::processResponse);
        }
    }
    routerCount = routers.size();
    int routerRange = 10000000/routerCount;
    for(int i=0;i<routerCount;i++)
    {
        int routerStart = i*routerRange;
        if(routerStart + routerRange > 10000000)
            routers.at(i)->setIPRange(routerStart, 10000000);
        else
            routers.at(i)->setIPRange(routerStart, routerStart+routerRange);
    }
}

DataCenter::~DataCenter()
{

}

void DataCenter::processRequest(RequestPacket request)
{
    emit sendRequest(request);
    //return 0;
}

void DataCenter::processResponse(ResponseType response)
{
    responses.push_back(&response);
}

int DataCenter::completedRequests()
{
    return responses.size();
}
