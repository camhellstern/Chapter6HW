#include <QCoreApplication>


#define DRAMLEVEL 4
#define STORAGELEVEL 4
#define LOADBALANCERCOST 10000
#define SWITCHCOST 300
#define SERVERCOST 5000

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    return a.exec();
}
