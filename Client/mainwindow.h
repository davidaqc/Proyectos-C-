#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /**
     * @brief Crea una ventana de Dialogo para mostrar advertencias
     *
     */
    void crearVentanaDialogo();
    /**
     * @brief Envia mensaje al Server
     *
     * @param mensaje Datos digitados por el cliente
     */
    void enviar_msj(string mensaje);

private slots:
    /**
     * @brief Eliger dentro un menu
     *
     */
    void on_aceptar_clicked();

    /**
     * @brief Ingresar nodo
     *
     */
    void on_aceptar_nodo_clicked();

    /**
     * @brief Mostrar grafo
     *
     */
    void on_pushButton_4_clicked();

    /**
     * @brief Ingresar arista
     *
     */
    void on_pushButton_2_clicked();

    /**
     * @brief Conectar el Server
     *
     */
    void on_pushButton_5_clicked();

    /**
     * @brief Generar algoritmo
     *
     */
    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui; /**< TODO: describe */

    /**
     * @brief Enum para las columnas de la tabla
     *
     */
    enum Column{
        NODO, LISTA
    };

};
#endif // MAINWINDOW_H
