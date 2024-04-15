#include "color_falso.h"
#include "ui_color_falso.h"
#include "imagenes.h"

color_falso::color_falso(int numfoto, int nueva, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::color_falso)
{
    ui->setupUi(this);
    nfoto = numfoto;
    set_callback_foto(nfoto, false);
    nres = nueva;
    paleta = 3;
    convertir_a_color_falso(nfoto, nres, paleta);
}

color_falso::~color_falso()
{
    delete ui;
    set_callback_foto(nfoto, true);
}

void color_falso::on_radioButton_clicked()
{
    paleta = 0;
    convertir_a_color_falso(nfoto, nres, paleta);
}

void color_falso::on_radioButton_2_clicked()
{
    paleta = 1;
    convertir_a_color_falso(nfoto, nres, paleta);
}

void color_falso::on_radioButton_3_clicked()
{
    paleta = 2;
    convertir_a_color_falso(nfoto, nres, paleta);
}

void color_falso::on_radioButton_4_clicked()
{
    paleta = 3;
    convertir_a_color_falso(nfoto, nres, paleta);
}

void color_falso::on_color_falso_accepted()
{
    convertir_a_color_falso(nfoto, nres, paleta, true);
    destroyWindow("Imagen Color Falso");
}

void color_falso::on_color_falso_rejected()
{
    destroyWindow("Imagen Color Falso");
}
