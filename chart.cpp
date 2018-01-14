#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QTime>
#include <QtCore/QDebug>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    ageSeries(0),
    speedSeries(0),
    maxHungerSeries(0),
    hungerSeries(0),
    thirstSeries(0),
    aliveSeries(0),
    m_axis(new QValueAxis),
    m_step(50),
    m_x(0),
    m_y(0),
    y_min(0),
    y_max(20)
{

    legend()->setVisible(true);
    legend()->setAlignment(Qt::AlignBottom);

    ageSeries = QSplineSeries_sharedPtr(new QSplineSeries(this));
    ageSeries->setName("age");
    QPen black(Qt::black);
    black.setWidth(3);
    ageSeries->setPen(black);
    ageSeries->append(m_x, m_y);
    addSeries(&(*ageSeries));

    speedSeries = QSplineSeries_sharedPtr(new QSplineSeries(this));
    speedSeries->setName("speed");
    QPen blue(Qt::blue);
    blue.setWidth(3);
    speedSeries->setPen(blue);
    speedSeries->append(m_x, m_y);
    addSeries(&(*speedSeries));

    maxHungerSeries = QSplineSeries_sharedPtr(new QSplineSeries(this));
    maxHungerSeries->setName("max hunger");
    QPen green(Qt::green);
    green.setWidth(3);
    maxHungerSeries->setPen(green);
    maxHungerSeries->append(m_x, m_y);
    addSeries(&(*maxHungerSeries));

    hungerSeries = QSplineSeries_sharedPtr(new QSplineSeries(this));
    hungerSeries->setName("hunger");
    QPen magenta(Qt::magenta);
    magenta.setWidth(3);
    hungerSeries->setPen(magenta);
    hungerSeries->append(m_x, m_y);
    addSeries(&(*hungerSeries));

    thirstSeries = QSplineSeries_sharedPtr(new QSplineSeries(this));
    thirstSeries->setName("thirst");
    QPen yellow(Qt::yellow);
    yellow.setWidth(3);
    thirstSeries->setPen(yellow);
    thirstSeries->append(m_x, m_y);
    addSeries(&(*thirstSeries));

    aliveSeries = QSplineSeries_sharedPtr(new QSplineSeries(this));
    aliveSeries->setName("alive");
    QPen red(Qt::red);
    red.setWidth(3);
    aliveSeries->setPen(red);
    aliveSeries->append(m_x, m_y);
    addSeries(&(*aliveSeries));

    createDefaultAxes();
    setAxisX(&(*m_axis), &(*ageSeries));
    setAxisX(&(*m_axis), &(*speedSeries));
    setAxisX(&(*m_axis), &(*maxHungerSeries));
    setAxisX(&(*m_axis), &(*hungerSeries));
    setAxisX(&(*m_axis), &(*thirstSeries));
    setAxisX(&(*m_axis), &(*aliveSeries));

    axisY1 = QValueAxis_sharedPtr(new QValueAxis());
    axisY1->setLinePenColor(Qt::black);

    addAxis(&(*axisY1), Qt::AlignLeft);
    axisY1->setRange(0,30000);

    setAxisY(&(*axisY1), &(*ageSeries));
    setAxisY(&(*axisY1), &(*speedSeries));
    setAxisY(&(*axisY1), &(*maxHungerSeries));
    setAxisY(&(*axisY1), &(*hungerSeries));
    setAxisY(&(*axisY1), &(*thirstSeries));

    axisY2 = QValueAxis_sharedPtr(new QValueAxis());
    axisY2->setLinePenColor(aliveSeries->pen().color());

    addAxis(&(*axisY2), Qt::AlignRight);
    axisY2->setRange(y_min,y_max);

    setAxisY(&(*axisY2), &(*aliveSeries));

    m_axis->setTickCount(50);
    axisX()->setRange(0, 50);
}

void Chart::addData(int age, int speed, int maxHunger, int hunger, int thirst, int alive)
{
    qreal x = plotArea().width() / m_axis->tickCount();
//    qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
    m_x += 1;

    ageSeries->append(m_x, age);
    speedSeries->append(m_x, speed);
    maxHungerSeries->append(m_x, maxHunger);
    hungerSeries->append(m_x, hunger);
    thirstSeries->append(m_x, thirst);
    aliveSeries->append(m_x, alive);

    if (alive > y_max) {
        y_max = alive + 0.05*alive;
        axisY2->setRange(y_min,y_max);
    }

    if (ageSeries->count() > 50)
    scroll(x, 0);
}
