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

//author: Adam Siwak

#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChart>
#include <QtCore/QTimer>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

typedef boost::shared_ptr<QSplineSeries> QSplineSeries_sharedPtr;
typedef boost::shared_ptr<QValueAxis> QValueAxis_sharedPtr;

/**
 * @brief The Chart class
 */
class Chart: public QChart
{
    Q_OBJECT
public:
    /**
     * @brief Chart constructor
     * @param parent
     * @param wFlags
     */
    Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    /**
     * @brief ~Chart destructor
     */
    virtual ~Chart() {}
    /**
     * @brief addData to chart
     * @param age
     * @param speed
     * @param maxHunger
     * @param hunger
     * @param thirst
     * @param alive
     */
    void addData(int age, int speed, int maxHunger, int hunger, int thirst, int alive);

private:
    QTimer m_timer;
    QSplineSeries_sharedPtr ageSeries;
    QSplineSeries_sharedPtr speedSeries;
    QSplineSeries_sharedPtr maxHungerSeries;
    QSplineSeries_sharedPtr hungerSeries;
    QSplineSeries_sharedPtr thirstSeries;
    QSplineSeries_sharedPtr aliveSeries;

    QStringList m_titles;
    QValueAxis_sharedPtr m_axis;
    QValueAxis_sharedPtr axisY1;
    QValueAxis_sharedPtr axisY2;
    qreal m_step;
    qreal m_x;
    qreal m_y;
    int y_min, y_max;
};

#endif /* CHART_H */
