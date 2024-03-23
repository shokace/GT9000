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
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePk2pk);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateMean);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateStandardDeviation);

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

void MainWindow::updateMean() {
    int count = series->count();
    double sum = 0.0;
    double c = 0.0; // A running compensation for lost low-order bits.

    for (const QPointF &point : series->points()) {
        double y = point.y() - c;    // So far, so good: c is zero.
        double t = sum + y;          // Alas, sum is big, y small, so low-order digits of y are lost.
        c = (t - sum) - y;           // (t - sum) recovers the high-order part of y; subtracting y recovers -(low part of y)
        sum = t;                     // Algebraically, c should always be zero. Beware overly aggressive optimizing compilers!
    }

    double mean = 0.0;
    if (count > 0) {
        mean = sum / count; // Calculate the mean
    }

    ui->meanLabel->setText(QString::number(mean, 'g', 6)); // Set the mean to the label, 'g' format with 15 significant digits
}

void MainWindow::updateStandardDeviation() {

    double sumOfSquares = 0.0;
    double c = 0.0; // Compensation for lost low-order bits
    int count = series->count();

    for (const QPointF &point : series->points()) {
        double y = (point.y() - mean) * (point.y() - mean) - c;
        double t = sumOfSquares + y;
        c = (t - sumOfSquares) - y;
        sumOfSquares = t;
    }

    double variance = count > 1 ? sumOfSquares / (count - 1) : 0;
    double stdDeviation = sqrt(variance);

    ui->standardDeviationLabel->setText(QString::number(stdDeviation, 'f', 6)); // 'f' for fixed-point notation, 6 digits precision
}



void MainWindow::updatePk2pk(){

    if (series->count()){
        for (const QPointF &point : series->points()) {
            minValue = std::min(minValue, point.y());
            maxValue = std::max(maxValue, point.y());
        }

        double peakToPeak = maxValue - minValue;
        ui->pk2pkLabel->setText(QString::number(peakToPeak) + "V");
        ui->minLabel->setText(QString::number(minValue));
        ui->maxLabel->setText(QString::number(maxValue));
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

    // Adjust the x-axis range to keep the latest points in view
    QValueAxis *axisX = qobject_cast<QValueAxis *>(chart->axes(Qt::Horizontal).first());

    axisX->setRange(0, x);


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
        timer->start(10); // Update every x milliseconds


    }
    else {
        qDebug() << "STOPPED";
        ui->runButton->setText("RUN");
        ui->runButton->update();
        timer->stop();
    }


}

