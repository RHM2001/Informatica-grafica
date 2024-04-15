#ifndef MODELO_COLOR_H
#define MODELO_COLOR_H

#include <QDialog>

namespace Ui {
class modelo_color;
}

class modelo_color : public QDialog
{
    Q_OBJECT

public:
    explicit modelo_color(int numfoto, int nueva, QWidget *parent = nullptr);
    ~modelo_color();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_modelo_color_accepted();

    void on_modelo_color_rejected();

private:
    Ui::modelo_color *ui;
    int nfoto;
    int nres;
    int modelo;
};

#endif // MODELO_COLOR_H
