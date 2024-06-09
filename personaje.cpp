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
    animationTimer2 = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Personaje::updatePosition);
    connect(animationTimer2, &QTimer::timeout, this, &Personaje::updatePosition2);
}

void Personaje::startAnimation()
{
    tiempoTrans = 0.0;
    animationTimer->start(10);}

void Personaje::startAnimation2()
{
    tiempoTrans = 0.0;
    animationTimer2->start(10);}

void Personaje::actualizar(int x, int y)
{
    xIn = x;
    yIn = y;
}

void Personaje::updatePosition()
{
    tiempoTrans += 0.1;
    movimiento(&tiempoTrans);
}

void Personaje::updatePosition2()
{
    tiempoTrans += 0.1;
    movimiento2(&tiempoTrans);}

void Personaje::movimiento2(float *dt)
{
    int dir =-1;
    QRectF sceneRect = scene()->sceneRect();
    viewRect = QSize(sceneRect.width(), sceneRect.height());

    qreal adjustedVelocity = velocity * 0.4;
    qreal jumpVelocity = 60.0;
    qreal gravity = 10;

    // Calculamos la nueva posición del personaje
    posX = xIn + (adjustedVelocity * cos(theta) * *dt) * dir;
    posY = yIn - (jumpVelocity * sin(theta) * *dt) + (0.5 * gravity * *dt * *dt);

    if (posX > viewRect.width() - 5 || posX < 0) {
        velocity = 0.8 * velocity;
        dir = -1 * dir;
        xIn = posX + 10 * dir;
        *dt = 0;
        yIn = posY;
        theta = 0;
    }

    QRect R1(posX, posY, 10, 70);
    if (colisionaCon(rects, R1)) {
        if (jumpVelocity * sin(theta) - gravity * *dt > 0) {
            animationTimer2->stop();
            setPos(posX, yIn);}
        else {
            animationTimer2->stop();
            setPos(posX, posY - 22);}
        return;}
    setPos(posX, posY);}


void Personaje::movimiento(float *dt)
{
    int dir =1;
    QRectF sceneRect = scene()->sceneRect();
    viewRect = QSize(sceneRect.width(), sceneRect.height());

    qreal adjustedVelocity = velocity * 0.4;
    qreal jumpVelocity = 60.0;
    qreal gravity = 10;

    // Calculamos la nueva posición del personaje
    posX = xIn + (adjustedVelocity * cos(theta) * *dt) * dir;
    posY = yIn - (jumpVelocity * sin(theta) * *dt) + (0.5 * gravity * *dt * *dt);

    if (posX > viewRect.width() - 5 || posX < 0) {
        velocity = 0.8 * velocity;
        dir = -1 * dir;
        xIn = posX + 10 * dir;
        *dt = 0;
        yIn = posY;
        theta = 0;}

    QRect R1(posX, posY, 10, 70);
    if (colisionaCon(rects, R1)) {
        if (jumpVelocity * sin(theta) - gravity * *dt > 0) {
            animationTimer->stop();
            setPos(posX, yIn);}
        else {
            animationTimer->stop();
            setPos(posX, posY - 22);}
        return;}
    setPos(posX, posY);}

