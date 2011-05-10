#include "dropbox.h"
#include <QDropEvent>
#include <QDebug>
DropBox::DropBox(QWidget *parent) :
    QLabel(parent)
{
    setAcceptDrops(true);
}
void DropBox::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/plain"))
        event->acceptProposedAction();
}
void DropBox::dropEvent(QDropEvent *event)
{
    QString txt = event->mimeData()->text();
    setText(txt);
    emit validate();
    return;
}

void DropBox::slotClear(QString str){
    setText("");
}
