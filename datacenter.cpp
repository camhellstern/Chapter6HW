#include "datacenter.h"

DataCenter::DataCenter(QObject *parent, int dramParam, int storageParam, int users) : QObject(parent)
{
    int cost = 0;
    responseCount = 0;
    runningTotal = 0;
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
    int routerRange = users/routerCount;
    for(int i=0;i<routerCount;i++)
    {
        int routerStart = i*routerRange;
        if(routerStart + routerRange > users)
            routers.at(i)->setIPRange(routerStart, users);
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

void DataCenter::processResponse(ResponseType *response)
{
    responses.push_back(response);
    responseCount++;
    runningTotal += response->responseTime;
}

int DataCenter::completedRequests()
{
    return responses.size();
}

double DataCenter::averageResponseTime() {
    return (runningTotal / responseCount);
}

double DataCenter::ninetyFifthPercentileNormal()
{
    double mean = averageResponseTime();
    double stdVar = 0;
    double meanStdVar = 0;

    for (ResponseType * r: responses)
    {
        stdVar += qPow(r->responseTime - mean, 2);
    }

    stdVar = qPow(stdVar / (responses.length() - 1), 0.5);
    meanStdVar = stdVar / qPow(mean, 0.5);
    return mean + 1.96 * meanStdVar;
}

double DataCenter::ninetyFifthPercentileExponential()
{
    double mu = 4 / averageResponseTime();
    double rho = 0.035 / (routerCount * 47 * 62 * 4 * mu);
    double t = (1.0/mu)+(rho/(2.0*mu*(1.0-rho)));
    return t * 2.0*((1.0/(mu*(1.0-rho)))*sqrt((rho/3.0)-(rho*rho/12.0)));
} // https://pdfs.semanticscholar.org/1d49/6ff7cd1b810cc56f189de861b6efd484618d.pdf
