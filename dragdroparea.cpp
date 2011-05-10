#include "dragdroparea.h"
#include <QDragEnterEvent>
#include <QLabel>
#include <QDebug>
DragDropArea::DragDropArea(QWidget *parent) :
    QWidget(parent)
{
}
void DragDropArea::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if (!child)
        return;

    // Only drag children with dynamic property: "drag"
    if (!child->property("drag").toBool())
        return;

    QPoint hotSpot = event->pos() - child->pos();

    QMimeData *mimeData = new QMimeData;
    mimeData->setText(child->text());
    mimeData->setData("application/x-hotspot",
                      QByteArray::number(hotSpot.x())
                      + " " + QByteArray::number(hotSpot.y()));

    QPixmap pixmap(child->size());
    child->render(&pixmap);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(hotSpot);
    drag->exec();
}
