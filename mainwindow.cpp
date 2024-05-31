#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entidad.h"
#include "personaje.h"
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


    // Crear y agregar entidad a la escena con la imagen
    entidad = new Entidad(":/images/Bloques/Suelo.png", 0, 578);
    scene->addItem(entidad);
    qDebug() << "Entidad creada y agregada a la escena en la posición" << entidad->pos();

    personaje = new Personaje(":/images/Personaje principal/Personaje.png",0, 506);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    scene->addItem(personaje);
    qDebug() << "Personaje creado y agregado a la escena en la posición" << personaje->pos();

    // Conecta la señal de cambio de posición del personaje con el slot de seguimiento de vista
    connect(personaje, &Personaje::posChanged, this, &MainWindow::followPlayer);

}

MainWindow::~MainWindow() {
    delete ui;
    delete scene;
    delete personaje; // Asegúrate de eliminar personaje y entidad
    delete entidad;
}

void MainWindow::followPlayer() {
    // Obtén la posición del personaje en relación con la vista
    QPointF playerPos = ui->marcoVisualdeljuego->mapFromScene(personaje->pos());

    // Obtén las dimensiones de la vista
    QRectF viewRect = ui->marcoVisualdeljuego->viewport()->rect();

    // Si el personaje se sale de la vista, centrar la vista en el personaje
    if (!viewRect.contains(playerPos.toPoint())) {
        ui->marcoVisualdeljuego->centerOn(personaje);
    }
}
