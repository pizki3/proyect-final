#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    vel = 4;
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,663);//area de mapa
    ui->marcoVisualdeljuego->setScene(scene);
    ui->marcoVisualdeljuego->setBackgroundBrush(QBrush((QImage(":/images/Fondo.jpg"))));}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;}
