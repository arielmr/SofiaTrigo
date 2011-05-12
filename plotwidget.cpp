#include "plotwidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <math.h>
#include <QDebug>
#include <QTimer>
#include "function.h"
PlotWidget::PlotWidget(QWidget *parent) :
    QWidget(parent)
  , m_functionName("sin")
  , m_function(new Function())
  , m_handlePos (QPointF(0.0, 0.0))
  , m_timer(new QTimer(this))
  , m_plotGranularity(0.1)
  , m_graphPortion(0.0)
{
    setMouseTracking(true); // receive mouse moves at all times
    m_dotPen.setStyle(Qt::DotLine); // dotted line
    m_points << QPointF(0,0);
}
void PlotWidget::paintEvent(QPaintEvent* ){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // nice rendering
    painter.setWindow(-5,-2,10,4); // define coordinate system (view)
    painter.scale(1.0, -1.0); // pixel coordinate system is y-inverted, fix it
    // Draw axis
    drawAxis(&painter);
    // PLOT THE GRAPH
    painter.setPen(Qt::darkBlue);
    painter.drawPolyline(m_points);

    // Draw the mouse-tracking circle
    if (!m_functionName.isEmpty()){
        painter.drawEllipse(m_handlePos, 0.05,0.05);
        painter.setPen(m_dotPen);
        painter.drawLine(m_handlePos, QPointF(m_handlePos.x(), 0.0));
    }
}
void PlotWidget::mouseMoveEvent(QMouseEvent *event){
    // Mouse is not mapped to painter, map it by hand
    m_handlePos.setX( -5 + event->posF().x()*10.0/this->width());
    m_handlePos.setY( m_function->calculate(m_functionName, m_handlePos.x(), m_A, m_B, m_C));
    emit value(m_handlePos.x(), m_function->calculate(m_functionName, m_handlePos.y(), m_A, m_B, m_C));
    update(); // request repaint
}
void PlotWidget::recalculate(QString f, float A, float B, float C){
    m_points.clear();
    if (!m_function){
        return;
    }
    m_functionName = f;
    //double norm;
    QPointF diff;
    QPointF point;
    for (float t=-5; t<5; t=t+0.01){
        point = QPointF(t, m_function->calculate(f, t, A, B, C));
        diff = m_points.last() - point;
        m_points << point;
    }
    m_A = A;
    m_B = B;
    m_C = C;
    m_handlePos.setX(0.0);
    m_handlePos.setY(0.0);
    update(); // request repaint
}

void PlotWidget::drawAxis(QPainter *p){
    p->setPen(Qt::gray);
    p->drawLine(-5,0,5,0);
    p->drawLine(0,5,0,-5);

    float dx = 0.05;
    // Draw small steps
    for (float t=-5.0; t<5.0; t=t+0.5 ){
        p->drawLine(QPointF(t, -dx), QPointF(t, dx));
    }
    for (float t=-5.0; t<5.0; t=t+0.5 ){
        p->drawLine(QPointF(-dx, t), QPointF(dx, t));
    }
    // Draw units
    p->setPen(Qt::red);
    for (float t=-5.0; t<5.0; t=t+1 ){
        p->drawLine(QPointF(t, -dx*2), QPointF(t, dx*2));
    }
    for (float t=-5.0; t<5.0; t=t+1 ){
        p->drawLine(QPointF(-dx*2, t), QPointF(dx*2, t));
    }
}
void PlotWidget::slotTick(){
}
