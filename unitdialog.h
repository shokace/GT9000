#ifndef UNITDIALOG_H
#define UNITDIALOG_H

#include <QDialog>

namespace Ui {
class unitDialog;
}

class unitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit unitDialog(QWidget *parent = nullptr);
    ~unitDialog();

private slots:
    void on_secondsButton_clicked();

    void on_closeButton_clicked();

    void on_nanosecondsButton_clicked();

    void on_millisecondsButton_clicked();

    void on_microsecondsButton_clicked();

    void on_picosecondsButton_clicked();

private:
    Ui::unitDialog *ui;
};

#endif // UNITDIALOG_H
