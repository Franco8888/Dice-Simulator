#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "randomnumbergenerator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //RandomNumberGenerator rng(1, 5);
    //rng.getRandomNumber(3);
    MainWindow w;
    w.show();

    return a.exec();
}
