
#ifndef REMOTEMEMORY_MEMORYMANAGER_H
#define REMOTEMEMORY_MEMORYMANAGER_H


#include "../Structures/LinkedList.h"
#include "../Structures/ClientList.h"

class MemoryManager{
public:
    static MemoryManager* getInstance();
    LinkedList cacheMemory;
    LinkedList mainMemory;
    ClientList clientList;
private:
    MemoryManager();
    static MemoryManager* instance;

};



#endif //REMOTEMEMORY_MEMORYMANAGER_H
