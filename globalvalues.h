#ifndef GLOBALVALUES_H
#define GLOBALVALUES_H

#define LOADBALANCERCOST 10000
#define SWITCHCOST 8000
#define DRAMDELAY .013
#define SSDDELAY .130
#define HDDDELAY 4160
#define LBDELAY 1000
#define ESWITCHDELAY 0.25

typedef struct{
    int ipAddress;
    int serverNumber;
    int movieNumber;
    int packetNumber;
} RequestPacket;

typedef struct{
    double responseTime;
} ResponseType;

#endif // GLOBALVALUES_H
