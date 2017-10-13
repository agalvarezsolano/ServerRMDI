

#ifndef REMOTEMEMORY_MAINSERVER_H
#define REMOTEMEMORY_MAINSERVER_H


#include "memoryManager.h"
#include "../Structures/ClientList.h"

class MainServer{
public:
    int ip = 8888;
    static MemoryManager *storage;
    MainServer();
    int MainServerInit();
    static void *connection_handler(void * socket_desc);
    static rmRef_h interpretMessage(char* clientMessage);
    static char* createdMessage(rmRef_h bd);

};

#endif //REMOTEMEMORY_MAINSERVER_H
