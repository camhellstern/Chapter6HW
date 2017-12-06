#ifndef USER_H
#define USER_H

#include "globalvalues.h"

class User
{
private :
    void getSession();
    int generateMovieNumber();
    int generateIP();
    int generatePacketNumber();
public:
    RequestPacket getRequest();
    User();

    //Object variables
    int ipAddress;
    int serverNumber;
    int movieNumber;
    int packetNumber;

};

#endif // USER_H
