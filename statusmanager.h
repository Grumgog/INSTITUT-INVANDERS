#ifndef STATUSMANAGER_H
#define STATUSMANAGER_H

#include <stack>

// Класс реализует простейший менеджер состояний для
//
namespace SM
{
class StatusManager;
enum status{mainMenu, playScreen, pause, deathScrean};
}

namespace SM
{
class StatusManager
{
private:
    std::stack<SM::status> statusStack;

public:
    StatusManager(SM::status startStatus);

    void pushStatus(SM::status stat);
    SM::status popStatus();
    SM::status getStatus();

    ~StatusManager();
};

}


#endif // STATUSMANAGER_H
