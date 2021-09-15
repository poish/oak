//
// Created by robert on 15.09.2021.
//

#ifndef OAK_INPUT_H
#define OAK_INPUT_H

#include "../../module-system/module.h"
#include "context/context.h"

#include <iostream>

class System;

class Input : public Module {

public:

    Context globalContext;

    Input(System* application) : Module(application) {

        globalContext = Context(application, this);
    }

    ~Input() {}

    void init() override { std::cout << "Input initialized" << std::endl; };

    std::string name() override;

    std::string use(){
        std::cout << "Global context is now used" << std::endl;
    }

    /* Functions below ar toe triggered by Oak instance that owns an instance of Input module */

    void keyboardEvent(int key, int scancode, int action, int mods);
    void characterEvent(unsigned codepoint);
    void mouseEvent(int button, int action, int mods);
    void cursorEvent(double xpos, double ypos);
};
#endif //OAK_INPUT_H
