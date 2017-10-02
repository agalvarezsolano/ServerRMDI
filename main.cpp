#include <iostream>
#include <pthread.h>
#include "Core/MainServer.h"
#include "Core/ServerHA.h"


using namespace std;


void *startMainServer(void*) {
    cout << "Iniciando Hilo de Main Server" << endl;
    MainServer m1 = MainServer();
    m1.MainServerInit();
}

void *startServerHA(void*){
    cout << "Iniciando Hilo de Server HA" << endl;
    ServerHA m2 = ServerHA();
    m2.ServerHAinit();
}

int main() {

    pthread_t mainServer;
    pthread_t serverHA;

    pthread_create(&mainServer, NULL, &startMainServer, NULL);
    pthread_create(&serverHA, NULL, &startServerHA, NULL);
    cout << "Hilos creados" << endl;
    pthread_join(mainServer, NULL);
    pthread_join(serverHA, NULL);

    return 0;
}
