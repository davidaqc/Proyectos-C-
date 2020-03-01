#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <curses.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList titulos;
    ui->tableWidget->setColumnCount(2);
    titulos << "Nodo" << "Lista";
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

void menu();
void insertar_nodo();
void agrega_arista(Tnodo &, Tnodo &, Tarista &);
void insertar_arista();
void vaciar_aristas(Tnodo &);
void eliminar_nodo();
void eliminar_arista();
void mostrar_grafo();
void mostrar_aristas();

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
        insertar_nodo();
        break;
    case 2:
        ui->aceptar_nodo->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton->setEnabled(false);
        insertar_arista();
        break;
    case 3:
        ui->aceptar_nodo->setEnabled(false);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton->setEnabled(false);
        eliminar_nodo();
        break;
    case 4:
        ui->aceptar_nodo->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton->setEnabled(true);
        //eliminar_arista();
        break;
    case 5: mostrar_grafo();
        break;
    case 6: mostrar_aristas();
        break;
    default: cout<<"OPCION NO VALIDA...!!!";
        break;
    }
}

void MainWindow::on_aceptar_nodo_clicked()
{
    Tnodo t,nuevo=new struct nodo;
    cout<<"INGRESE VARIABLE:";
    //cin>>nuevo->nombre;
    QString a=ui->lineEdit_2->text();
    int op = a.split(" ")[0].toInt();

    nuevo->nombre = op;
    nuevo->sgte = NULL;
    nuevo->ady=NULL;

    if(p==NULL)
    {
        p = nuevo;
        cout<<"PRIMER NODO...!!!";
    }
    else
    {
        t = p;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = nuevo;
        cout<<"NODO INGRESADO...!!!";
    }
}


/*                      INSERTAR NODO AL GRAFO
---------------------------------------------------------------------*/
void insertar_nodo()
{
}

/*                      AGREGAR ARISTA
    funcion que utilizada para agregar la arista a dos nodos
---------------------------------------------------------------------*/
void agrega_arista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo)
{
    Tarista q;
    if(aux->ady==NULL)
    {   aux->ady=nuevo;
        nuevo->destino=aux2;
        cout<<"PRIMERA ARISTA....!";
    }
    else
    {   q=aux->ady;
        while(q->sgte!=NULL)
            q=q->sgte;
        nuevo->destino=aux2;
        q->sgte=nuevo;
        cout<<"ARISTA AGREGADA...!!!!";
    }

}
/*                      INSERTAR ARISTA
    funcion que busca las posiciones de memoria de los nodos
    y hace llamado a agregar_arista para insertar la arista
---------------------------------------------------------------------*/
void insertar_arista()
{
}

/*          FUNCION PARA BORRAR TODAS LAS ARISTAS DE UN NODO
    esta funcion es utilizada al borrar un nodo pues si tiene aristas
    es nesesario borrarlas tambien y dejar libre la memoria
---------------------------------------------------------------------*/
void vaciar_aristas(Tnodo &aux)
{
    Tarista q,r;
    q=aux->ady;
    while(q->sgte!=NULL)
    {
        r=q;
        q=q->sgte;
        delete(r);
    }
}
/*                      ELIMINAR NODO
    funcion utilizada para eliminar un nodo del grafo
    pero para eso tambien tiene que eliminar sus aristas por lo cual
    llama a la funcion vaciar_aristas para borrarlas
---------------------------------------------------------------------*/
void eliminar_nodo()
{   char var;
    Tnodo aux,ant;
    aux=p;
    cout<<"ELIMINAR UN NODO\n";
    if(p==NULL)
     {
         cout<<"GRAFO VACIO...!!!!";
         return;
     }
    cout<<"INGRESE NOMBRE DE VARIABLE:";
    cin>>var;

    while(aux!=NULL)
    {
        if(aux->nombre==var)
        {
            if(aux->ady!=NULL)
                vaciar_aristas(aux);

            if(aux==p)
            {

                    p=p->sgte;
                    delete(aux);
                    cout<<"NODO ELIMINADO...!!!!";
                    return;



            }
            else
            {
                ant->sgte = aux->sgte;
                delete(aux);
                cout<<"NODO ELIMINADO...!!!!";
                return;
            }
        }
        else
        {
            ant=aux;
            aux=aux->sgte;
         }
    }

}

/*                      ELIMINAR ARISTA
    funcion utilizada para eliminar una arista
---------------------------------------------------------------------*/
void eliminar_arista()
{
char ini, fin;
    Tnodo aux, aux2;
    Tarista q,r;
    cout<<"\n ELIMINAR ARISTA\n";
    cout<<"INGRESE NODO DE INICIO:";
    cin>>ini;
    cout<<"INGRESE NODO FINAL:";
    cin>>fin;
    aux=p;
    aux2=p;
    while(aux2!=NULL)
    {
        if(aux2->nombre==fin)
        {
            break;
        }
        else
        aux2=aux2->sgte;
    }
     while(aux!=NULL)
    {
        if(aux->nombre==ini)
        {
            q=aux->ady;
            while(q!=NULL)
            {
                if(q->destino==aux2)
                {
                    if(q==aux->ady)
                        aux->ady=aux->ady->sgte;
                    else
                        r->sgte=q->sgte;
                    delete(q);
                    cout<<"ARISTA  "<<aux->nombre<<"----->"<<aux2->nombre<<" ELIMINADA.....!!!!";
                    return;
                }
            }
            r=q;
            q=q->sgte;
        }
        aux = aux->sgte;
    }
}
/*                      MOSTRAR GRAFO
    funcion que imprime un grafo en su forma enlazada
---------------------------------------------------------------------*/
void mostrar_grafo()
{
}

/*                      MOSTRAR ARISTAS
    funcion que muestra todas las aristas de un nodo seleccionado
---------------------------------------------------------------------*/
void mostrar_aristas()
{
    Tnodo aux;
    Tarista ar;
    char var;
    cout<<"MOSTRAR ARISTAS DE NODO\n";
    cout<<"INGRESE NODO:";
    cin>>var;
    aux=p;
    while(aux!=NULL)
    {
        if(aux->nombre==var)
        {
            if(aux->ady==NULL)
            {   cout<<"EL NODO NO TIENE ARISTAS...!!!!";
                return;
             }
            else
            {
                cout<<"NODO|LISTA DE ADYACENCIA\n";
                cout<<"   "<<aux->nombre<<"|";
                ar=aux->ady;

                while(ar!=NULL)
                {
                    cout<<ar->destino->nombre<<" ";
                    ar=ar->sgte;
                }
                cout<<endl;
                return;
            }
        }
        else
        aux=aux->sgte;
    }
}

void MainWindow::on_actionVentana_1_triggered()
{
    Dialog *ventana1 = new Dialog(this);
    ventana1->setModal(true);
    ventana1->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    // Actualiza el tableWidget
    while(ui->tableWidget->rowCount()!=0){
        ui->tableWidget->removeRow(0);
    }

    Tnodo ptr;
    Tarista ar;
    ptr=p;
    cout<<"NODO|LISTA DE ADYACENCIA\n";

    while(ptr!=NULL){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, NODO,
                                 new QTableWidgetItem(QString::number(ptr->nombre)));

        cout<<"   "<<ptr->nombre<<"|";
        if(ptr->ady!=NULL)
        {
            ar=ptr->ady;
            while(ar!=NULL)
            {
                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, LISTA,
                                         new QTableWidgetItem(
                                             QString::number(ar->destino->nombre)));
                cout<<" "<<ar->destino->nombre;
                ar=ar->sgte;
            }

        }
        ptr=ptr->sgte;
        cout<<endl;
    }
}

// Insertar arista.
void MainWindow::on_pushButton_2_clicked(){
    //char ini, fin;
    Tarista nuevo=new struct arista;
    Tnodo aux, aux2;

    if(p==NULL)
    {
        cout<<"GRAFO VACIO...!!!!";
        return;
    }
    nuevo->sgte=NULL;
    cout<<"INGRESE NODO DE INICIO:";
    //cin>>ini;
    QString a=ui->lineEdit_3->text();
    int ini = a.split(" ")[0].toInt();
    cout<<"INGRESE NODO FINAL:";
    //cin>>fin;
    QString b=ui->lineEdit_4->text();
    int fin = b.split(" ")[0].toInt();
    aux=p;
    aux2=p;
    while(aux2!=NULL)
    {
        if(aux2->nombre==fin)
        {
            break;
        }

        aux2=aux2->sgte;
    }
    while(aux!=NULL)
    {
        if(aux->nombre==ini)
        {
            agrega_arista(aux,aux2, nuevo);
            return;
        }

        aux = aux->sgte;
    }
}
