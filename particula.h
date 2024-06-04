#ifndef PARTICULA_H
#define PARTICULA_H

#include "entidad.h"
#include <QGraphicsScene>
#include <QTimer>
#include <vector>

class Particula : public Entidad {
    Q_OBJECT

public:
    Particula(const QString &imagePath, int x, int y, qreal initialVelocity, qreal initialTheta,std::vector<QRect> rects_, QGraphicsItem *parent = nullptr);

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
    float velocity, theta;
    qreal xIn, yIn;
    QTimer *animationTimer;
    std::vector<QRect> rects;
    float tiempoTrans;
};

#endif // PARTICULA_H
