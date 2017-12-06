#include "user.h"
#include "stdlib.h"
#include "random"

User::User()
{
    this->ipAddress = this->generateIP();
    getSession();
}
void User::getSession() {
    this->movieNumber = this->generateMovieNumber();
    this->packetNumber = this->generatePacketNumber();
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
    //issue packet to farm
    //request next packet
    this->packetNumber += 1;
    return packet;
}

int User::generateIP() {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> ipDistribution(1,10000000);
    return ipDistribution(generator);
}

int User::generateMovieNumber() {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> movieDistribution(1,15000); //Will be changed to exponential distribution
    return movieDistribution(generator);
}

int User::generatePacketNumber() {
    std::default_random_engine generator;
      std::uniform_int_distribution<int> packageDistribution(1,700);
      return packageDistribution(generator);
}
