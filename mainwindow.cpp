#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QVBoxLayout>
#include <QIcon>

#include "mainwindow.h"
#include "CustomToolButton.h"
#include "inputsdialog.h"
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


    ui->exitButton = new CustomToolButton;
    ui->exitButton->setText("TEST");
    //ui->exitButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

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

    settingsDialog.adjustSize();
    QRect mainWindowGeometry = this->geometry();
    int dialogX = mainWindowGeometry.x() + 188; // 10 pixels from the left edge of the main window
    int dialogY = mainWindowGeometry.y() + 100; // 10 pixels from the top edge of the main window

    settingsDialog.move(dialogX, dialogY);
    settingsDialog.exec();
}



void MainWindow::on_unitsButton_clicked()
{
    unitDialog unitDialog;
    unitDialog.setModal(true);

    unitDialog.adjustSize();
    QRect mainWindowGeometry = this->geometry();
    int dialogX = mainWindowGeometry.x() + 280; // 10 pixels from the left edge of the main window
    int dialogY = mainWindowGeometry.y() + 100; // 10 pixels from the top edge of the main window

    unitDialog.move(dialogX, dialogY);

    unitDialog.exec();
}


void MainWindow::on_systemButton_clicked()
{
    //QRect topFrame = ui->topFrame->geometry();
    //systemDialog systemDialog(topFrame, this);
    systemDialog systemDialog;
    systemDialog.setModal(true);


    systemDialog.adjustSize();
    QRect mainWindowGeometry = this->geometry();
    int dialogX = mainWindowGeometry.x() + 5; // 10 pixels from the left edge of the main window
    int dialogY = mainWindowGeometry.y() + 100; // 10 pixels from the top edge of the main window

    systemDialog.move(dialogX, dialogY);

    systemDialog.exec();
}


void MainWindow::on_inputsButton_clicked()
{
    inputsDialog inputsDialog;
    inputsDialog.setModal(true);


    inputsDialog.adjustSize();
    QRect mainWindowGeometry = this->geometry();
    int dialogX = mainWindowGeometry.x() + 97; // 10 pixels from the left edge of the main window
    int dialogY = mainWindowGeometry.y() + 100; // 10 pixels from the top edge of the main window

    inputsDialog.move(dialogX, dialogY);
    inputsDialog.exec();
}

