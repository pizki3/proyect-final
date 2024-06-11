#ifndef BOLAFUEGO_H
#define BOLAFUEGO_H

#include "entidad.h"
#include <QTimer>
#include <QGraphicsScene>
#include <vector>

class BolaFuego : public Entidad {
    Q_OBJECT

public:
    BolaFuego(const QString &imagePath, int x, int y, qreal radius, qreal angularVelocity, std::vector<QRect> *enemigos,int,QGraphicsItem *parent = nullptr);

    void startAnimation();
    void stopanimation();
    void movCircular(qreal *dt);
    std::vector<QRect> *enemigos;

public slots:
    void updatePosition();

private:
    qreal radius;
    qreal angularVelocity;
    qreal angle;
    QTimer *animationTimer;
    float tiempotrans;
    int pos;
};

#endif // BOLAFUEGO_H
