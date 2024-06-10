#include "enemigo.h"

Enemigo::Enemigo(const QString &imagePath, int x, int y, qreal radius, qreal angularVelocity, std::vector<QRect> *enemigos, QGraphicsItem *parent)
    : BolaFuego(imagePath, x, y, radius, angularVelocity, enemigos, parent)
{
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Enemigo::updatePosition);
    startAnimation();

}
void Enemigo::movCircular(qreal *dt)
{
    posX=90*20;
    posY=485;
    setPos(posX, posY);}
