#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <vector>
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

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void followPlayer();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Personaje *personaje;
    Personaje *tigre;
    Particula *particula;
    std::vector<QRect> rects;
};

#endif // MAINWINDOW_H
