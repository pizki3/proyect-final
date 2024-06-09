#include "tiempovuelowidget.h"
#include <QVBoxLayout>


TiempoVueloWidget::TiempoVueloWidget(QWidget *parent) : QWidget(parent)
{
    // Configuración del widget
    tiempoLabel = new QLabel("Tiempo de vuelo: ", this); // Etiqueta para mostrar el tiempo de vuelo
    // Agregar el QLabel al layout del widget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tiempoLabel);
}

void TiempoVueloWidget::setTiempoVuelo(double tiempo)
{
    tiempoLabel->setText(QString("Tiempo de vuelo: %1").arg(tiempo));}
