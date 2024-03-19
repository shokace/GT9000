#include "unitdialog.h"
#include "ui_unitdialog.h"

unitDialog::unitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unitDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
}

/*void unitDialog::setYAxisRange(double minY, double maxY) {
    QValueAxis *axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).first());
    if (axisY) {
        axisY->setRange(minY, maxY);
    }
}*/

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

