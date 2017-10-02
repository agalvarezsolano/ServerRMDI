
#include "memoryManager.h"


///@brief Singleton que tiene las instancias de las memorias de los server
MemoryManager* MemoryManager::instance = 0;

MemoryManager *MemoryManager::getInstance() {
    if (instance == 0){
        instance = new MemoryManager();
    }
    return instance;
}

MemoryManager::MemoryManager() {

}
