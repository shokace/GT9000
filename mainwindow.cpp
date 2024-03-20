#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QVBoxLayout>
#include <QIcon>
#include <QtCharts>
#include <QLineSeries>
#include <QChartView>
#include <QRandomGenerator>
#include <QtCharts/QValueAxis>
#include <QDebug>



#include "mainwindow.h"
#include "inputsdialog.h"
#include "settingsdialog.h"
#include "ui_mainwindow.h"
#include "unitdialog.h"
#include "systemdialog.h"




MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("GT9000");

    /*
     *
     * TIMER UPDATER
     *
     */
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateChartData);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLabels);
    //timer->start(100); // Update every x milliseconds




    series = new QLineSeries();
    chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::NoAnimation);


    // Create the QChartView with the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set the QChartView as the child of the graphFrame
    if (ui->graphFrame->layout() == nullptr) {
        ui->graphFrame->setLayout(new QVBoxLayout());
    }

    ui->graphFrame->layout()->addWidget(chartView);
    chart->legend()->hide();





    /*
     *
     * GRAPH SETTINGS
     *
     */
    QPen axisPen(Qt::black);
    QBrush labelsBrush(Qt::white);

    QValueAxis *axisX = new QValueAxis;

    axisX->setRange(0, 1000); // Initial range
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Sample Number");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    chart->setBackgroundBrush(QBrush(QColor(50,50,50)));
    axisX->setTitleBrush(labelsBrush);
    axisX->setLinePen(axisPen);
    axisX->setLabelsBrush(labelsBrush);


    QValueAxis *axisY = new QValueAxis;

    axisY->setRange(-1, 1);
    axisY->setTitleText("Data");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    axisY->setTitleBrush(labelsBrush);
    axisY->setLinePen(axisPen);
    axisY->setLabelsBrush(labelsBrush);


    QPen pen(QColor(0, 100, 255));

    pen.setWidth(2);
    series->setPen(pen);


    if (axisX) {
        QPen gridPen(Qt::black);
        gridPen.setStyle(Qt::DotLine);
        axisX->setGridLinePen(gridPen);
    }

    if (axisY) {
        QPen gridPen(Qt::black);
        gridPen.setStyle(Qt::DotLine);
        axisY->setGridLinePen(gridPen);
    }


}

void MainWindow::updateLabels(){

    int pointCount = series->count();
    QString pointCountStr = QString::number(pointCount);
    ui->countLabel->setText(pointCountStr);


    //pk2pk needs to do op as chart is being updated...


}

void MainWindow::updateChartData() {
    static int x = 0;
    double y = (QRandomGenerator::global()->generateDouble() * 2.0) - 1.0;

    series->append(x, y);

    // Keep only the latest 1000 points
    if (series->count() > 1000) {
        series->remove(0); // Remove the oldest point
    }

    // Adjust the x-axis range to keep the latest points in view
    QValueAxis *axisX = qobject_cast<QValueAxis *>(chart->axes(Qt::Horizontal).first());
    if(x > 100) {
        axisX->setRange(x - 100, x);
    }
    else {
        axisX->setRange(0, x);
    }

    // Adjust the y-axis range
    QValueAxis *axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).first());
    axisY->setRange(-1, 1);
    x++;
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
    int dialogX = mainWindowGeometry.x() + 188; //pixels from the left edge of the main window
    int dialogY = mainWindowGeometry.y() + 100; //pixels from the top edge of the main window

    settingsDialog.move(dialogX, dialogY);
    settingsDialog.exec();
}



void MainWindow::on_unitsButton_clicked()
{
    unitDialog unitDialog;
    unitDialog.setModal(true);

    unitDialog.adjustSize();
    QRect mainWindowGeometry = this->geometry();
    int dialogX = mainWindowGeometry.x() + 280;
    int dialogY = mainWindowGeometry.y() + 100;

    unitDialog.move(dialogX, dialogY);
    unitDialog.exec();
}


void MainWindow::on_systemButton_clicked()
{
    systemDialog systemDialog;
    systemDialog.setModal(true);


    systemDialog.adjustSize();
    QRect mainWindowGeometry = this->geometry();
    int dialogX = mainWindowGeometry.x() + 5;
    int dialogY = mainWindowGeometry.y() + 100;

    systemDialog.move(dialogX, dialogY);
    systemDialog.exec();
}


void MainWindow::on_inputsButton_clicked()
{
    inputsDialog inputsDialog;
    inputsDialog.setModal(true);


    inputsDialog.adjustSize();
    QRect mainWindowGeometry = this->geometry();
    int dialogX = mainWindowGeometry.x() + 97;
    int dialogY = mainWindowGeometry.y() + 100;

    inputsDialog.move(dialogX, dialogY);
    inputsDialog.exec();
}


void MainWindow::on_runButton_clicked()
{
    if (ui->runButton->text() == "RUN") {
        qDebug() << "RUNNING";
        ui->runButton->setText("STOP");
        ui->runButton->update();
        timer->start(100); // Update every x milliseconds


    }
    else {
        qDebug() << "STOPPED";
        ui->runButton->setText("RUN");
        ui->runButton->update();
        timer->stop();
    }


}

