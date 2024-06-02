#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entidad.h"
#include "personaje.h"
#include <vector>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 8000, 667); // Área de mapa
    ui->marcoVisualdeljuego->setScene(scene);
    ui->marcoVisualdeljuego->setBackgroundBrush(QBrush(QImage(":/images/Fondo.jpg")));
;

    // Creamos suelo
    std::vector<Entidad*>entidades;
    int posi=0;
    int i;
    for (i=0; i < 6; ++i) {
        Entidad* nuevaEntidad = new Entidad(":/images/Bloques/Suelo.png", posi, 578);
        entidades.push_back(nuevaEntidad);
        posi += 80;
        scene->addItem(nuevaEntidad);}
    posi += 80;
    Entidad* nuevaEntidad2 = new Entidad(":/images/Bloques/Madera.png", posi-80, 504);
    entidades.push_back(nuevaEntidad2);
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi-80-160, 504-90);
    entidades.push_back(nuevaEntidad2);
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi, 504-180);
    entidades.push_back(nuevaEntidad2);
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi-160-160, 504-180);
    entidades.push_back(nuevaEntidad2);
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi-160-160-80, 504-180);
    entidades.push_back(nuevaEntidad2);
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi-320-160, 504-180);
    entidades.push_back(nuevaEntidad2);
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera3.png", posi-160-160-160-80, 504-180-90);
    entidades.push_back(nuevaEntidad2);
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi-160-160-80, 504-360);
    entidades.push_back(nuevaEntidad2);
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi-160-160, 504-360);
    entidades.push_back(nuevaEntidad2);
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi-160-80, 504-360);
    entidades.push_back(nuevaEntidad2);
    scene->addItem(nuevaEntidad2);
    posi+=240;
    for (i=0; i < 15; ++i) {
        Entidad* nuevaEntidad = new Entidad(":/images/Bloques/Suelo.png", posi, 578);
        entidades.push_back(nuevaEntidad);
        posi += 80;
        scene->addItem(nuevaEntidad);}
    personaje = new Personaje(":/images/Personaje principal/Personaje.png",0, 506);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    scene->addItem(personaje);
    qDebug() << "Personaje creado y agregado a la escena en la posición" << personaje->pos();

    // Conecta la señal de cambio de posición del personaje con el slot de seguimiento de vista
    connect(personaje, &Personaje::posChanged, this, &MainWindow::followPlayer);}

MainWindow::~MainWindow() {
    delete ui;
    delete scene;
    delete personaje;}

void MainWindow::followPlayer() {
    // Obtén la posición del personaje en relación con la vista
    QPointF playerPos = ui->marcoVisualdeljuego->mapFromScene(personaje->pos());

    // Obtén las dimensiones de la vista
    QRectF viewRect = ui->marcoVisualdeljuego->viewport()->rect();

    // Si el personaje se sale de la vista, centrar la vista en el personaje
    if (!viewRect.contains(playerPos.toPoint())) {
        ui->marcoVisualdeljuego->centerOn(personaje);}}
