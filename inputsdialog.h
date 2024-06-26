#ifndef INPUTSDIALOG_H
#define INPUTSDIALOG_H

#include <QDialog>

namespace Ui {
class inputsDialog;
}

class inputsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit inputsDialog(QWidget *parent = nullptr);
    ~inputsDialog();

private slots:
    void on_okButton_clicked();

    void on_discardButton_clicked();

private:
    Ui::inputsDialog *ui;
};

#endif // INPUTSDIALOG_H
