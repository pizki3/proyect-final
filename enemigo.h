#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "entidad.h"
#include <QTimer>
#include <QGraphicsScene>
#include <vector>

class Enemigo : public Entidad {
    Q_OBJECT

public:
    Enemigo(const QString &imagePath, int x, int y, qreal radius, qreal angularVelocity, std::vector<QRect> *enemigos,std::vector<QRect> *armas, QGraphicsItem *parent = nullptr);

    void startAnimation();
    void stopanimation();
    void movimiento();
    std::vector<QRect> *enemigos;
    std::vector<QRect> *armas;

public slots:
    void updatePosition();

private:
    qreal radius;
    qreal angularVelocity;
    qreal angle;
    QTimer *animationTimer;
    float tiempotrans;
    bool derecha;
    int limi;
    int lims;};

#endif // ENEMIGO_H
