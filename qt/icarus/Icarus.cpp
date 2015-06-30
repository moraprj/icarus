#include "Icarus.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Icarus app();

    return a.exec();
}


Icarus::Icarus():
    serial(QFile("config/serial.ini"))
{

}

Icarus::~Icarus()
{

}

