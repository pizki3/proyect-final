#include "bolafuego.h"
#include <cmath>

BolaFuego::BolaFuego(const QString &imagePath, int x, int y, qreal radius, qreal angularVelocity, QGraphicsItem *parent)
    : Entidad(imagePath, x, y, parent), radius(radius), angularVelocity(angularVelocity), angle(0.0)
{
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &BolaFuego::updatePosition);
    startAnimation();}

void BolaFuego::startAnimation()
{
    animationTimer->start(10); // Llama a updatePosition cada 10 ms
}

void BolaFuego::updatePosition()
{
    angle += angularVelocity * 0.01; // Incrementa el ángulo para el movimiento circular
    movCircular(&angle);
}

void BolaFuego::movCircular(qreal *dt)
{
    qreal xCenter = 500; // Define el centro de la circunferencia en el eje x
    qreal yCenter = 150; // Define el centro de la circunferencia en el eje y

    qreal posX = xCenter + radius * cos(*dt);
    qreal posY = yCenter + radius * sin(*dt);

    setPos(posX, posY);
}

