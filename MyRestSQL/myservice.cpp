#include "myservice.h"

/** Nom du service */
#define APPNAME "MyRestSQL"
/** Description du service */
#define DESCRIPTION "Serveur MyRestSQL"

MyService::MyService(int argc, char ** argv) : QtService<QCoreApplication>(argc, argv, APPNAME)
{
    setServiceDescription(DESCRIPTION);
    setServiceFlags(QtServiceBase::CanBeSuspended);
}

MyService::~MyService()
{
    try {

    } catch(...) {
        qCritical() << "Erreur dans le destructeur";
    }
}

void MyService::start()
{
    try {
        MyServer *server = new MyServer();
    } catch(...) {
        qCritical() << "Service: Erreur";
    }
}

void MyService::pause() {
    try {
        qDebug() << "service en pause !";
    } catch(...) {
        qCritical() << "Erreur à la pause du service MyService";
    }
}

void MyService::resume()
{
    try {
        qDebug() << "service résumé !";
    } catch(...) {
        qCritical() << "Erreur au resume du service MyService";
    }
}

void MyService::stop()
{
    try {
        qDebug() << "service arrété !";
    } catch(...) {
        qCritical() << "Erreur à l'arret du service MyService";
    }
}
