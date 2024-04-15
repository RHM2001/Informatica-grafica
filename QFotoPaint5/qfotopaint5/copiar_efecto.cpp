#include "copiar_efecto.h"
#include "ui_copiar_efecto.h"
#include <QFileDialog>
#include <QMessageBox>
#include "video.h"

copiar_efecto::copiar_efecto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::copiar_efecto)
{
    ui->setupUi(this);
    modo = 0;
}

copiar_efecto::~copiar_efecto()
{
    delete ui;
}

void copiar_efecto::on_pushButton_clicked()
{
    QString nombre = QFileDialog::getOpenFileName(this, "Archivo de vídeo", ".", QString::fromStdString(FiltroVideo));
    if (!cap.open(nombre.toLatin1().data())) {
        QMessageBox::information(this, "Error al abrir el vídeo", "No se ha podido abrir el archivo de vídeo");
        ui->pushButton->setChecked(false);
    }
    ui->pushButton_2->setChecked(false);

}

void copiar_efecto::on_pushButton_2_clicked()
{
    if (!cap.open(ui->spinBox->value())) {
        QMessageBox::information(this, "Error al abrir el cámara", "No se ha podido abrir la cámara");
         ui->pushButton_2->setChecked(false);
    }
    ui->pushButton->setChecked(false);
}

void copiar_efecto::on_copiar_efecto_accepted()
{
   if (!cap.isOpened())
   {
       QMessageBox::information(this, "Error de fuente de vídeo", "No hay fuente de vídeo seleccionada");
       return;
   }
   QString nombre = QFileDialog::getSaveFileName(this, "Archivo de vídeo", ".", QString::fromStdString(FiltroVideo));
   if (!nombre.isEmpty()) {
       VideoWriter wri;
       double fps = cap.get(CAP_PROP_FPS);
       if (fps <= 0) fps = 25;
       Mat frame;
       if (cap.read(frame)) {
           if (!wri.open(nombre.toLatin1().data(), VideoWriter::fourcc('D', 'I', 'V', 'X'), fps, frame.size())) {
               QMessageBox::information(this, "Error de salida de vídeo", "No se ha podido crear el vídeo" + nombre);
               return;
           }
           int mat = ui->spinBox_2->value();
           double sat = ui->doubleSpinBox->value();
           double lum = ui->doubleSpinBox_2->value();
           int cx = ui->spinBox_3->value();
           int cy = ui->spinBox_4->value();
           double radio = ui->doubleSpinBox_3->value();
           double grado = ui->doubleSpinBox_4->value();
           int direccion = 1;
           while (waitKey(1) == -1 && cap.read(frame)) {
               Mat res;
               if (modo == 0) {
                res = op_mat_sat_lum(frame, sat, lum, mat);
                if (ui->checkBox->isChecked())
                     mat = (mat+4)%256;
               }
               else {
                   res = op_pinchar_estirar(frame, cx, cy, radio, grado*radio*radio/1000.0);
                   if (ui->checkBox_2->isChecked()) {
                       grado += direccion;
                       if (abs(grado) >= 60)
                           direccion = -direccion;
                   }
               }
               imshow("Frame", res);
               wri.write(res);
           }
           wri.release();
           destroyWindow("Frame");
       }

   }
}

void copiar_efecto::on_tabWidget_currentChanged(int index)
{
    modo = index;
}
