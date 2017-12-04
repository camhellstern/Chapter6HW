#ifndef SERVER_H
#define SERVER_H

#include <datacentercomponent.h>

class Server : public DataCenterComponent
{
public:
    explicit Server(QObject *parent = 0, bool ssd = false);
    ~Server();
    int processRequest();

public slots:
};

#endif // SERVER_H
