#ifndef VER_INFO_H
#define VER_INFO_H

#include <QDialog>
#include <opencv2/opencv.hpp>
using namespace cv;
#include "imagenes.h"

namespace Ui {
class ver_info;
}

class ver_info : public QDialog
{
    Q_OBJECT

public:
    explicit ver_info(int num_foto, QWidget *parent = nullptr);
    ~ver_info();
    void setInfo();

private:
    Ui::ver_info *ui;
    int nfoto;
    Mat img;
};

#endif // VER_INFO_H
