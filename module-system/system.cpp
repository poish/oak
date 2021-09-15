//
// Created by robert on 15.09.2021.
//

#include "system.h"

void System::addModule(std::shared_ptr<Module> module){

    std::pair<std::string, std::shared_ptr<Module>> item(module->name(), module);

    modules.insert(item);
}

std::shared_ptr<Module> System::getModule(std::string name){

    auto it = modules.find(name);
    return it->second;
}

void System::initModules(){

    for(auto it = modules.begin(); it != modules.end(); it++){

        it->second->init();
    }
}