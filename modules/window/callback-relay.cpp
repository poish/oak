//
// Created by robert on 15.09.2021.
//
#include "callback-relay.h"

#include "../../oak.h"
#include <iostream>
Oak* CallbackRelay::target = nullptr;

void CallbackRelay::setTarget(Oak* tgt){

    auto window = tgt->getWindow();

    if(window->windowCreated()){
        target = tgt;
        std::cout << "bound" << std::endl;
    }
    else{
        std::cout << "failed to bind" << std::endl;
    }
}
Oak* CallbackRelay::getTarget(GLFWwindow* context){

    return target;
}
void CallbackRelay::pushKeyboardEvent(GLFWwindow* window, int key, int scancode, int action, int mods){

    Oak* target = getTarget(window);
    target->keyboardEvent(key, scancode, action, mods);
}

void CallbackRelay::pushCharacterEvent(GLFWwindow *window, unsigned int codepoint) {

    Oak* target = getTarget(window);
    target->characterEvent(codepoint);
}

void CallbackRelay::pushMouseEvent(GLFWwindow *window, int button, int action, int mods) {

    Oak* target = getTarget(window);
    target->mouseEvent(button, action, mods);

}

void CallbackRelay::pushCursorEvent(GLFWwindow *window, double xpos, double ypos) {

    Oak* target = getTarget(window);
    target->cursorEvent(xpos, ypos);
}

void CallbackRelay::pushFramebufferResize(GLFWwindow *window, int width, int height) {

    Oak* target = getTarget(window);
    target->framebufferResize(width, height);
}
