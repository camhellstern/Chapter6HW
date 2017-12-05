#include <QCoreApplication>
#include <QTime>
#include <datacenter.h>


#define DRAMLEVEL 3
#define STORAGELEVEL 3
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
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

    DataCenter *data = new DataCenter(NULL, DRAMLEVEL, STORAGELEVEL);


    return a.exec();
}
