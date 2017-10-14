#include <iostream>
#include "Core/MainServer.h"


using namespace std;


void *startMainServer(void*) {
    cout << "Iniciando Hilo de Main Server" << endl;
    MainServer m1 = MainServer();
    m1.MainServerInit();
}

int main() {

    pthread_t mainServer;
    pthread_create(&mainServer, NULL, &startMainServer, NULL);
    cout << "Hilos creados" << endl;
    pthread_join(mainServer, NULL);
    return 0;
}
