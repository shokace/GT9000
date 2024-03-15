#ifndef SYSTEMDIALOG_H
#define SYSTEMDIALOG_H

#include <QDialog>

namespace Ui {
class systemDialog;
}

class systemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit systemDialog(const QRect &frameGeometry, QWidget *parent = nullptr);
    ~systemDialog();

private slots:
    void on_okButton_clicked();

    void on_applyButton_clicked();

    void on_discardButton_clicked();

    void on_systemTypeButton_clicked();

private:
    Ui::systemDialog *ui;
};

#endif // SYSTEMDIALOG_H
