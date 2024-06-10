#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "entidad.h"
#include "mainwindow.h"
#include <vector>
#include <QRect>
#include <QTimer>
#include <QObject>

class MainWindow;

class Personaje : public Entidad {
    Q_OBJECT
public:
    Personaje(const QString &imagePath, int x, int y, qreal initialVelocity, qreal initialTheta, std::vector<QRect> rects,std::vector<QRect> *enemigos,MainWindow *mainWindow);
    void startAnimation();
    void startAnimation2();
    void actualizar(int x, int y);
    void movimiento(float *dt);
    void movimiento2(float *dt);
    void init(const QString &imagePath, int x, int y, qreal initialVelocity, qreal initialTheta, std::vector<QRect> rects, std::vector<QRect> *enemigos, MainWindow *mainWindow);

private:
    qreal pX;
    qreal pY;
    QSize viewRect;
    float velocity, theta;
    qreal xIn, yIn;
    QTimer *animationTimer;
    QTimer *animationTimer2;
    std::vector<QRect> rects;
    std::vector<QRect> *enemigos;
    MainWindow *mainWindow;
    float tiempoTrans;

private slots:
    void updatePosition();
    void updatePosition2();};

#endif // PERSONAJE_H
