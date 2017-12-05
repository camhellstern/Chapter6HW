#ifndef DATACENTERCOMPONENT_H
#define DATACENTERCOMPONENT_H

#include <QObject>
#include <QtTest/qtest.h>
#include <globalvalues.h>


class DataCenterComponent : public QObject
{
    Q_OBJECT
public:
    explicit DataCenterComponent(QObject *parent = 0);
    virtual ~DataCenterComponent();

signals:
    void sendToNext();

public slots:
    virtual int processRequest(RequestPacket request);
};

#endif // DATACENTERCOMPONENT_H
