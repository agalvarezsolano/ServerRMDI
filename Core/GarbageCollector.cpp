

#include "GarbageCollector.h"

///@brief constructor instancia la clase singletoon MemoryManager para optener las memorias actuales
GarbageCollector::GarbageCollector()
{
    this->storage = MemoryManager::getInstance();
}

///@brief Ejecuta el metodo de liberar memoria de la lista
void GarbageCollector::start()
{
    this->storage->mainMemory.freeMemory();
}
