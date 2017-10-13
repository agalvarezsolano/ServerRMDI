
#ifndef SERVERRM_NODECLIENT_H
#define SERVERRM_NODECLIENT_H

#include <cstdio>

class NodeClient{
public:
    int dato;
    NodeClient* next = NULL;
    NodeClient(int);

    NodeClient();
};

#endif //SERVERRM_NODECLIENT_H
