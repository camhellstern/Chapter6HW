#include "datacenter.h"

DataCenter::DataCenter(QObject *parent, int dramParam, int storageParam) : QObject(parent)
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
    responseCount++;
    runningTotal += response.responseTime;
}

int DataCenter::completedRequests()
{
    return responses.size();
}

int DataCenter::averageResponseTime() {
    return int(runningTotal / responseCount);
}

int DataCenter::ninetyFifthPercentileNormal()
{
    int mean = averageResponseTime();
    long stdVar = 0;
    long meanStdVar = 0;

    for (ResponseType * r: responses)
    {
        stdVar += qPow(r->responseTime - mean, 2);
    }

    stdVar = qPow(stdVar / (responses.length() - 1), 0.5);
    meanStdVar = stdVar / qPow(mean, 0.5);
    return mean + 1.96 * meanStdVar;
}

int DataCenter::ninetyFifthPercentileExponential()
{
    int rho = averageResponseTime() / (routerCount * 46);
    int t = averageResponseTime()/(1.0-rho);
    return t * log(100.0/(100.0-95.0));
} // https://pdfs.semanticscholar.org/1d49/6ff7cd1b810cc56f189de861b6efd484618d.pdf
