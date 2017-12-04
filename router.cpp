#include "router.h"

Router::Router(QObject *parent, int dramSize, int storageParam) : DataCenterComponent(parent)
{
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
}

Router::~Router()
{

}

int Router::routerCost()
{
    return cost;
}
