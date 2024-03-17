#include "inputsdialog.h"
#include "ui_inputsdialog.h"

inputsDialog::inputsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::inputsDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
}

inputsDialog::~inputsDialog()
{
    delete ui;
}

void inputsDialog::on_okButton_clicked()
{
    this->close();
}


void inputsDialog::on_discardButton_clicked()
{
    this->close();
}

