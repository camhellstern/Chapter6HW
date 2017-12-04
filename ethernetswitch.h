#ifndef ETHERNETSWITCH_H
#define ETHERNETSWITCH_H

#include <datacentercomponent.h>
#include <QList>
#include <serverrack.h>


class EthernetSwitch : public DataCenterComponent
{
public:
    explicit EthernetSwitch(QObject *parent = 0, int dramSize = 4, bool ssd = false);
    ~EthernetSwitch();
    int switchCost();

signals:

public slots:
    void processRequest();

private:
    int cost;
    QList<ServerRack *> racks;


};

#endif // ETHERNETSWITCH_H
