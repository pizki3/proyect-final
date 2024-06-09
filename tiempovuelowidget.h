#ifndef TIEMPOVUELOWIDGET_H
#define TIEMPOVUELOWIDGET_H

#include <QWidget>
#include <QLabel>

class TiempoVueloWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TiempoVueloWidget(QWidget *parent = nullptr);

public slots:
    void setTiempoVuelo(double tiempo); // Método para establecer el tiempo de vuelo

private:
    QLabel *tiempoLabel; // Etiqueta para mostrar el tiempo de vuelo
};

#endif // TIEMPOVUELOWIDGET_H
