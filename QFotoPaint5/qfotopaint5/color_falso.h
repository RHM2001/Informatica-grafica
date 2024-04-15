#ifndef COLOR_FALSO_H
#define COLOR_FALSO_H

#include <QDialog>

namespace Ui {
class color_falso;
}

class color_falso : public QDialog
{
    Q_OBJECT

public:
    explicit color_falso(int num_foto, int nueva, QWidget *parent = nullptr);
    ~color_falso();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_color_falso_accepted();

    void on_color_falso_rejected();

private:
    Ui::color_falso *ui;
    int paleta;
    int nfoto;
    int nres;
};

#endif // COLOR_FALSO_H
