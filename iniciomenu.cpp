#include "iniciomenu.h"
#include <QPushButton>
#include <QVBoxLayout>

InicioMenu::InicioMenu(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *startButton = new QPushButton("Iniciar Juego", this);
    layout->addWidget(startButton);

    setLayout(layout);

    connect(startButton, &QPushButton::clicked, this, &InicioMenu::startGame);
}
