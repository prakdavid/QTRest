#include "myserver.h"

MyServer::MyServer()
{
    QHttpServer *server = new QHttpServer(this);
    connect(server, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),
        this, SLOT(handleRequest(QHttpRequest*, QHttpResponse*)));

    server->listen(QHostAddress::Any, 8080);
}

void MyServer::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{

    // qDebug() << req->methodString();
    // qDebug() << req->method();
    //
    // Il faudrait faire un dispatcher de controller
    QStringList route = QString(req->path()).split('/');
    qDebug() << route << "route";

    // on verra plus tard pour les pointeur sur fonction
    if (route[1] == QString("user")) {
        qDebug() << "call user controller";
    }

    qDebug() << req->path();
    QRegExp exp("^/user/([a-z]+)$");

    if( exp.indexIn(req->path()) != -1 )
    {
        resp->setHeader("Content-Type", "text/html");
        resp->writeHead(200);

        QString name = exp.capturedTexts()[1];
        QString body = tr("<html><head><title>Greeting App</title></head><body><h1>Hello %1!</h1></body></html>");
        resp->end(body.arg(name).toUtf8());
    }
    else
    {
        resp->writeHead(403);
        resp->end(QByteArray("You aren't allowed here!"));
    }
}

void MyServer::dispatcher()
{

}
