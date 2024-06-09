#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entidad.h"
#include "personaje.h"
#include "particula.h"
#include "bolafuego.h"
#include <QDebug>
#include <QLabel>
#include <QScrollBar>

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
    connect(ui->btnPause, &QPushButton::clicked, this, &MainWindow::pausarJuego);


    // Creamos suelo
    int posi = 0;
    int i;
    for (i = 0; i < 6; ++i) {
        Entidad* nuevaEntidad = new Entidad(":/images/Bloques/Suelo.png", posi, 578);
        entidades.push_back(nuevaEntidad);
        rects.push_back(QRect(posi, 595, 60, 80));
        posi += 80;
        scene->addItem(nuevaEntidad);}
    posi += 80;
    int pos=posi;
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
        scene->addItem(nuevaEntidad);}

    personaje = new Personaje(":/images/Personaje principal/Personaje.png", 0, 506, rects);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    scene->addItem(personaje);
    int velo=80;
    Bola = new BolaFuego(":/images/Personaje principal/Roca2.png",0,0, velo, 3);
    scene->addItem(Bola);
    tigre=new Personaje(":/images/Enemigos/Tigre", 90*20, 485, rects);
    scene->addItem(tigre);
    qDebug() << "Personaje creado y agregado a la escena en la posición" << personaje->pos();
    particula = new Particula(":/images/Personaje principal/Roca.png", 0, 506,60,45*(3.1415/180),rects,ui->lcdNumber,ui->textBrowser);
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

void MainWindow::Actualizarcronometro(float N){
    ui->lcdNumber->display(QString::number(N, '5', 2));}

void MainWindow::createObstacles(int count)
{
    for (int i = 1; i <= count; ++i) {
        Entidad* nuevaEntidad2 = new Entidad(":/images/Bloques/Madera.png", 480, 504-(90*i));
        entidades.push_back(nuevaEntidad2);
        rects.push_back(QRect(480, 504-(90*i), 60, 80));
        scene->addItem(nuevaEntidad2);}}

void MainWindow::followPlayer()
{
    // Distancia en el eje X a partir de la cual la vista seguirá al personaje
    qreal distanciaInicioSeguir = 400.0; // Ajusta este valor según tus necesidades

    // Obtén la posición del personaje en la escena
    QPointF playerPos = personaje->pos();

    // Obtener la posición actual de la vista
    qreal viewX = ui->marcoVisualdeljuego->horizontalScrollBar()->value();

    // Calcular la nueva posición de la vista
    qreal nuevaPosicionVistaX = playerPos.x() - distanciaInicioSeguir;

    // Actualizar la posición de la vista si la nueva posición es diferente
    if (nuevaPosicionVistaX != viewX) {
        ui->marcoVisualdeljuego->horizontalScrollBar()->setValue(nuevaPosicionVistaX);
    }
}



void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (!juegoPausado) {
        // Procesar eventos de teclado solo si el juego no está pausado
        int newX = personaje->getPosicionX();
        int newY = personaje->getPosicionY();

        QString nuevaImagen;

        switch (event->key()) {
        case Qt::Key_A:
            newX -= 8;
            nuevaImagen = ":/images/Personaje principal/Caminar1.png";
            break;
        case Qt::Key_D:
            newX += 8;
            nuevaImagen = ":/images/Personaje principal/Caminar.png";
            break;
        case Qt::Key_E:
            newY -= 90;
            newX += 80;
            nuevaImagen = ":/images/Personaje principal/Personaje_salto_derecha.png";
            break;
        case Qt::Key_Q:
            newY -= 90;
            newX -= 80;
            nuevaImagen = ":/images/Personaje principal/Personaje_salto_izquierda.png";
            break;
        case Qt::Key_S:
            newY += 10;
            nuevaImagen = ":/images/Personaje principal/Personaje_agachado.png";
            break;
        case Qt::Key_W:
            newY -= 90;
            nuevaImagen = ":/images/Personaje principal/Personaje_salto.png";
            break;
        case Qt::Key_P:
            particula->actualizar(newX, newY);
            particula->startAnimation();
            return; // No cambiar la imagen del personaje al presionar P
        default:
            return;
        }

        // Cambiar la imagen del personaje
        personaje->setImagen(nuevaImagen);

        // Usar un QTimer para volver a la imagen original después de un breve período de tiempo
        QTimer::singleShot(400, [this]() {
            personaje->setImagen(":/images/Personaje principal/Personaje.png");
        });

        QRect R1(newX, newY, 80, 80);
        if (!personaje->colisionaCon(rects, R1)) {
            personaje->setPos(newX, newY);
            personaje->actualizar(newX, newY);
            particula->actualizar(newX, newY);
            particula->setPos(newX, newY);

            // Llamar a followPlayer para ajustar la vista según la posición del personaje
            followPlayer();}}}


void MainWindow::pausarJuego()
{
    juegoPausado = !juegoPausado;

    if (juegoPausado) {
        // Si el juego está pausado, desactivar el foco del widget principal
        ui->marcoVisualdeljuego->clearFocus();
        Bola->stopanimation();
        // Crear un grupo para la imagen de pausa
        QGraphicsItemGroup *pausaGroup = new QGraphicsItemGroup;

        // Obtener la posición del botón de pausa en relación a la ventana principal
        QPoint botonPosGlobal = ui->btnPause->mapToGlobal(QPoint(0, ui->btnPause->height()));

        // Convertir las coordenadas globales a las coordenadas de la vista de la escena
        QPoint botonPos = ui->marcoVisualdeljuego->mapFromGlobal(botonPosGlobal);

        // Convertir las coordenadas de la vista a las coordenadas de la escena
        QPointF botonPosScene = ui->marcoVisualdeljuego->mapToScene(botonPos);

        // Mostrar una imagen de pausa
        QPixmap pixmap(":/images/Pausa.png");
        QGraphicsPixmapItem *pausaItem = new QGraphicsPixmapItem(pixmap);
        // Posicionar la imagen justo debajo del botón de pausa
        pausaItem->setPos(botonPosScene.x()-50, botonPosScene.y()+200);
        pausaGroup->addToGroup(pausaItem);
        scene->addItem(pausaGroup);}

    else {// Si el juego se reanuda, eliminar la imagen de pausa si existe
        QList<QGraphicsItem*> items = scene->items();
        Bola->startAnimation();
        for (QGraphicsItem *item : items) {
            if (dynamic_cast<QGraphicsItemGroup*>(item)) {
                scene->removeItem(item);
                delete item;
                break;}}
        ui->marcoVisualdeljuego->setFocus();}}
