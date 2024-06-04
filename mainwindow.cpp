#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entidad.h"
#include "personaje.h"
#include "particula.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , particula(nullptr) // Inicializar la partícula a nullptr
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 8000, 667); // Área de mapa
    ui->marcoVisualdeljuego->setScene(scene);
    ui->marcoVisualdeljuego->setBackgroundBrush(QBrush(QImage(":/images/Fondo.jpg")));

    // Creamos suelo
    std::vector<Entidad*> entidades;
    int posi = 0;
    int i;
    for (i = 0; i < 6; ++i) {
        Entidad* nuevaEntidad = new Entidad(":/images/Bloques/Suelo.png", posi, 578);
        entidades.push_back(nuevaEntidad);
        rects.push_back(QRect(posi, 595, 60, 80));
        posi += 80;
        scene->addItem(nuevaEntidad);}
    posi += 80;
    Entidad* nuevaEntidad2 = new Entidad(":/images/Bloques/Madera.png", posi - 80, 504);
    entidades.push_back(nuevaEntidad2);
    rects.push_back(QRect(posi - 80, 504 + 10, 60, 80));
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi - 80 - 160, 504 - 90);
    entidades.push_back(nuevaEntidad2);
    rects.push_back(QRect(posi - 80 - 160, 504 - 90 + 10, 60, 80));
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi, 504 - 180);
    entidades.push_back(nuevaEntidad2);
    rects.push_back(QRect(posi, 504 - 180 + 10, 60, 80));
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi - 160 - 160, 504 - 180);
    entidades.push_back(nuevaEntidad2);
    rects.push_back(QRect(posi - 160 - 160, 504 - 180 + 10, 60, 80));
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi - 160 - 160 - 80, 504 - 180);
    entidades.push_back(nuevaEntidad2);
    rects.push_back(QRect(posi - 160 - 160 - 80, 504 - 180 + 10, 60, 80));
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi - 320 - 160, 504 - 180);
    entidades.push_back(nuevaEntidad2);
    rects.push_back(QRect(posi - 320 - 160, 504 - 180 + 10, 60, 80));
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera3.png", posi - 160 - 160 - 160 - 80, 504 - 180 - 90);
    entidades.push_back(nuevaEntidad2);
    rects.push_back(QRect(posi - 160 - 160 - 160 - 80, 504 - 180 - 90 + 10, 60, 80));
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi - 160 - 160 - 80, 504 - 360);
    entidades.push_back(nuevaEntidad2);
    rects.push_back(QRect(posi - 160 - 160 - 80, 504 - 360 + 10, 60, 80));
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi - 160 - 160, 504 - 360);
    entidades.push_back(nuevaEntidad2);
    rects.push_back(QRect(posi - 160 - 160, 504 - 360 + 10, 60, 80));
    scene->addItem(nuevaEntidad2);
    nuevaEntidad2 = new Entidad(":/images/Bloques/Madera2.png", posi - 160 - 80, 504 - 360);
    entidades.push_back(nuevaEntidad2);
    rects.push_back(QRect(posi - 160 - 80, 504 - 360 + 10, 60, 80));
    scene->addItem(nuevaEntidad2);
    posi += 240;
    for (i = 0; i < 15; ++i) {
        Entidad* nuevaEntidad = new Entidad(":/images/Bloques/Suelo.png", posi, 578);
        entidades.push_back(nuevaEntidad);
        rects.push_back(QRect(posi, 595, 60, 80));
        posi += 80;
        scene->addItem(nuevaEntidad);
    }
    personaje = new Personaje(":/images/Personaje principal/Personaje.png", 0, 506, rects);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    scene->addItem(personaje);
    tigre=new Personaje(":/images/Enemigos/Tigre", 90*20, 485, rects);
    scene->addItem(tigre);
    qDebug() << "Personaje creado y agregado a la escena en la posición" << personaje->pos();
    particula = new Particula(":/images/Personaje principal/Roca.png", 0, 506,60,45*(3.1415/180));
    particula->setFlag(QGraphicsItem::ItemIsFocusable);
    particula->setFocus();
    scene->addItem(particula);
    setFocus();}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete personaje;
    if (particula) {
        delete particula;
    }
}

void MainWindow::followPlayer()
{
    // Obtén la posición del personaje en relación con la vista
    QPointF playerPos = ui->marcoVisualdeljuego->mapFromScene(personaje->pos());

    // Obtén las dimensiones de la vista
    QRectF viewRect = ui->marcoVisualdeljuego->viewport()->rect();

    // Si el personaje se sale de la vista, centrar la vista en el personaje
    if (!viewRect.contains(playerPos.toPoint())) {
        ui->marcoVisualdeljuego->centerOn(personaje);}}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int newX = personaje->getPosicionX();
    int newY = personaje->getPosicionY();

    switch (event->key()) {
    case Qt::Key_A:
        newX -= 10;
        break;
    case Qt::Key_D:
        newX += 10;
        break;
    case Qt::Key_E:
        newY -= 90;
        newX += 80;
        break;
    case Qt::Key_Q:
        newY -= 90;
        newX -= 80;
        break;
    case Qt::Key_S:
        newY += 10;
        break;
    case Qt::Key_W:
        newY -= 90;
        break;
    case Qt::Key_P:
        particula->startAnimation();
        break;

    default:
        return;
    }

    QRect R1(newX, newY, 80, 80);
    if (!personaje->colisionaCon(rects, R1)) {
        personaje->setPos(newX, newY);
        personaje->actualizar(newX, newY);
        particula->actualizar(newX, newY);
        particula->setPos(newX, newY);
    }
}
