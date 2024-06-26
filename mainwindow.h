#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QChartView>
#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void updateChartData();

    void on_exitButton_clicked();

    void on_settingsButton_clicked();

    void on_unitsButton_clicked();

    void on_systemButton_clicked();

    void on_inputsButton_clicked();

    void on_runButton_clicked();

    void updateLabels();

    void updatePk2pk();

    void updateMean();

    void updateStandardDeviation();

private:
    Ui::MainWindow *ui;
    QLineSeries *series;
    QChart *chart;
    QTimer *timer;
    QChartView chartView;
    double minValue = std::numeric_limits<double>::max();
    double maxValue = std::numeric_limits<double>::lowest();
    double mean = 0.0;
};
#endif // MAINWINDOW_H
