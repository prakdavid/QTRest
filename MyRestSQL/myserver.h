#ifndef MYSERVER_H
#define MYSERVER_H

#include <qhttpserver.h>
#include <qhttprequest.h>
#include <qhttpresponse.h>

#include "controller.h"
#include "usercontroller.h"

#include <QRegExp>
#include <QStringList>
#include <QDebug>

class MyServer : public QObject
{
    Q_OBJECT
public:
    MyServer();
    void dispatcher();
private slots:
    void handleRequest(QHttpRequest *req, QHttpResponse *resp);
};

#endif // MYSERVER_H
