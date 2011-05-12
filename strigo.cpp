/*
  Ariel Molina Rueda
  Eladio Alvarez Valle
*/
#include "strigo.h"
#include "ui_widget.h"
#include <QtDeclarative>
#include <QWebView>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
  , ui(new Ui::Widget)
  , m_currentFunction("sin")
{
    ui->setupUi(this);
    // El widget principal abarca todo
    this->setLayout(ui->m_layout);

    // El fondo del widget central es blanco
    // Se usa un stacked widget con 3 widgets,
    // los 3 tabs principales controlan lo que se ve
    ui->stackedWidget->setStyleSheet("background-color: white;");
    // El resto de la ventana es negro para que combine con los tabs
    this->setStyleSheet("background-color: black;");
    ui->stackedWidget->setMaximumWidth(620);

    // Crear elementos QML (tabs)
    m_qmlTab3     = new QDeclarativeView;
    m_qmlTabFuncs = new QDeclarativeView;
    m_qmlTab3->setSource(QUrl("qrc:/qml/tab3.qml"));
    m_qmlTabFuncs->setSource(QUrl("qrc:/qml/tabFunc.qml"));
    // Insertar elementos QML al inicio y final del layout
    ui->m_layout->addWidget(m_qmlTab3, 0,0,1,1, Qt::AlignLeft); // -1 = non stretchable
    ui->m_layout->addWidget(m_qmlTabFuncs, 0,2,1,1, Qt::AlignRight);
    // Conectar seales QML a slots de C+++
    connect(m_qmlTab3->rootObject(), SIGNAL(teoria()), this, SLOT(slotShowTheory()));
    connect(m_qmlTab3->rootObject(), SIGNAL(ejercicios()), this, SLOT(slotShowExercise()));
    connect(m_qmlTab3->rootObject(), SIGNAL(graficar()), this, SLOT(slotShowPlot()));
    connect(m_qmlTabFuncs->rootObject(), SIGNAL(selectFunction(QString)), ui->plotter, SLOT(recalculate(QString)));
    connect(m_qmlTabFuncs->rootObject(), SIGNAL(selectFunction(QString)), this, SLOT(slotSwitchFunction(QString)));
    connect(m_qmlTabFuncs->rootObject(), SIGNAL(selectFunction(QString)), ui->m_up, SLOT(slotClear(QString)));
    connect(m_qmlTabFuncs->rootObject(), SIGNAL(selectFunction(QString)), ui->m_down, SLOT(slotClear(QString)));
    connect(ui->plotter, SIGNAL(value(double,double)), this, SLOT(slotShowValues(double, double)));
    connect(ui->m_up, SIGNAL(validate()), this, SLOT(slotValidateFunctionFrac()));
    connect(ui->m_down, SIGNAL(validate()), this, SLOT(slotValidateFunctionFrac()));


    // Cargar la teora de un archivo HTML externo (en el mismo directorio que el ejecutable)
    ui->webView->load(QUrl("teoria/funciones.htm"));
    // El webview abarca todo el widget central

    ui->teoria->setLayout(ui->m_containWeb);
    ui->plotter->recalculate("sin");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotShowTheory(){
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::slotShowExercise(){
    ui->stackedWidget->setCurrentIndex(1);
}
void Widget::slotShowPlot(){
    ui->stackedWidget->setCurrentIndex(2);
}
void Widget::slotShowValues(double x, double y){
    QString coord = " X = " + QString::number(x, 'g', 2) + ",   Y = " + QString::number(y, 'g', 2)+")";
    ui->values->setText("Valor: " + coord);
}
void Widget::slotSwitchFunction(QString func){
    QString file =":/triang/images/"+func+".png";
    QPixmap p(file);
    ui->m_functionImg->setPixmap(p);
    m_currentFunction = func;
    ui->m_evaluation->setPixmap(QPixmap::QPixmap());
}
void Widget::slotValidateFunctionFrac(){
    if (m_currentFunction == "sin"
            && ui->m_up->text().endsWith("esto")
            && ui->m_down->text().endsWith("nusa")
            )
        ui->m_evaluation->setPixmap(QPixmap(":/triang/images/ok.svg"));
    else if (m_currentFunction == "cos"
            && ui->m_up->text().endsWith("ente")
            && ui->m_down->text().endsWith("nusa")
            )
        ui->m_evaluation->setPixmap(QPixmap(":/triang/images/ok.svg"));
    else if (m_currentFunction == "tan"
            && ui->m_up->text().endsWith("puesto")
            && ui->m_down->text().endsWith("dyacente")
            )
        ui->m_evaluation->setPixmap(QPixmap(":/triang/images/ok.svg"));
    else if (m_currentFunction == "cot"
            && ui->m_up->text().endsWith("dyacente")
            && ui->m_down->text().endsWith("puesto")
            )
        ui->m_evaluation->setPixmap(QPixmap(":/triang/images/ok.svg"));
    else if (m_currentFunction == "sec"
            && ui->m_up->text().endsWith("nusa")
            && ui->m_down->text().endsWith("ente")
            )
        ui->m_evaluation->setPixmap(QPixmap(":/triang/images/ok.svg"));
    else if (m_currentFunction == "csc"
            && ui->m_up->text().endsWith("nusa")
            && ui->m_down->text().endsWith("esto")
            )
        ui->m_evaluation->setPixmap(QPixmap(":/triang/images/ok.svg"));
    else
        ui->m_evaluation->setPixmap(QPixmap(":/triang/images/x.svg"));
}

void Widget::on_Asl_valueChanged(int value)
{
    ui->Asp->setValue(double(value)/100.0);
    ui->plotter->recalculate(m_currentFunction, ui->Asp->value(), ui->Bsp->value(), ui->Csp->value());
}

void Widget::on_Bsl_valueChanged(int value)
{
    ui->Bsp->setValue(double(value)/100.0);
    ui->plotter->recalculate(m_currentFunction, ui->Asp->value(), ui->Bsp->value(), ui->Csp->value());

}

void Widget::on_Csl_valueChanged(int value)
{
    ui->Csp->setValue(double(value)/100.0);
    ui->plotter->recalculate(m_currentFunction, ui->Asp->value(), ui->Bsp->value(), ui->Csp->value());
}
