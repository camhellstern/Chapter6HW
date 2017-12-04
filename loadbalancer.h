#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <datacentercomponent.h>
#include <ethernetswitch.h>
#include <QList>


class LoadBalancer : public DataCenterComponent
{
public:
    explicit LoadBalancer(QObject *parent = 0, int dramSize = 4, bool ssd = false);
    ~LoadBalancer();
    int lbCost();

signals:

public slots:
    void processRequest();

private:
    EthernetSwitch *switch1;
    EthernetSwitch *switch2;
    QList<QJsonObject> switch1Requests;
    QList<QJsonObject> switch2Requests;
    int cost;
};

#endif // LOADBALANCER_H
