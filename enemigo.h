#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "bolafuego.h"
#include <vector>

class Enemigo : public BolaFuego {
public:
    Enemigo(const QString &imagePath, int x, int y, qreal radius, qreal angularVelocity, std::vector<QRect> *enemigos, QGraphicsItem *parent = nullptr);
    void movCircular(qreal *dt);
};

#endif // ENEMIGO_H
