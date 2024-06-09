#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <vector>
#include <QLCDNumber>
#include "bolafuego.h"
#include "personaje.h"
#include "particula.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createObstacles(int count);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void Actualizarcronometro(float);

private slots:
    void followPlayer();
    void pausarJuego();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Personaje *personaje;
    Personaje *tigre;
    Particula *particula;
    BolaFuego *Bola;
    bool juegoPausado;
    std::vector<QRect> rects;
    std::vector<QRect> enemigos;
    std::vector<Entidad*> entidades;
};

#endif // MAINWINDOW_H
