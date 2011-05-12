#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>
#include <QPen>
class Function;
class PlotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlotWidget(QWidget *parent = 0);    
protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *);
    void drawAxis(QPainter* p);
signals:
    void value(double x, double y);
public slots:
    void recalculate(QString f, float A=1.0, float B=1.0, float C=0.0);
private slots:
    void slotTick();
private:
    QString         m_functionName;
    QPolygonF       m_points;
    Function*       m_function;
    QPointF         m_handlePos;
    QPen            m_dotPen;
    QTimer*         m_timer;
    double          m_plotGranularity;
    float           m_graphPortion;

    double          m_A;
    double          m_B;
    double          m_C;
};

#endif // PLOTWIDGET_H
