#ifndef PARTICULA_H
#define PARTICULA_H
#include "entidad.h"
#include <QGraphicsScene>
#include <QTimer>
#include <vector>
#include <QLCDNumber>
#include <QTextBrowser>

class Particula : public Entidad {
    Q_OBJECT

public:
    Particula(const QString &imagePath, int x, int y, qreal initialVelocity, qreal initialTheta,std::vector<QRect> rects,std::vector<QRect> *enemigos,std::vector<QRect> *armas,QLCDNumber *,QGraphicsItem *parent = nullptr);

    void movParabolico(float *dt);
    void startAnimation();
    void resetPosition();
    void actualizar(int,int);

private slots:
    void updatePosition();

private:
    qreal pX;
    qreal pY;
    QSize viewRect;
    QTextBrowser *dis;
    float velocity, theta;
    qreal xIn, yIn;
    QTimer *animationTimer;
    QLCDNumber* lcdNumber;
    std::vector<QRect> rects;
    std::vector<QRect> *armas;
    std::vector<QRect> *enemigos;
    bool rei;
    float tiempoTrans;};

#endif // PARTICULA_H
