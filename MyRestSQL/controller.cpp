#include "usercontroller.h"

Controller::Controller()
{
    qDebug() << "Controller";
}

void Controller::responder(QHttpResponse *resp, int status)
{
    resp->setHeader("Content-Type", "Application/xml");
    resp->writeHead(status);

    QString body = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><state>completed</state>";
    resp->end(body.toUtf8());
}

