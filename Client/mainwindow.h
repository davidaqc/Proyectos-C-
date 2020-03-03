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
    void crearVentanaDialogo();
    void enviar_msj(string mensaje);

private slots:
    void on_aceptar_clicked();

    void on_aceptar_nodo_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;

    enum Column{
        NODO, LISTA
    };

};
#endif // MAINWINDOW_H
