#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "entidad.h"
#include <QKeyEvent>
#include <QTimer>

class Personaje : public Entidad {
    Q_OBJECT
public:
    Personaje(const QString &imagePath, int x, int y, QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void posChanged();  // Señal para notificar el cambio de posición

private slots:
    void jump();

private:
    QTimer *jumpTimer;
    bool jumpingUp;
    int jumpHeight;
    int jumpSpeed;
    int initialY;
};

#endif // PERSONAJE_H
