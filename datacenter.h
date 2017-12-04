#ifndef DATACENTER_H
#define DATACENTER_H

#include <QObject>
#include <QList>
#include <serverrack.h>
#include <router.h>

class DataCenter : public QObject
{
    Q_OBJECT
public:
    static int baseCost() {return 10694380;}
    explicit DataCenter(QObject *parent = 0, int dramParam = 1, int storageParam = 1);
    ~DataCenter();

signals:

public slots:

private:
    QList<Router *> routers;
    int routerCount;
};

#endif // DATACENTER_H
