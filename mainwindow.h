#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>


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

private:
    Ui::MainWindow *ui;
    QLineSeries *series;
    QChart *chart;
};
#endif // MAINWINDOW_H
