#include "morfo_mat.h"
#include "ui_morfo_mat.h"
#include "imagenes.h"

morfo_mat::morfo_mat(int numfoto, int nueva, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::morfo_mat)
{
    ui->setupUi(this);
    nfoto = numfoto;
    set_callback_foto(nfoto, false);
    nres = nueva;
    nit = 0;
    modo = 0;
    morfologia_matematica(nfoto, nres, nit, modo);
}

morfo_mat::~morfo_mat()
{
    set_callback_foto(nfoto, true);
    delete ui;
}

void morfo_mat::on_radioButton_clicked()
{
    modo = 0;
    morfologia_matematica(nfoto, nres, nit, modo);
}

void morfo_mat::on_radioButton_2_clicked()
{
    modo = 1;
    morfologia_matematica(nfoto, nres, nit, modo);
}

void morfo_mat::on_radioButton_3_clicked()
{
    modo = 2;
    morfologia_matematica(nfoto, nres, nit, modo);
}

void morfo_mat::on_radioButton_4_clicked()
{
    modo = 3;
    morfologia_matematica(nfoto, nres, nit, modo);
}

void morfo_mat::on_horizontalSlider_valueChanged(int value)
{
    nit = value;
    ui->spinBox->setValue(value);
    morfologia_matematica(nfoto, nres, nit, modo);
}

void morfo_mat::on_spinBox_valueChanged(int arg1)
{
    nit = arg1;
    ui->horizontalSlider->setValue(arg1);
    morfologia_matematica(nfoto, nres, nit, modo);
}

void morfo_mat::on_morfo_mat_accepted()
{
    morfologia_matematica(nfoto, nres, nit, modo, true);
    destroyWindow("Morfología matemática");
}

void morfo_mat::on_morfo_mat_rejected()
{
    destroyWindow("Morfología matemática");
}
