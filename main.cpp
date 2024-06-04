#include "mainwindow.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Crear un QCommandLineParser para manejar los parámetros de línea de comandos
    QCommandLineParser parser;
    parser.setApplicationDescription("Juego de ejemplo con parámetros de línea de comandos");
    parser.addHelpOption();
    parser.addVersionOption();

    // Definir la opción de línea de comandos para obstáculos adicionales
    QCommandLineOption obstaclesOption(QStringList() << "o" << "obstacles",
                                       "Número de obstáculos adicionales a crear.",
                                       "obstacles");

    // Agregar la opción al parser
    parser.addOption(obstaclesOption);

    // Parsear los argumentos de línea de comandos
    parser.process(a);

    // Obtener el valor de la opción
    int extraObstacles = parser.value(obstaclesOption).toInt();

    // Crear la ventana principal
    MainWindow w;

    // Aplicar las opciones de línea de comandos
    w.createObstacles(extraObstacles);

    w.show();
    return a.exec();}
