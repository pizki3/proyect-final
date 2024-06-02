#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Entidad : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

protected:
    int posY;
    int posX;

public:
    Entidad(const QString &imagePath, int x, int y, QGraphicsItem *parent = nullptr);
    void setPosicion(int x, int y);
    QPoint getPosicion() const;};

#endif // ENTIDAD_H
