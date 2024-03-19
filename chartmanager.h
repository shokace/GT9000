#ifndef CHARTMANAGER_H
#define CHARTMANAGER_H

#include <QObject>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QChartView>


class ChartManager : public QObject {
    Q_OBJECT

public:
    explicit ChartManager(QObject *parent = nullptr);
    QChartView* createChart();

public slots:
    void updateChartData();

private:
    QLineSeries *series;
    QChart *chart;
};

#endif // CHARTMANAGER_H
