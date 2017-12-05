#include "datacentercomponent.h"

DataCenterComponent::DataCenterComponent(QObject *parent) : QObject(parent)
{

}

DataCenterComponent::~DataCenterComponent()
{

}

int DataCenterComponent::processRequest(RequestPacket request)
{
    return 0;
}
