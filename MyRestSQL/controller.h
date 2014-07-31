#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <qhttpresponse.h>
#include <qhttpserver.h>
#include <qhttprequest.h>

#include <QRegExp>
#include <QStringList>
#include <QDebug>
#include <QtXml>

class Controller
{
public:
    Controller();
    virtual ~Controller() {}
    void responder(QHttpResponse *resp, int status);

};


#endif // CONTROLLER_H
