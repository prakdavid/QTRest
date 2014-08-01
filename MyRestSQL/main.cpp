#include <QCoreApplication>

#include "myservice.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyService serv(argc, argv);
    serv.start();
    return a.exec();
}
