#include "particula.h"
#include <QGraphicsScene>
#include <cmath>

Particula::Particula(const QString &imagePath, int x, int y, qreal initialVelocity, qreal initialTheta, QGraphicsItem *parent)
    : Entidad(imagePath, x, y, parent), velocity(initialVelocity), theta(initialTheta), tiempoTrans(0.0)
{
    xIn = posX;
    yIn = posY;
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Particula::updatePosition);
}

void Particula::startAnimation()
{
    tiempoTrans = 0.0;
    animationTimer->start(10); // Llama a updatePosition cada 10 ms
}

void Particula::updatePosition()
{
    tiempoTrans += 0.1;
    movParabolico(&tiempoTrans);
}

void Particula::resetPosition()
{
    setPos(xIn, yIn);
}

void Particula::movParabolico(float *dt)
{
    int dir = 1;
    QRectF sceneRect = scene()->sceneRect();
    viewRect = QSize(sceneRect.width(), sceneRect.height());

    posX = xIn + (velocity * cos(theta) * *dt) * dir;
    posY = yIn - (velocity * sin(theta) * *dt) + (0.5 * 9.8 * *dt * *dt);

    if (posX > viewRect.width() - 5 || posX < 0) {
        velocity = 0.8 * velocity;
        dir = -1 * dir;
        xIn = posX + 10 * dir;
        *dt = 0;
        yIn = posY;
        theta = 0;
    }

    if (posY > viewRect.height()) {
        // Restablecer la posición inicial
        resetPosition();
        return; // Salir de la función para evitar más actualizaciones
    }

    setPos(posX, posY);
}

