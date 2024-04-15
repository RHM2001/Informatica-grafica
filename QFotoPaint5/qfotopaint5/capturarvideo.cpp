#include "capturarvideo.h"
#include "ui_capturarvideo.h"

capturarvideo::capturarvideo(string nombre, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::capturarvideo)
{
    ui->setupUi(this);
    cap.open(nombre);
    if (cap.isOpened()) {
        Mat img;
        cap.read(img);
        imshow("Frame", img);
        int longitud = cap.get(CAP_PROP_FRAME_COUNT);
        ui->horizontalSlider_3->setMaximum((longitud-1));
        ui->spinBox_3->setMaximum(longitud-1);
    }
    if (parent)
        move(parent->x()+DESP_X_HIJO, parent->y()+DESP_Y_HIJO);
}

capturarvideo::~capturarvideo()
{
    delete ui;
}

bool capturarvideo::isOpened()
{
    return cap.isOpened();
}

void capturarvideo::on_horizontalSlider_3_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
    cap.set(CAP_PROP_POS_FRAMES, value);
    Mat frame;
    cap.read(frame);
    if (!frame.empty())
        imshow("Frame", frame);
    else {
        qDebug("No se puede abrir el frame %d", ui->spinBox_3->value());
    }
}

void capturarvideo::on_spinBox_3_valueChanged(int arg1)
{
    ui->horizontalSlider_3->setValue(arg1);
}

void capturarvideo::on_capturarvideo_rejected()
{
    destroyWindow("Frame");
}

void capturarvideo::on_capturarvideo_accepted()
{
    cap.set(CAP_PROP_POS_FRAMES, ui->spinBox_3->value());
    Mat frame;
    cap.read(frame);
    if (!frame.empty())
        crear_nueva(primera_libre(), frame);
    else {
        qDebug("No se puede abrir el frame %d", ui->spinBox_3->value());
    }

    destroyWindow("Frame");
}
