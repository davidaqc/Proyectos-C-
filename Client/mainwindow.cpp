#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <curses.h>

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList titulos;
    ui->tableWidget->setColumnCount(2);
    titulos << "Nodo" << "L_Adyacente";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

void vaciar_aristas(Tnodo &);
void eliminar_nodo();
void eliminar_arista();
void mostrar_aristas();
void crearVentanaDialogo();
int conexion();
void enviar_msj();

int sock = socket(AF_INET, SOCK_STREAM, 0);

int conexion(){
    //	Create a socket
    cout << "Pausa";
    //int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        return 1;
    }

    //	Create a hint structure for the server we're connecting with
    int port = 54000;
    string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return 1;
    }
    return 0;
}

void enviar_msj(string userInput){
    send(sock, userInput.c_str(), userInput.size() + 1, 0);
}

void MainWindow::on_aceptar_clicked()
{
    QString a=ui->lineEdit->text();
    int op = a.split(" ")[0].toInt();

    switch(op)
    {
    case 1:
        ui->aceptar_nodo->setEnabled(true);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton->setEnabled(false);
        enviar_msj("i_n");
        break;
    case 2:
        ui->aceptar_nodo->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton->setEnabled(false);
        enviar_msj("i_a");
        break;
    case 3:
        ui->aceptar_nodo->setEnabled(false);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton->setEnabled(false);
        //eliminar_nodo();
        break;
    case 4:
        ui->aceptar_nodo->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton->setEnabled(true);
        //eliminar_arista();
        break;
    default:
        cout<<"OPCION NO VALIDA...!!!";
        crearVentanaDialogo();
        break;
    }
    ui->lineEdit->setText("");
}

void MainWindow::on_aceptar_nodo_clicked()
{
    QString a=ui->lineEdit_2->text();
    int op = a.split(" ")[0].toInt();
    ui->lineEdit_2->setText("");
    enviar_msj(to_string(op));
}

// Insertar arista.
void MainWindow::on_pushButton_2_clicked(){
    QString a=ui->lineEdit_3->text();
    int ini = a.split(" ")[0].toInt();

    QString b=ui->lineEdit_4->text();
    int fin = b.split(" ")[0].toInt();

    QString c=ui->lineEdit_7->text();
    int fin1 = c.split(" ")[0].toInt();

    string ambos_datos = to_string(ini) + "," + to_string(fin) + "," + to_string(fin1);
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_7->setText("");
    enviar_msj(ambos_datos);
}

void crearVentanaDialogo(){
    Dialog *ventana1 = new Dialog();
    ventana1->setModal(true);
    ventana1->show();
}

void MainWindow::on_pushButton_4_clicked(){

    enviar_msj("m_d");
    // Actualiza el tableWidget
    while(ui->tableWidget->rowCount()!=0){
        ui->tableWidget->removeRow(0);
    }

    char buf[4096];
    //		Wait for response
    memset(buf, 0, 4096);
    int bytesReceived = recv(sock, buf, 4096, 0);
    if (bytesReceived == -1){
        cout << "There was an error getting response from server\r\n";
    }
    else{
        // ----------------------------------------------------
        // Separar el mensaje en dos.
        string l_n;
        string l_lA;
        string s0 = string(buf, bytesReceived);
        string delimiter0 = "&";
        size_t pos0 = 0;
        string token0;
        while ((pos0 = s0.find(delimiter0)) != string::npos) {
            token0 = s0.substr(0, pos0);
            l_n = token0;
            s0.erase(0, pos0 + delimiter0.length());
        }
        l_lA = s0;
        // ----------------------------------------------------

        // Convierte el string en valores separados
        string s = l_n;
        string delimiter = ",";
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, NODO,
                                     new QTableWidgetItem(
                                         QString::fromStdString(token)));
            s.erase(0, pos + delimiter.length());
        }

        string palabra= l_lA;
        palabra.erase(0,1); // quitar el primer simbolo

        // Convierte el string en valores separados
        string s2 = palabra + "$";
        string delimiter2 = "$";
        size_t pos2 = 0;
        string token2;
        int c= 0;
        while ((pos2 = s2.find(delimiter2)) != string::npos) {
             token2 = s2.substr(0, pos2);
             ui->tableWidget->setItem(c, LISTA,
                                      new QTableWidgetItem(
                                          QString::fromStdString(token2)));
             s2.erase(0, pos2 + delimiter2.length());
             c++;
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    conexion();
}

void MainWindow::on_toolButton_clicked(){
    enviar_msj("g_d");
    QString a=ui->lineEdit_5->text();
    int ini = a.split(" ")[0].toInt();

    QString b=ui->lineEdit_6->text();
    int fin = b.split(" ")[0].toInt();

    string ambos_datos = to_string(ini) + "," + to_string(fin);
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    enviar_msj(ambos_datos);

    // Recibir msj
    char buf[4096];
    //		Wait for response
    memset(buf, 0, 4096);
    int bytesReceived = recv(sock, buf, 4096, 0);
    if (bytesReceived == -1){
        cout << "There was an error getting response from server\r\n";
    }
    else{
        //Mostrar camino mas corto
        cout << string(buf, bytesReceived) << endl;
        //ui->label_10->setText("");
        ui->label_10->setText(QString::fromStdString(string(buf, bytesReceived)));
    }
}
