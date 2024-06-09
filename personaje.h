#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "entidad.h"
#include <vector>
#include <QRect>
#include <QTimer>

class Personaje : public Entidad {
    Q_OBJECT
public:
    Personaje(const QString &imagePath, int x, int y, qreal initialVelocity, qreal initialTheta, std::vector<QRect> rects_);

    void startAnimation();
    void actualizar(int x, int y);
    void resetPosition();

private:
    qreal pX;
    qreal pY;
    QSize viewRect;
    float velocity, theta;
    qreal xIn, yIn;
    QTimer *animationTimer;
    std::vector<QRect> rects;
    float tiempoTrans;

    void movParabolico(float *dt);

private slots:
    void updatePosition();
};

#endif // PERSONAJE_H
