
#ifndef SERVERRM_CLIENTLIST_H
#define SERVERRM_CLIENTLIST_H

#include "NodeClient.h"

class ClientList{
public:
    ClientList();
    NodeClient* head;
    int size;
    void insertLast(int dato);
    int getLast();
    int getAtIndex(int index);

};

#endif //SERVERRM_CLIENTLIST_H
