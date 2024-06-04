#include "personaje.h"
#include <QBrush>
#include <QColor>

Personaje::Personaje(const QString &imagePath, int x, int y, std::vector<QRect> rects_,QGraphicsItem *parent)
    : Entidad(imagePath, x, y, parent) {
    rects=rects_;
    // Posición Y inicial
}


