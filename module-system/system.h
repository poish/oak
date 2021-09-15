//
// Created by robert on 15.09.2021.
//

#ifndef OAK_SYSTEM_H
#define OAK_SYSTEM_H

#include <string>
#include <map>
#include <memory>
#include "module.h"
#include <iostream>
class System {

public:

    std::map<std::string, std::shared_ptr<Module>> modules;

    void addModule(std::shared_ptr<Module> module);
    std::shared_ptr<Module> getModule(std::string name);

    void initModules();
};
#endif //OAK_SYSTEM_H
