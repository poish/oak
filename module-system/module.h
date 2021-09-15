//
// Created by robert on 15.09.2021.
//

#ifndef OAK_MODULE_H
#define OAK_MODULE_H

#include <string>
#include <memory>

class System;

class Module {

public:

    Module(System* ownerInstance);
    virtual ~Module(){}

    virtual std::string name();

    System* owner;

    virtual void init() {}
};
#endif //OAK_MODULE_H
