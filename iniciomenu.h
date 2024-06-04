#ifndef INICIOMENU_H
#define INICIOMENU_H

#include <QWidget>

class InicioMenu : public QWidget
{
    Q_OBJECT

public:
    explicit InicioMenu(QWidget *parent = nullptr);

signals:
    void startGame();
};

#endif // INICIOMENU_H
