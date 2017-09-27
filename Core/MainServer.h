//
// Created by adrian on 24/09/17.
//

#ifndef REMOTEMEMORY_MAINSERVER_H
#define REMOTEMEMORY_MAINSERVER_H


#include "memoryManager.h"

class MainServer{
public:
    MemoryManager *storage;
    int socket_desc , client_sock , c;
    int *new_sock;

    struct sockaddr_in *server , *client;

    MainServer();
    int MainServerInit();
    static void *connection_handler(void * socket_desc);
    static rmRef_h interpretMessage(char* clientMessage);
    static char* createdMessage(rmRef_h bd);

};

#endif //REMOTEMEMORY_MAINSERVER_H
