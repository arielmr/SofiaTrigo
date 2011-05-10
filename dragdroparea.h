#ifndef DROPAREA_H
#define DROPAREA_H

#include <QWidget>

class QDragEnterEvent;
class QDragMoveEvent;

class DragDropArea : public QWidget
{
    Q_OBJECT
public:
    explicit DragDropArea(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
signals:

public slots:

};

#endif // DROPAREA_H
