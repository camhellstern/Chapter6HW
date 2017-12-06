#ifndef DATACENTER_H
#define DATACENTER_H

#include <QObject>
#include <QList>
#include <QtMath>
#include <globalvalues.h>
#include <serverrack.h>
#include <router.h>

class DataCenter : public QObject
{
    Q_OBJECT
public:
    explicit DataCenter(QObject *parent = 0, int dramParam = 1, int storageParam = 1);
    ~DataCenter();
    int completedRequests();
    int averageResponseTime();
    int ninetyFifthPercentileNormal();

signals:
    void sendRequest(RequestPacket request);
public slots:
    void processRequest(RequestPacket request);
    void processResponse(ResponseType response);

private:
    QList<ResponseType *> responses;
    QList<Router *> routers;
    int routerCount;
    int baseCost =11650380;
    int responseCount;
    int runningTotal;
};

#endif // DATACENTER_H
