#include "rotar_imagen.h"
#include "ui_rotar_imagen.h"

#include "imagenes.h"

Rotar_imagen::Rotar_imagen(int numfoto, int numres, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rotar_imagen)
{
    ui->setupUi(this);
    nfoto = numfoto;
    nres = numres;
    escala = 1;
    grado = 0;
    ver_rotar_escalar_imagen(nfoto, nres, grado, escala);
}

Rotar_imagen::~Rotar_imagen()
{
    delete ui;
}

void Rotar_imagen::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    grado = value;
    ver_rotar_escalar_imagen(nfoto, nres, grado, escala);
}

void Rotar_imagen::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
    grado = arg1;
    ver_rotar_escalar_imagen(nfoto, nres, grado, escala);
}

void Rotar_imagen::on_spinBox_2_valueChanged(int arg1)
{
    escala = arg1;
    ver_rotar_escalar_imagen(nfoto, nres, grado, escala);
}

void Rotar_imagen::on_Rotar_imagen_accepted()
{
    ver_rotar_escalar_imagen(nfoto, nres, grado, escala, true);
    destroyWindow("RotarEscalar");
}

void Rotar_imagen::on_Rotar_imagen_rejected()
{
    mostrar(nfoto);
    destroyWindow("RotarEscalar");
}
