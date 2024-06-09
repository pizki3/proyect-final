#include "entidad.h"
#include <QPixmap>
#include <vector>

Entidad::Entidad(const QString &imagePath, int x, int y, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), posY(y), posX(x) {
    setPixmap(QPixmap(imagePath)); // Establece la imagen
    setPos(posX, posY);}

int Entidad::getPosicionX(){
    return posX;}

int Entidad::getPosicionY(){
    return posY;}

void Entidad:: actualizar(int X,int Y){
    posX=X;
    posY=Y;}

bool Entidad::colisionaCon(std::vector<QRect> rects,QRect r1){
    int N = rects.size();
    for(int i=0; i<N;i++){
        if(r1.intersects(rects[i])){
            return r1.intersects(rects[i]);}}
    return r1.intersects(rects[0]);}
