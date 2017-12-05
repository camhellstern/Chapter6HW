#ifndef USER_H
#define USER_H

#include "globalvalues.h"

class User
{
public:
    int generateMovieNumber();
    int generateIP();
    int generatePacketNumber();

    void getSession();
    void issueRequest();

    User();

    int ipAddress;
    int serverNumber;
    int movieNumber;
    int packetNumber;

};

#endif // USER_H
