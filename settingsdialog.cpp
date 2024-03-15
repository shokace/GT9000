#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_discardButton_clicked()
{
    this->close();
}


void SettingsDialog::on_okButton_clicked()
{
    this->close();

}

