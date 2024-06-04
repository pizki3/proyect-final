#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <vector>

class Entidad : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

protected:
    int posY;
    int posX;
    int vida;
    int daño;

public:
    Entidad(const QString &imagePath, int x, int y, QGraphicsItem *parent = nullptr);
    int getPosicionX();
    int getPosicionY();
    void actualizar(int,int);
    bool colisionaCon(std::vector<QRect> rects,QRect r1);};
#endif // ENTIDAD_H
