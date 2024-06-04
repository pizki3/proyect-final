#ifndef BOLAFUEGO_H
#define BOLAFUEGO_H

#include "entidad.h"
#include <QTimer>
#include <QGraphicsScene>
#include <vector>

class BolaFuego : public Entidad {
    Q_OBJECT

public:
    BolaFuego(const QString &imagePath, int x, int y, qreal radius, qreal angularVelocity, QGraphicsItem *parent = nullptr);

    void startAnimation();
    void movCircular(qreal *dt);

private slots:
    void updatePosition();

private:
    qreal radius;
    qreal angularVelocity;
    qreal angle;
    QTimer *animationTimer;
};

#endif // BOLAFUEGO_H
