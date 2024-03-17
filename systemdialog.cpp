#include "systemdialog.h"
#include "ui_systemdialog.h"

#include <QScreen>
#include <QGuiApplication>
#include <QDebug>






systemDialog::systemDialog(QWidget *parent) : QDialog(parent), ui(new Ui::systemDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);

}



systemDialog::~systemDialog()
{
    delete ui;
}



void systemDialog::on_okButton_clicked()
{
    this->close();
}


void systemDialog::on_applyButton_clicked()
{

}



void systemDialog::on_discardButton_clicked()
{
    this->close();
}


void systemDialog::on_systemTypeButton_clicked()
{
    if (ui->systemTypeButton->text() == "SITES") {
        ui->systemTypeButton->setText("SYSTEM");
    }
    else {
        ui->systemTypeButton->setText("SITES");
    }
    ui->systemTypeButton->update();
    qDebug() << "New text:" << ui->systemTypeButton->text();



}

