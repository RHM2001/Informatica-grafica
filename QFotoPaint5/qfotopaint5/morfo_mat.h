#ifndef MORFO_MAT_H
#define MORFO_MAT_H

#include <QDialog>

namespace Ui {
class morfo_mat;
}

class morfo_mat : public QDialog
{
    Q_OBJECT

public:
    explicit morfo_mat(int numfoto, int nueva, QWidget *parent = nullptr);
    ~morfo_mat();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_morfo_mat_accepted();

    void on_morfo_mat_rejected();

private:
    Ui::morfo_mat *ui;
    int nfoto;
    int nres;
    int nit;
    int modo;
};

#endif // MORFO_MAT_H
