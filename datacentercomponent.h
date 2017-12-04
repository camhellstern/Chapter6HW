#ifndef DATACENTERCOMPONENT_H
#define DATACENTERCOMPONENT_H

#include <QObject>
#include <QtTest/qtest.h>
#include <QJsonObject>

class DataCenterComponent : public QObject
{
    Q_OBJECT
public:
    explicit DataCenterComponent(QObject *parent = 0);
    virtual ~DataCenterComponent();
    virtual int processRequest();

signals:
    void sendToNext();

public slots:
};

#endif // DATACENTERCOMPONENT_H
