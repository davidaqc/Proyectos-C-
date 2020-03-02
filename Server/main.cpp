#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <sstream>

using namespace std;

struct nodo{
    int nombre;//nombre del vertice o nodo
    struct nodo *sgte;
    struct arista *ady;//puntero hacia la primera arista del nodo
};

struct arista{
    struct nodo *destino;//puntero al nodo de llegada
    struct arista *sgte;
};

typedef struct nodo *Tnodo;//  Tipo Nodo
typedef struct arista *Tarista; //Tipo Arista

Tnodo p;//puntero cabeza
int clientSocket;
int temporal;

void entro_mensaje(string mensaje);
void insertar_nodo(string valor);
void mostrar_grafo();
void agrega_arista(Tnodo &, Tnodo &, Tarista &);
void insertar_arista(string ambos_valores);

int main()
{
    // Create a socket
    cout << "¡¡¡Wait for a connection!!!" << endl;
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Can't create a socket! Quitting" << endl;
        return -1;
    }

    // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);

    // Wait for a connection
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on

    memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        cout << host << " connected on port " << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }

    // Close listening socket
    close(listening);

    // While loop: accept and echo message back to client
    char buf[4096];

    while (true)
    {
        memset(buf, 0, 4096);

        // Wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cerr << "Error in recv(). Quitting" << endl;
            //break;
        }

        if (bytesReceived == 0)
        {
            cout << "Client disconnected " << endl;
            //break;
        }

        if(string(buf, 0, bytesReceived)== "i_n"){
            cout << "Opcion 1 elegida" <<endl;
            temporal = 0;
        }
        else if(string(buf, 0, bytesReceived)== "i_a"){
            cout << "Opcion 2 elegida" << endl;
            temporal = 1;
        }else if(string(buf, 0, bytesReceived)== "m_d"){
            cout << "Mostrar grafo" << endl;
            mostrar_grafo();
        }else{ // Demas botones, insetar nodo, etc.
            entro_mensaje(string(buf, 0, bytesReceived));
        }
    }

    // Close the socket
    close(clientSocket);
    return 0;
}

void entro_mensaje(string mensaje){
    if(temporal == 0){
        cout << "El modo <Insertar Nodo>, está activo." << endl;
        insertar_nodo(mensaje);
    }else if(temporal == 1){
        cout << "El modo <Insertar arista>, está activo" << endl;
        insertar_arista(mensaje);
    }else{
        cout << "Saliendo" << endl;
    }
};

void insertar_nodo(string valor){

    Tnodo t,nuevo=new struct nodo;
    int mensaje = stoi(valor);
    nuevo->nombre = mensaje;
    nuevo->sgte = NULL;
    nuevo->ady=NULL;

    if(p==NULL){
        p = nuevo;
        cout<<"PRIMER NODO...!!!" << endl;
    }
    else{
        t = p;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = nuevo;
        cout<<"NODO INGRESADO...!!!" << endl;
    }
}

/*                      AGREGAR ARISTA
    funcion que utilizada para agregar la arista a dos nodos
---------------------------------------------------------------------*/
void agrega_arista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo)
{
    Tarista q;
    if(aux->ady==NULL){
        aux->ady=nuevo;
        nuevo->destino=aux2;
        cout<<"PRIMERA ARISTA....!" << endl;
    }
    else{
        q=aux->ady;
        while(q->sgte!=NULL)
            q=q->sgte;
        nuevo->destino=aux2;
        q->sgte=nuevo;
        cout<<"ARISTA AGREGADA...!!!!" << endl;
    }
}

/*                      INSERTAR ARISTA
    funcion que busca las posiciones de memoria de los nodos
    y hace llamado a agregar_arista para insertar la arista
---------------------------------------------------------------------*/
void insertar_arista(string ambos_datos){

    // Convierte el string en valores separados
    int ini, fin;
    string s = ambos_datos;
    string delimiter = ",";
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        ini = stoi(token);
        s.erase(0, pos + delimiter.length());
    }
    fin = stoi(s);

    Tarista nuevo=new struct arista;
    Tnodo aux, aux2;

    if(p==NULL){
        cout<<"GRAFO VACIO...!!!!" << endl;
        return;
    }
    nuevo->sgte=NULL;
    aux=p;
    aux2=p;
    while(aux2!=NULL){
        if(aux2->nombre==fin){
            break;
        }
        aux2=aux2->sgte;
    }
    while(aux!=NULL){
        if(aux->nombre==ini){
            agrega_arista(aux,aux2, nuevo);
            return;
        }
        aux = aux->sgte;
    }
}

/*                      MOSTRAR GRAFO
    funcion que imprime un grafo en su forma enlazada
---------------------------------------------------------------------*/
void mostrar_grafo(){
    Tnodo ptr;
    Tarista ar;
    ptr=p;
    cout<<"NODO|LISTA DE ADYACENCIA\n";

    string lista_nodos = "";
    string lista_listaAdyacencia = "&";

    while(ptr!=NULL){
        cout<<"   "<<ptr->nombre<<"|";
        lista_listaAdyacencia += "$";
        lista_nodos += to_string(ptr->nombre);
        lista_nodos += ",";

        if(ptr->ady!=NULL){
            ar=ptr->ady;
            while(ar!=NULL){
                cout<<" "<<ar->destino->nombre;
                lista_listaAdyacencia += to_string(ar->destino->nombre);
                lista_listaAdyacencia += ",";
                ar=ar->sgte;
            }
        }else{
            lista_listaAdyacencia += ".";
            lista_listaAdyacencia += ",";
        }
        ptr=ptr->sgte;
        cout<<endl;
    }

    // Concatenacion de lista_nodos y lista_listaAdyacencia
    string message = lista_nodos + lista_listaAdyacencia;
    send(clientSocket, message.c_str(), message.size() + 1, 0);
}
