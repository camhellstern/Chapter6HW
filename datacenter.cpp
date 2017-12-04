#include "datacenter.h"

DataCenter::DataCenter(QObject *parent, int dramParam, int storageParam) : QObject(parent)
{
    int cost = 0;
    while(cost < baseCost())
    {
        Router *r = new Router(this, dramParam, storageParam);
        routers.push_back(r);
        cost += r->routerCost();
    }
    routerCount = routers.size();
}

DataCenter::~DataCenter()
{

}
