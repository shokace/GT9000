#include "systemdialog.h"
#include "ui_systemdialog.h"

#include <QScreen>
#include <QGuiApplication>
#include <QDebug>




/*systemDialog::systemDialog(const QRect &frameGeometry, QWidget *parent) : QDialog(parent), ui(new Ui::systemDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);

    if (parent != nullptr) {
        // Get the geometry of the parent (main window)
        int dialogY = parent->geometry().y() + frameGeometry.height(); // Adjust based on frame's height
        this->move(parent->geometry().x(), dialogY);
        // Calculate the top-left position for the dialog
        int dialogX = frameGeometry.x();


        // Move the dialog to the calculated position
        this->move(dialogX, dialogY);
    }

}*/
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

