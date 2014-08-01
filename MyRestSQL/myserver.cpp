#include "myserver.h"

MyServer::MyServer()
{
    QHttpServer *server = new QHttpServer(this);
    connect(server, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),this, SLOT(handleRequest(QHttpRequest*, QHttpResponse*)));
    if(!server->listen(QHostAddress::Any, 8080))
    {
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server listenning...";
    }
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
        Controller toto;
        toto.responder(resp, 200);
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
