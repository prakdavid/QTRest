#ifndef FACTORY_H
#define FACTORY_H

#include "controller.h"
#include <iostream>
#include <map>

class Factory
{
private:
    Factory(){};
    ~Factory(){};
    static Factory *instance;
    std::map<std::string, Controller*> map_controllers;

public:
    static Factory *getInstance() {
        if (instance == NULL) {
            instance = new Factory();
        }
        return instance;
    }

    static void destroyInstance() {
        if (instance != NULL) {
            delete instance;
            instance = NULL;
        }
    }

    template<typename K>
    void registerObject(const std::string description)
    {
        this->map_controllers[description] = new K();
    }

    Controller* getObject(const std::string description)
    {
        return this->map_controllers[description];
    }
};



#endif // FACTORY_H
