#include "entidad.h"
#include <QPixmap>

Entidad::Entidad(const QString &imagePath, int x, int y, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), posX(x), posY(y) {
    setPixmap(QPixmap(imagePath)); // Establece la imagen
    setPos(posX, posY);}


int Entidad::getPosY() const {
    return posY;
}
void Entidad::setPosicion(int x, int y) {
    posX = x;
    posY = y;
    setPos(posX, posY);
}

QPoint Entidad::getPosicion() const {
    return QPoint(posX, posY);
}
