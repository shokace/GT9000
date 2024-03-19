#include "chartmanager.h"
#include <QtCharts/QValueAxis>
#include <QRandomGenerator>

ChartManager::ChartManager(QObject *parent) : QObject(parent), series(new QLineSeries()), chart(new QChart()) {
    // Initialize the series and chart in the constructor
    chart->addSeries(series);
    chart->setTitle("Real-time Data");
    chart->createDefaultAxes();
    chart->setAnimationOptions(QChart::AllAnimations);

    // Customize axes
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, 1000);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Sample Number");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-1, 1);
    axisY->setTitleText("Data");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}

QChartView* ChartManager::createChart() {
    // Return a new QChartView with the configured chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}

void ChartManager::updateChartData() {
    static int x = 0;
    double y = (QRandomGenerator::global()->generateDouble() * 2.0) - 1.0; // Generate random y

    // Keep only the latest 1000 points
    if (series->count() > 1000) {
        series->remove(0);
    }

    series->append(x++, y);

    // Adjust the x-axis
    QValueAxis *axisX = qobject_cast<QValueAxis *>(chart->axes(Qt::Horizontal).first());
    if (x > 1000) {
        axisX->setMin(x - 1000);
    }
    axisX->setMax(x);
}
