#include <QThread>
#include <QObject>
#include <random>

class request: public QObject
{
    Q_OBJECT
    QThread requestThread;
    
public slots: 

    //IP signal function
    void sendIp(const QString &ipParameter) {
        std::default_random_engine generator;
          
       //Generating random ip of type int between 1 to 10000000
           std::uniform_int_distribution<int> ipDistribution(1,10000000);
           int ipRand= distribution(generator);
                        
        emit ip(ipAddress);  
    }
    
    //Package signal function
    void sendPackage(const QString &packageParameter) {
          std::default_random_engine generator;
         
       //Generating random package of type int between 1 to 700
            std::uniform_int_distribution<int> packageDistribution(1,700);
            int packageRand= packageDistribution(generator);
            
        emit package(packageNum);       
    }
    
    //Movie signal function
    void sendMovie(const QString &movieParameter) {
        std::default_random_engine generator;
          
       //Generating random movie of type int between 1 to 15000
            std::exponential_int_distribution<int> packageDistribution(1.5);
            
        emit movie(movieNum);        
    }

//Signal slot for request
signals:
    void ip(int &ipAddress);
    void package(int &packageNum);
    void movie(int &movieNum);

};
