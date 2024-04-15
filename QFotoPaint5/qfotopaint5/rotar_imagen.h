#ifndef ROTAR_IMAGEN_H
#define ROTAR_IMAGEN_H

#include <QDialog>

namespace Ui {
class Rotar_imagen;
}

class Rotar_imagen : public QDialog
{
    Q_OBJECT

public:
    explicit Rotar_imagen(int numfoto, int numres, QWidget *parent = nullptr);
    ~Rotar_imagen();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_Rotar_imagen_accepted();

    void on_Rotar_imagen_rejected();

private:
    Ui::Rotar_imagen *ui;
    int grado;
    int escala;
    int nfoto, nres;
};

#endif // ROTAR_IMAGEN_H
