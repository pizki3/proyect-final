#include "enemigo.h"
#include <cmath>
#include <QLCDNumber>
#include "mainwindow.h"
#include <iostream>
#include <QGraphicsScene>


Enemigo::Enemigo(const QString &imagePath, int x, int y, qreal radius, qreal angularVelocity,std::vector<QRect> *enemigos,std::vector<QRect> *armas, QGraphicsItem *parent)
    : Entidad(imagePath, x, y, parent), radius(radius), angularVelocity(angularVelocity), angle(0.0),enemigos(enemigos),armas(armas)
{
    vida=45;
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Enemigo::updatePosition);
    limi=posX+90;
    lims=posX-90*5;
    derecha=false;
    startAnimation();}

void Enemigo::startAnimation()
{
    animationTimer->start(10);}

void Enemigo::stopanimation(){
    animationTimer->stop();}

void Enemigo::updatePosition()
{
    movimiento();}

void Enemigo::movimiento()
{
    if (posX >limi)
    {derecha = false;}
    else if (posX < lims)
    {derecha = true;}
    if (derecha==true)
    {posX += 1;
        (*enemigos)[1] = QRect(posX, posY, 80, 80);}
    else{
        posX -= 5;
        (*enemigos)[1] = QRect(posX, posY, 80, 80);}
    QRect R1(posX, posY, 70, 80);
    if(colisionaCon(*armas,R1)){
        setPixmap(QPixmap(":/images/Enemigos/Tigre2"));
        vida=vida-1;
        std::cout<<vida<<std::endl;}
    else{
        //setPixmap(QPixmap(":/images/Enemigos/Tigre"));
    }
    if(vida==0){
        setPixmap(QPixmap());
        (*enemigos)[5] = QRect(-posX, -posY, 80, 80);
        animationTimer->stop();}
    setPos(posX, posY);}
