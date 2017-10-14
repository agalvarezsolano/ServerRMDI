

#ifndef SERVERRM_GARBAGECOLLECTOR_H
#define SERVERRM_GARBAGECOLLECTOR_H

#include "memoryManager.h"

class GarbageCollector{
public:
    MemoryManager *storage;
    void start();
    GarbageCollector();

};
#endif //SERVERRM_GARBAGECOLLECTOR_H
