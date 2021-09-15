//
// Created by robert on 15.09.2021.
//

#include "module.h"

Module::Module(System *ownerInstance) {

    owner = ownerInstance;
}

std::string Module::name() {

    return std::string("Abstract Module");
}