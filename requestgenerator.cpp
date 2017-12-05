#include "requestgenerator.h"

int Request_Generator::getIp()
{
  randGenerator();
  return ip;
}

int Request_Generator::getPackage()
{
  randGenerator();
  return package;
}

int Request_Generator::getMovie()
{
  randGenerator();
  return movie;
}

void Request_Generator::randGenerator()
{
  std::default_random_engine generator;
  std::uniform_int_distribution<int> ipDistribution(1,10000000);
  std::uniform_int_distribution<int> packageDistribution(1,700);
  std::uniform_int_distribution<int> movieDistribution(1,15000); //Will be changed to exponential distribution
  ip = ipDistribution(generator);
  package = packageDistribution(generator);
  movie = movieDistribution(generator);
}
