/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QTime>
#include <QtCore/QDebug>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axis(new QValueAxis),
    m_step(50),
    m_x(0),
    m_y(0)
{
    m_series = new QSplineSeries(this);
    QPen green(Qt::green);
    green.setWidth(3);
    m_series->setPen(green);
    m_series->append(m_x, m_y);
    addSeries(m_series);

    ageSeries = new QSplineSeries(this);
    QPen red(Qt::red);
    red.setWidth(3);
    ageSeries->setPen(red);
    ageSeries->append(m_x, m_y);
    addSeries(ageSeries);
    //

    createDefaultAxes();
    setAxisX(m_axis, m_series);
    setAxisX(m_axis, ageSeries);

    m_axis->setTickCount(50);
    axisX()->setRange(0, 50);
    axisY()->setRange(0, 7500);
}

void Chart::addData(int age, int speed, int maxHunger, int hunger, int thirst, int alive)
{
    qreal x = plotArea().width() / m_axis->tickCount();
    qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
    m_x += y;
    m_y = rand()%7000;

    m_series->append(m_x, m_y);
    ageSeries->append(m_x, age);
//    speedSeries->append(m_x, speed);
//    maxHungerSeries->append(m_x, maxHunger);
//    hungerSeries->append(m_x, hunger);
//    thirstSeries->append(m_x, thirst);
//    aliveSeries->append(m_x, alive);

    if (m_series->count() > 50)
    scroll(x, 0);
}
