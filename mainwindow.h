#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "personaje.h"
#include "entidad.h" // Incluir entidad.h

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void followPlayer();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Personaje *personaje;
    Entidad *entidad; // Declarar entidad
};

#endif // MAINWINDOW_H

