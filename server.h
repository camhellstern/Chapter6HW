#ifndef SERVER_H
#define SERVER_H

#include <datacentercomponent.h>
#include <server.h>
#include <QList>

class Server : public DataCenterComponent
{
public:
    explicit Server(QObject *parent = 0, int dramSize = 4, bool ssd = false, int start = 1, int end = 320);
    ~Server();
    int serverCost();

public slots:
    int processRequest();

private:
    QList<RequestPacket> requests;
    int cost;
    int maxDRAMEntries;
    int DRAMEntries;
    int movieRangeStart;
    int movieRangeEnd;

};

#endif // SERVER_H
