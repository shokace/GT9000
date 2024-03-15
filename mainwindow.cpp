#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QVBoxLayout>

#include "mainwindow.h"
#include "settingsdialog.h"
#include "ui_mainwindow.h"
#include "unitdialog.h"
#include "systemdialog.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setWindowTitle("GT9000");
    ui->exitButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exitButton_clicked()
{
    QCoreApplication::quit();
}




void MainWindow::on_settingsButton_clicked()
{
    SettingsDialog settingsDialog;
    settingsDialog.setModal(true);
    settingsDialog.exec();
}



void MainWindow::on_unitsButton_clicked()
{
    unitDialog unitDialog;
    unitDialog.setModal(true);
    unitDialog.exec();
}


void MainWindow::on_systemButton_clicked()
{
    QRect topFrame = ui->topFrame->geometry();
    systemDialog systemDialog(topFrame, this);
    systemDialog.setModal(true);
    systemDialog.exec();
}

