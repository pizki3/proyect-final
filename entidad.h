#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Entidad : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Entidad(const QString &imagePath, int x, int y, QGraphicsItem *parent = nullptr);
    void setPosicion(int x, int y);
    QPoint getPosicion() const;
    int getPosY() const;

protected:
    int posY;
    int posX;
};

#endif // ENTIDAD_H
