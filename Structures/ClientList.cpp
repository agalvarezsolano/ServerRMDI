
#include "ClientList.h"
#include <cstdio>

ClientList::ClientList() {
    this->head = NULL;
    this->size = 0;
}

void ClientList::insertLast(int dato) {
    NodeClient* newNode = new NodeClient(dato);
    if (size == 0){
        this->head = newNode;
        this->size++;
    }else{
        NodeClient* current = this->head;
        while(current->next != NULL){
            current =  current->next;
        }
        current->next = newNode;
        this->size++;
    }
}

int ClientList::getLast() {
    if (size == 0){
        return -1;
    }else{
        NodeClient* current = this->head;
        while(current->next != NULL){
            current =  current->next;
        }
        return current->dato;
    }
}

int ClientList::getAtIndex(int index) {
    if(index < this->size){
        NodeClient* current = this->head;
        for (int i = 0; i != index ; ++i) {
            current =  current->next;
        }
        return current->dato;
    }else {
        return -1;
    }
}
