//
// Created by robert on 15.09.2021.
//

#include "context.h"

void Context::keyboardEvent(int key, int scancode, int action, int mods){

    if(key == 65) {

        std::cout << "GlobalContext: " << key << std::endl;
    }
}