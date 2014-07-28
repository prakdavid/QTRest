#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <QDebug>

#include "controller.h"

class UserController : public Controller
{
public:
    UserController();
    void getUser();
    void toString();
};

#endif // USERCONTROLLER_H
