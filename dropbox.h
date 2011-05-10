#ifndef DROPBOX_H
#define DROPBOX_H

#include <QLabel>
class QDropEvent;

class DropBox : public QLabel
{
    Q_OBJECT
public:
    explicit DropBox(QWidget *parent = 0);
protected:
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);
signals:
    void validate();
public slots:
    void slotClear(QString str);
};

#endif // DROPBOX_H
