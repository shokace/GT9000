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

private:
    Ui::inputsDialog *ui;
};

#endif // INPUTSDIALOG_H
