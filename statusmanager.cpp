#include "statusmanager.h"

SM::StatusManager::StatusManager(SM::status startStatus)
{
    this->statusStack.push(startStatus);
}


void SM::StatusManager::pushStatus(SM::status stat)
{
    this->statusStack.push(stat);
}

SM::status SM::StatusManager::popStatus()
{
    SM::status result = this->statusStack.top();
    this->statusStack.pop();
    return result;
}

SM::status SM::StatusManager::getStatus()
{
    return this->statusStack.top();
}

SM::StatusManager::~StatusManager()
{

}

