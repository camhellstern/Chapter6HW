#include <user.h>
#include <stdlib.h>
#include <random>

User::User()
{
    this->ipAddress = this->generateIP();
    getSession();
}
void User::getSession() {
    this->movieNumber = this->generateMovieNumber();
    this->packetNumber = this->generatePacketNumber();
    this->serverNumber = this->generateServerNumber();
}

RequestPacket User::getRequest() {
    //if we finished the movie start a new one
    if(this->packetNumber > 700) {
        getSession();
    }
    RequestPacket packet;
    packet.ipAddress = this->ipAddress;
    packet.movieNumber = this->movieNumber;
    packet.packetNumber = this->packetNumber;
    packet.serverNumber = this->serverNumber;
    //issue packet to farm
    //request next packet
    this->packetNumber += 1;
    return packet;
}

int User::generateIP() {
    static std::default_random_engine generator;
    std::uniform_int_distribution<int> ipDistribution(1,10000);
    return ipDistribution(generator);
}

int User::generateMovieNumber() {
    static std::default_random_engine generator;
    std::exponential_distribution<> movieDistribution(0.035); //Will be changed to exponential distribution
    return movieDistribution(generator);
}

int User::generatePacketNumber() {
    static std::default_random_engine generator;
      std::uniform_int_distribution<int> packageDistribution(1,700);
      return packageDistribution(generator);
}

int User::generateServerNumber() {
    static std::default_random_engine generator;
    std::uniform_int_distribution<int> serverDistribution(1, 47);
    return serverDistribution(generator);
}
