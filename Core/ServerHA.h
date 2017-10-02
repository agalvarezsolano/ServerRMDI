
#ifndef REMOTEMEMORY_SERVERHA_H
#define REMOTEMEMORY_SERVERHA_H


#include "memoryManager.h"

class ServerHA{
public:
    int ip = 5555;
    MemoryManager *storage;
    ServerHA();
    int ServerHAinit();
    static void *connection_handler(void *);
    static rmRef_h interpretMessage(char*);
    static char* createdMessage(rmRef_h bd);
};


#endif //REMOTEMEMORY_SERVERHA_H
