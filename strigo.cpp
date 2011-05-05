/*
  Ariel Molina Rueda
  Eladio Alvarez Valle
*/
#include "strigo.h"
#include "ui_widget.h"
#include <QtDeclarative>
#include <QWebView>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
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
    ui->m_layout->insertWidget(0, m_qmlTab3, -1, Qt::AlignLeft); // -1 = non stretchable
    ui->m_layout->insertWidget(-1, m_qmlTabFuncs, 0, Qt::AlignRight);
    // Conectar señales QML a slots de C+++
    connect(m_qmlTab3->rootObject(), SIGNAL(teoria()), this, SLOT(slotShowTheory()));
    connect(m_qmlTab3->rootObject(), SIGNAL(ejercicios()), this, SLOT(slotShowExercise()));
    connect(m_qmlTab3->rootObject(), SIGNAL(graficar()), this, SLOT(slotShowPlot()));
    connect(m_qmlTabFuncs->rootObject(), SIGNAL(selectFunction(QString)), ui->plotter, SLOT(recalculate(QString)));

    connect(ui->plotter, SIGNAL(value(double,double)), this, SLOT(slotShowValues(double, double)));

    // Cargar la teoría de un archivo HTML externo (en el mismo directorio que el ejecutable)
    ui->webView->load(QUrl("teoria/funciones.htm"));
    // El webview abarca todo el widget central
    ui->teoria->setLayout(ui->containWeb);
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
    QString coord = "(" + QString::number(x, 'g', 2) + ", " + QString::number(y, 'g', 2)+")";
    ui->values->setText("Valor: " + coord);
}
