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
    void recalculate(QString f);
private:
    QString         m_functionName;
    QPolygonF       m_points;
    Function*       m_function;
    double          m_handlePos;
    QPen            m_dotPen;
};

#endif // PLOTWIDGET_H
