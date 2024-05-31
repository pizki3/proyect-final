#include "personaje.h"
#include <QBrush>
#include <QColor>

Personaje::Personaje(const QString &imagePath, int x, int y, QGraphicsItem *parent)
    : Entidad(imagePath, x, y, parent) {
    jumpTimer = new QTimer(this);
    connect(jumpTimer, &QTimer::timeout, this, &Personaje::jump);
    jumpingUp = false;
    jumpHeight = 150;       // Altura máxima del salto
    jumpSpeed = 10;         // Velocidad del salto
    initialY = posY;     // Posición Y inicial
}

void Personaje::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_A:
        setPos(x() - 10, y());
        emit posChanged(); // Emitir la señal posChanged
        break;
    case Qt::Key_D:
        setPos(x() + 10, y());
        emit posChanged(); // Emitir la señal posChanged
        break;
    case Qt::Key_S:
        setPos(x(), y() + 10);
        emit posChanged(); // Emitir la señal posChanged
        break;
    case Qt::Key_Space:
        if (!jumpingUp) {
            jumpingUp = true;
            initialY = posY;  // Actualizar la posición Y inicial
            jumpTimer->start(30);  // Iniciar el temporizador para el salto
        }
        break;
    default:
        break;
    }
}

void Personaje::jump() {
    if (jumpingUp) {
        setPos(x(), y() - jumpSpeed);  // Mover hacia arriba
        if (y() <= initialY - jumpHeight) {
            jumpingUp = false;  // Iniciar la caída
        }
    } else {
        setPos(x(), y() + jumpSpeed);  // Mover hacia abajo
        if (y() >= initialY) {
            setPos(x(), initialY);     // Asegurarse de que vuelva a la posición inicial
            jumpTimer->stop();         // Detener el temporizador
            emit posChanged();         // Emitir la señal posChanged
        }
    }
}
