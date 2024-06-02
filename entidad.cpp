#include "entidad.h"
#include <QPixmap>

Entidad::Entidad(const QString &imagePath, int x, int y, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), posY(y), posX(x) {
    setPixmap(QPixmap(imagePath)); // Establece la imagen
    setPos(posX, posY);}

void Entidad::setPosicion(int x, int y) {
    posX = x;
    posY = y;
    setPos(posX, posY);}

QPoint Entidad::getPosicion() const {
    return QPoint(posX, posY);}
