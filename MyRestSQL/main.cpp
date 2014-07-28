#include <QCoreApplication>
#include "myserver.h"
#include "factory.h"

Factory *Factory::instance = NULL;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyServer server;
    return a.exec();
}
