//
// Created by robert on 15.09.2021.
//
#include "input.h"
#include <iostream>

std::string Input::name() {

    return std::string("Input");
}

void Input::keyboardEvent(int key, int scancode, int action, int mods) {

    globalContext.keyboardEvent(key, scancode, action, mods);
    std::cout << "Keyboard: " << key << " " << action << std::endl;
}

void Input::characterEvent(unsigned int codepoint) {

    std::cout << "Character: " << codepoint << std::endl;
}

void Input::mouseEvent(int button, int action, int mods) {

    std::cout << "Mouse: " << button << " " << action << std::endl;
}

void Input::cursorEvent(double xpos, double ypos) {

}

