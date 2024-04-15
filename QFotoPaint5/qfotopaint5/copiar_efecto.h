#ifndef COPIAR_EFECTO_H
#define COPIAR_EFECTO_H

#include <QDialog>
#include "imagenes.h"

namespace Ui {
class copiar_efecto;
}

class copiar_efecto : public QDialog
{
    Q_OBJECT

public:
    explicit copiar_efecto(QWidget *parent = nullptr);
    ~copiar_efecto();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_copiar_efecto_accepted();

    void on_tabWidget_currentChanged(int index);

private:
    VideoCapture cap;
    int modo;
    Ui::copiar_efecto *ui;
};

#endif // COPIAR_EFECTO_H
