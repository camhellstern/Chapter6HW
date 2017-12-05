#ifndef GLOBALVALUES_H
#define GLOBALVALUES_H

#define LOADBALANCERCOST 10000
#define SWITCHCOST 300
#define DRAMDELAY 40
#define SSDDELAY 40
#define HDDDELAY 40
#define LBDELAY 10
#define ESWITCHDELAY 0.00025

typedef struct{
    int ipAddress;
    int movieNumber;
    int packetNumber;
} RequestPacket;

typedef struct{
    double responseTime;
} ResponseType;

#endif // GLOBALVALUES_H
