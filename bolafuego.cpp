#include "bolafuego.h"
#include <cmath>
#include <QLCDNumber>
#include "mainwindow.h"
#include <QGraphicsScene>

BolaFuego::BolaFuego(const QString &imagePath, int x, int y, qreal radius, qreal angularVelocity,std::vector<QRect> *enemigos, QGraphicsItem *parent)
    : Entidad(imagePath, x, y, parent), radius(radius), angularVelocity(angularVelocity), angle(0.0),enemigos(enemigos)
{
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &BolaFuego::updatePosition);
    startAnimation();}

void BolaFuego::startAnimation()
{
    animationTimer->start(10);}

void BolaFuego::stopanimation(){
    animationTimer->stop();}

void BolaFuego::updatePosition()
{
    angle += angularVelocity * 0.01; // Incrementa el ángulo para el movimiento circular
    movCircular(&angle);}

void BolaFuego::movCircular(qreal *dt)
{
    qreal xCenter = 500; // Define el centro de la circunferencia en el eje x
    qreal yCenter = 150; // Define el centro de la circunferencia en el eje y
    qreal posX = xCenter + radius * cos(*dt);
    qreal posY = yCenter + radius * sin(*dt);
    int x=posX;
    (*enemigos)[0] = QRect(posX, posY, 25, 25);
    setPos(posX, posY);}

