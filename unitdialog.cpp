#include "unitdialog.h"
#include "ui_unitdialog.h"

unitDialog::unitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unitDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
}

unitDialog::~unitDialog()
{
    delete ui;
}

void unitDialog::on_secondsButton_clicked()
{
    this->close();
}

void unitDialog::on_closeButton_clicked()
{
    this->close();
}

void unitDialog::on_millisecondsButton_clicked()
{
    this->close();
}

void unitDialog::on_nanosecondsButton_clicked()
{
    this->close();

}

void unitDialog::on_microsecondsButton_clicked()
{
    this->close();
}

void unitDialog::on_picosecondsButton_clicked()
{
    this->close();

}

