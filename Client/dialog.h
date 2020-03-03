#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

/**
 * @brief Ventana de dialogo, envia mensajes de advertencia
 *
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui; /**< TODO: describe */
};

#endif // DIALOG_H
