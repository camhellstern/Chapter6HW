#include <QCoreApplication>
#include <QTime>
#include "user.h"
#include <datacenter.h>
#include <globalvalues.h>


int DRAMLEVEL;
int STORAGELEVEL;
int CYCLES;
int USERS;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(argc != 5) {
        printf("USAGE - DataCenterProject <DRAMLEVEL 1-3> <STORAGELEVEL 1-3> <CYCLES (INT)>");
    } else {
        DRAMLEVEL =  QString(argv[1]).toInt();
        STORAGELEVEL = QString(argv[2]).toInt();
        CYCLES = QString(argv[3]).toInt();
        USERS = QString(argv[4]).toInt();
    }

    if(DRAMLEVEL == 1)
    {
        if(STORAGELEVEL == 1)
            printf("DRAM Capacity: 4GB, Storage Format: All HDD\n");
        else if(STORAGELEVEL == 2)
            printf("DRAM Capacity: 4GB, Storage Format: Half HDD Half SSD\n");
        else
            printf("DRAM Capacity: 4GB, Storage Format: All SSD\n");
    }
    else if(DRAMLEVEL == 2)
    {
        if(STORAGELEVEL == 1)
            printf("DRAM Capacity: 16GB, Storage Format: All HDD\n");
        else if(STORAGELEVEL == 2)
            printf("DRAM Capacity: 16GB, Storage Format: Half HDD Half SSD\n");
        else
            printf("DRAM Capacity: 16GB, Storage Format: All SSD\n");
    }
    else
    {
        if(STORAGELEVEL == 1)
            printf("DRAM Capacity: 32GB, Storage Format: All HDD\n");
        else if(STORAGELEVEL == 2)
            printf("DRAM Capacity: 32GB, Storage Format: Half HDD Half SSD\n");
        else
            printf("DRAM Capacity: 32GB, Storage Format: All SSD\n");
    }

    DataCenter *data = new DataCenter(NULL, DRAMLEVEL, STORAGELEVEL, USERS);

    User *userGroup = new User[USERS];

    //sanity check
    printf("IP: %d, Movie: %d, Packet: %d\n", userGroup[0].ipAddress, userGroup[0].movieNumber, userGroup[0].packetNumber);

    //Get to making some requests
    printf("Running %d cycles for %d users...\n\n", CYCLES, USERS);

    for(int i = 0; i < CYCLES; i++) {
        printf("Cycle %d...", i);
        for(int j = 0; j < USERS; j++) {
            data->processRequest(userGroup[j].getRequest());
        }
        printf("DONE\n");
    }

    //while(data->completedRequests() < (CYCLES*USERS));

    printf("Response Time:\n %f \n",data->averageResponseTime());
    printf("Normal Distribution:\n95 percent of responses are below: %f \n", data->ninetyFifthPercentileNormal());
    printf("Exponential Poisson Distribution:\n95 percent of responses are below: %f \n", data->ninetyFifthPercentileExponential());

    return a.exec();
}
