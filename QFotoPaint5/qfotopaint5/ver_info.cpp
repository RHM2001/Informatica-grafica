#include "ver_info.h"
#include "ui_ver_info.h"

ver_info::ver_info(int num_foto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ver_info)
{
    ui->setupUi(this);
    nfoto = num_foto;
    img = ver_informacion(nfoto);
    setInfo();
}

ver_info::~ver_info()
{
    delete ui;
}

void ver_info::setInfo()
{

    int ancho = img.cols;
    int alto = img.rows;
    int profundidad = img.elemSize() * 8;
    int canales = img.channels();
    int memoria = img.total() * img.elemSize();
    Scalar meanColor = mean(img);
    int meanRed = cvRound(meanColor[2]);
    int meanGreen = cvRound(meanColor[1]);
    int meanBlue = cvRound(meanColor[0]);

    QColor meanColorQt(meanRed, meanGreen, meanBlue);

    ui->label_3->setNum(ancho);
    ui->label_18->setNum(alto);
    ui->label_5->setNum(profundidad);
    ui->label_7->setNum(canales);
    ui->label_9->setNum(memoria);
    ui->label_12->setNum(meanRed);
    ui->label_14->setNum(meanGreen);
    ui->label_16->setNum(meanBlue);
    ui->label_19->setAutoFillBackground(true);
    ui->label_19->setPalette(QPalette(meanColorQt));
}
