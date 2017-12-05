#ifndef SERVER_H
#define SERVER_H

#include <globalvalues.h>
#include <QObject>
#include <server.h>
#include <QList>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0, int dramSize = 4, bool ssd = false, int start = 1, int end = 320);
    ~Server();
    int serverCost();

signals:
    void sendResponse(ResponseType response);

public slots:
    void processRequest(RequestPacket request);

private:
    QList<RequestPacket> dram;
    int cost;
    int maxDRAMEntries;
    int DRAMEntries;
    int movieRangeStart;
    int movieRangeEnd;
    bool isSSD;

};

#endif // SERVER_H
