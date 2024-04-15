#include "modelo_color.h"
#include "ui_modelo_color.h"
#include "imagenes.h"

modelo_color::modelo_color(int numfoto, int nueva, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modelo_color)
{
    ui->setupUi(this);
    nfoto = numfoto;
    set_callback_foto(nfoto, false);
    nres = nueva;
    modelo = 0;
    modelo_de_color(nfoto, nres, modelo);
}

modelo_color::~modelo_color()
{
    set_callback_foto(nfoto, true);
    delete ui;
}

void modelo_color::on_radioButton_clicked()
{
    modelo = 0;
    modelo_de_color(nfoto, nres, modelo);
}

void modelo_color::on_radioButton_2_clicked()
{
    modelo = 1;
    modelo_de_color(nfoto, nres, modelo);
}

void modelo_color::on_radioButton_3_clicked()
{
    modelo = 2;
    modelo_de_color(nfoto, nres, modelo);
}

void modelo_color::on_radioButton_4_clicked()
{
    modelo = 3;
    modelo_de_color(nfoto, nres, modelo);
}

void modelo_color::on_radioButton_5_clicked()
{
    modelo = 4;
    modelo_de_color(nfoto, nres, modelo);
}

void modelo_color::on_modelo_color_accepted()
{
     modelo_de_color(nfoto, nres, modelo, true);
     destroyWindow("Nuevo modelo de color");
}

void modelo_color::on_modelo_color_rejected()
{
    destroyWindow("Nuevo modelo de color");
}
