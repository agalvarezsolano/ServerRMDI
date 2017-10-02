

#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include "MainServer.h"
#include <string.h>
#include <unistd.h>

using namespace std;
///@brief constructor vacio
MainServer::MainServer()
{

}
///@brief metodo que inicia el server y abre el socket
int MainServer::MainServerInit()
{
    int socket_desc , client_sock , c , *new_sock;
    struct sockaddr_in server , client;
    socket_desc = socket(AF_INET, SOCK_STREAM,0);
    if (socket_desc == -1){
        cout << "Error al crea el socket del Main Server" << endl;
    }
    cout << "Main Socket creado" << endl;

    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    server.sin_addr.s_addr = INADDR_ANY;

    if(bind(socket_desc,(struct sockaddr*)&server, sizeof(server)) < 0)
    {
        cout << "Error en Main Bind" << endl;
        return 1;
    }


    listen(socket_desc, 20);

    c = sizeof(struct sockaddr_in);

    cout << "Escuchando" << endl;
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c)) != -1) {

        cout << "Cliente aceptado" << endl;
        pthread_t sniffer_thread;
        //new_sock = static_cast<int *>(malloc(1));
        *new_sock = client_sock;

        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *) new_sock) < 0) {
            cout << "Hilo no creado" << endl;
            return 1;
        }
        cout << "Hilo creado" << endl;
    }
    if (client_sock < 0)
    {
        cout << "Cliente no aceptado" << endl;
        return 1;
    }

    return 0;
}
///@brief metodo que se crea llama cada vez que entra un cliente al server
void* MainServer::connection_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    int read_size;
    char* message, clientMessage[2000];

    while((read_size = recv(sock, clientMessage, 2000, 0)) > 0)
    {
        rmRef_h instance = interpretMessage(clientMessage);
        if(clientMessage[0] != 'm') {
            MemoryManager *storage = MemoryManager::getInstance();
            if (storage->mainMemory.findKey(instance.key)) {

                if (clientMessage[0] == 'n') {
                    storage->mainMemory.insertFirst(instance);
                    storage->cacheMemory.insertFirst(instance);
                    storage->HAMemory.insertFirst(instance);
                    cout << "New con exito" << endl;
                    message = '#' + message;
                    write(sock, message, strlen(message));


                }
                if (clientMessage[0] == 'g') {
                    if (storage->cacheMemory.findKey(instance.key)) {
                        instance = storage->cacheMemory.getRef(instance.key);
                        message = createdMessage(instance);
                        write(sock, message, strlen(message));
                    } else {
                        instance = storage->mainMemory.getRef(instance.key);
                        storage->cacheMemory.insertFirstCache(instance);
                        message = createdMessage(instance);
                        write(sock, message, strlen(message));
                    }


                }
                if (clientMessage[0] == 'd') {
                    storage->mainMemory.deleteKey(instance.key);
                    storage->cacheMemory.deleteKey(instance.key);
                    storage->HAMemory.deleteKey(instance.key);
                    cout << "Delete con exito" << endl;
                    message = '#' + message;
                    write(sock, message, strlen(message));

                }
            } else {
                cout << "Key ya existente" << endl;
                message = 'e' + message;
                write(sock, message, strlen(message));

            }
        }else{

        }
    }
}
///@brief interpreta el mensaje enviado por el cliente
///@tparam clientMessage mensaje del cliente
rmRef_h MainServer::interpretMessage(char *clientMessage){
    rmRef_h instance;
    instance.referencias = 1;
    int i = 1;
    int type;
    type = 0;
    while (clientMessage[i] != '#'){
        if(clientMessage[0] == 'n'){
            string word;
            while (clientMessage[i] != '@'){
                string c;
                char bd = clientMessage[i];
                c = bd;
                word = word + c;
                i++;
            }
            if (type == 0) {
                char *key;
                key = (char *) word.c_str();
                instance.key = key;
                type++;
                i++;
            }if(type == 1){
                int* value;
                value = (int*) word.c_str();
                instance.value = value;
                type++;
                i++;
            }if(type == 2){
                int value_size;
                value_size =  atoi(word.c_str());
                instance.value_size = value_size;
                type++;
                i++;
            }

        }
        if(clientMessage[0] == 'g' || clientMessage[0] == 'd'){
            string word;
            while (clientMessage[i] != '@'){
                string c;
                char bd = clientMessage[i];
                c = bd;
                word = word + c;
                i++;
            }
            char *key;
            key = (char *) word.c_str();
            instance.key = key;
        }
    }

    return instance;
}
///@brief crea el mensaje de vuelta al cliente
///@tparam bd instancia que se le va a enviar al cliente
char* MainServer::createdMessage(rmRef_h bd) {
    char* message;
    string  word;
    string m,p,q,o;
    m = bd.key;
    word = word + m + '@';
    int* s = (int *)bd.value;
    o = *s;
    word = word +  o + '@';
    q = bd.value_size;
    word = word + q + '@' +'#';
    message =(char*) word.c_str();
    return message;
}
