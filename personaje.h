#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "entidad.h"
#include <QKeyEvent>
#include <QTimer>
#include <vector>
#include <QRect>

class Personaje : public Entidad {
    Q_OBJECT
public:
    Personaje(const QString &imagePath, int x, int y, std::vector<QRect> rects_, QGraphicsItem *parent = nullptr);
private:
    std::vector<QRect> rects;};

#endif // PERSONAJE_H
