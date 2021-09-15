//
// Created by robert on 15.09.2021.
//

#ifndef OAK_CONTEXT_H
#define OAK_CONTEXT_H
#include <iostream>

class Input;
class System;

class Context {

public:

    System* application;
    Input* supervisor;

    Context(){

        application = nullptr;
        supervisor = nullptr;
    }

    Context(System* app, Input* supervis){

        application = application;
        supervisor = supervis;
    }

    void keyboardEvent(int key, int scancode, int action, int mods);
    void characterEvent(unsigned codepoint){}
    void mouseEvent(int button, int action, int mods){}
    void cursorEvent(double xpos, double ypos){}
};
#endif //OAK_CONTEXT_H
