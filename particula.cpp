#include "particula.h"
#include "mainwindow.h"
#include <QGraphicsScene>
#include <cmath>

Particula::Particula(const QString &imagePath, int x, int y, qreal initialVelocity, qreal initialTheta,std::vector<QRect> rects_,std::vector<QRect> *enemigos_,std::vector<QRect> *armas,QLCDNumber* lcdNumber_, QGraphicsItem *parent)
    : Entidad(imagePath, x, y, parent), velocity(initialVelocity), theta(initialTheta), tiempoTrans(0.0), rects(rects_),enemigos(enemigos_),armas(armas)
{   lcdNumber=lcdNumber_;
    xIn = posX;
    yIn = posY;
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Particula::updatePosition);}

void Particula::startAnimation()
{
    tiempoTrans = 0.0;
    animationTimer->start(10);}

void Particula::actualizar(int x,int y)
{
    xIn=x;
    yIn=y;}

void Particula::updatePosition()
{
    tiempoTrans += 0.1;
    movParabolico(&tiempoTrans);}

void Particula::resetPosition()
{
    (*armas)[0] = QRect(0, yIn,10, 10);
    setPos(xIn, yIn);}

void Particula::movParabolico(float *dt)
{
    int dir=1;
    QRectF sceneRect = scene()->sceneRect();
    viewRect = QSize(sceneRect.width(), sceneRect.height());

    posX = xIn + (velocity * cos(theta) * *dt) * dir;
    posY = yIn - (velocity * sin(theta) * *dt) + (0.5 * 9.8 * *dt * *dt);
    int suma=0;

    if (posX > viewRect.width() - 5 || posX < 0) {
        velocity = 0.8 * velocity;
        dir = -1 * dir;
        xIn = posX + 10 * dir;
        *dt = 0;
        yIn = posY;
        theta = 0;}

    QRect R1(posX, posY,10,10);

    if (colisionaCon(rects,R1)){
        animationTimer->stop();
        (*armas)[0] = QRect(posX, posY,80, 80);
        resetPosition();
        return;}
    if (colisionaCon(*enemigos,R1) ){
        rei=true;
        if(rei==true){
            (*armas)[0] = QRect(posX, posY,80, 80);
            rei=false;}
        else{
            animationTimer->stop();
            resetPosition();}
        return;}

    setPos(posX, posY);
    (*armas)[0] = QRect(posX, posY,10, 10);}
