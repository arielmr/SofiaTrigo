#ifndef STRIGO_H
#define STRIGO_H

#include <QWidget>
class QDeclarativeView;
namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void slotShowTheory();
    void slotShowExercise();
    void slotShowPlot();
    void slotShowValues(double x, double y);
    void slotSwitchFunction(QString func);
    void slotValidateFunctionFrac();
protected:
    QDeclarativeView*   m_qmlTab3;
    QDeclarativeView*   m_qmlTabFuncs;
private:
    Ui::Widget *ui;
    QString             m_currentFunction;
};

#endif // STRIGO_H
