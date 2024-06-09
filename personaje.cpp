#include "personaje.h"
#include <QBrush>
#include <QGraphicsScene>
#include <QColor>
#include <cmath>

Personaje::Personaje(const QString &imagePath, int x, int y, qreal initialVelocity, qreal initialTheta, std::vector<QRect> rects_)
    : Entidad(imagePath, x, y, nullptr), velocity(initialVelocity), theta(initialTheta), tiempoTrans(0.0), rects(rects_)
{
    xIn = pos().x();
    yIn = pos().y();
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Personaje::updatePosition);
}

void Personaje::startAnimation()
{
    tiempoTrans = 0.0;
    animationTimer->start(10);
}

void Personaje::actualizar(int x, int y)
{
    xIn = x;
    yIn = y;
}

void Personaje::updatePosition()
{
    tiempoTrans += 0.1;
    movParabolico(&tiempoTrans);
}

void Personaje::resetPosition()
{
    setPos(xIn, yIn);
}

void Personaje::movParabolico(float *dt)
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

    QRect R1(posX, posY, 80, 80);
    if (colisionaCon(rects, R1)) {
        animationTimer->stop();
        resetPosition();
        return;
    }

    setPos(posX, posY);
}
